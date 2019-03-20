package display.led_display;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;

import display.led_display.helper.TinyDB;

public class rowAdaptor extends BaseAdapter {

    Context context;
    String keyName;
    ArrayList<String> data = new ArrayList<String>();
    private static LayoutInflater inflater = null;

    public rowAdaptor(Context context, ArrayList<String> data, String keyName) {
        // TODO Auto-generated constructor stub
        this.context = context;
        this.data = data;
        this.keyName = keyName;
        inflater = (LayoutInflater) context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        // TODO Auto-generated method stub
        return data.size();
    }

    @Override
    public Object getItem(int position) {
        // TODO Auto-generated method stub
        return data.get(position);
    }

    @Override
    public long getItemId(int position) {
        // TODO Auto-generated method stub
        return position;
    }

    private Bitmap loadImageFromStorage(String path)
    {
        Bitmap b = null;
        try {
            File f=new File(path);
            b = BitmapFactory.decodeStream(new FileInputStream(f));
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
        return b;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        // TODO Auto-generated method stub
        View vi = convertView;
        if (vi == null) {
            if (keyName == "frameList") {
                vi = inflater.inflate(R.layout.image_row, null);
            } else {
                vi = inflater.inflate(R.layout.row, null);
            }
        }
        final View finView = vi;
        TextView text = (TextView) vi.findViewById(R.id.text);
        text.setText(data.get(position)); // populate rows
        Button buttonDelete = (Button) vi.findViewById(R.id.buttonDelete);
        buttonDelete.setFocusable(false); // needed to allow row to still be clickable
        if (keyName == "frameList") {
            ImageView thumbnail = (ImageView) vi.findViewById(R.id.imageThumb);
            thumbnail.setImageBitmap(loadImageFromStorage(data.get(position)));
            text.setText("Frame " + (position + 1)); // populate rows
            // use a spinner to select a number (time)
//            Spinner dropdown = vi.findViewById(R.id.spinnerDropDown);
//            String[] items = new String[]{"5", "10", "15", "20", "25", "30", "60", "120"};
//            ArrayAdapter<String> adapter = new ArrayAdapter<String>(vi.getContext(), android.R.layout.simple_spinner_dropdown_item, items);
//            dropdown.setAdapter(adapter);
            // use up and down arrows to adjust ordering
            ImageButton buttonUp = (ImageButton) vi.findViewById(R.id.buttonUp);
            buttonUp.setFocusable(false); // needed to allow row to still be clickable
            ImageButton buttonDown = (ImageButton) vi.findViewById(R.id.buttonDown);
            buttonDown.setFocusable(false); // needed to allow row to still be clickable
            final TinyDB tinyDB = new TinyDB(vi.getContext());
            //data.get(position);
            String[] path = data.get(position).split("/");
            String projectName = path[path.length-1].replace("frame" + position + ".png", "");
            Log.d("projectName", projectName);
            final ArrayList<String> framesList = tinyDB.getListString(projectName + "frameList");
            buttonUp.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Log.d("clickEvent", "up button clicked");
                    Log.d("original list", "" + position);
                    // decrement the position of image
                    Collections.swap(framesList, position, position - 1);
                    tinyDB.putListString("test1" + "frameList", framesList);
                    data = framesList;
                    notifyDataSetChanged();
                    //TextView textFrameCount = (TextView) finView.findViewById(R.id.textFrameCount);
                }
            });
            buttonDown.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Log.d("clickEvent", "down button clicked");
                    // increment the position of image
                    Collections.swap(framesList, position, position + 1);
                    tinyDB.putListString("test1" + "frameList", framesList);
                    data = framesList;
                    notifyDataSetChanged();
                }
            });

        }

        // set up "are you sure you want to delete dialog"
        AlertDialog.Builder builder = new AlertDialog.Builder(finView.getContext());
        builder.setTitle("Confirm deletion of " + keyName.replace("List", ""));
        builder.setMessage("This action is permanent!");
        builder.setPositiveButton("YES", new DialogInterface.OnClickListener() {
            public void onClick(DialogInterface dialog, int which) {
                TinyDB tinyDB = new TinyDB(finView.getContext().getApplicationContext());
                if(keyName == "frameList") {
                    // delete frame from current framelist
                    String[] path = data.get(position).split("/");
                    String projectName = path[path.length-1].replace("frame" + position + ".png", "");
                    Log.d("projectName", projectName);
                    data.remove(position);
                    tinyDB.putListString(projectName + keyName, data);
                    Log.d("New " + projectName + keyName, data.toString());
                    // also need to rename the other frames if they slide around
                } else if(keyName == "projectList") {
                    String projectName = data.get(position);
                    data.remove(position);
                    tinyDB.putListString(keyName, data);
                    tinyDB.remove(projectName + "frameList");
                    Log.d("deleted", projectName + "frameList");
                    Log.d(keyName, data.toString());
                }
                notifyDataSetChanged();
                dialog.dismiss();
            }
        });
        builder.setNegativeButton("NO", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
            }
        });
        final AlertDialog alert = builder.create();

        buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.d("clickEvent", "button clicked");
                alert.show();
            }
        });
        return vi;
    }
}

