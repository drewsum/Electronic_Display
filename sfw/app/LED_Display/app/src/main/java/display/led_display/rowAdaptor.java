package display.led_display;

import android.app.AlertDialog;
import android.content.Context;
import android.content.ContextWrapper;
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
    ArrayList<String> data = new ArrayList<>();
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
    public View getView(final int position, final View convertView, ViewGroup parent) {
        // TODO Auto-generated method stub
        View vi = convertView;
        if (vi == null) {
            if (keyName == "frameList") {
                vi = inflater.inflate(R.layout.image_row, parent, false);
            } else {
                vi = inflater.inflate(R.layout.row, parent, false);
            }
        }
        final View finView = vi;
        TextView text = vi.findViewById(R.id.text);
        text.setText(data.get(position)); // populate rows
        Button buttonDelete = vi.findViewById(R.id.buttonDelete);
        buttonDelete.setFocusable(false); // needed to allow row to still be clickable
        if (keyName == "frameList") {
            ImageView thumbnail = vi.findViewById(R.id.imageThumb);
            thumbnail.setImageBitmap(loadImageFromStorage(data.get(position)));
            text.setText("Frame " + (position + 1)); // populate rows
            // use a spinner to select a number (time)
//            Spinner dropdown = vi.findViewById(R.id.spinnerDropDown);
//            String[] items = new String[]{"5", "10", "15", "20", "25", "30", "60", "120"};
//            ArrayAdapter<String> adapter = new ArrayAdapter<String>(vi.getContext(), android.R.layout.simple_spinner_dropdown_item, items);
//            dropdown.setAdapter(adapter);
            // use up and down arrows to adjust ordering
            ImageButton buttonUp = vi.findViewById(R.id.buttonUp);
            buttonUp.setFocusable(false); // needed to allow row to still be clickable
            ImageButton buttonDown = vi.findViewById(R.id.buttonDown);
            buttonDown.setFocusable(false); // needed to allow row to still be clickable
            final TinyDB tinyDB = new TinyDB(vi.getContext());
            //data.get(position);
            String[] splitPath = data.get(position).split("/");
            String dirtyName = splitPath[splitPath.length-1];
            final String projectName = dirtyName.substring(0, dirtyName.indexOf("frame"));
            final ArrayList<String> framesList = tinyDB.getListString(projectName + "frameList");
            final String namingNumber = framesList.get(0);
            Log.d("namingNumber", namingNumber);
            framesList.remove(0);
            buttonUp.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Log.d("clickEvent", "up button clicked");
                    Log.d("original list location", "" + position);
                    // decrement the position of image
                    if (position != 0) {
                        Collections.swap(framesList, position, position - 1);
                    } else {
                        Collections.swap(framesList, position, framesList.size() -1);
                    }
                    // save off the ordering
                    framesList.add(0, namingNumber);
                    tinyDB.putListString(projectName + "frameList", framesList);
                    Log.d("new ordered frameList", framesList.toString());
                    framesList.remove(0);
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
                    if(position != framesList.size() - 1) {
                        Collections.swap(framesList, position, position + 1);
                    } else {
                        Collections.swap(framesList, position, 0);
                    }
                    // save off the ordering
                    framesList.add(0, namingNumber);
                    tinyDB.putListString(projectName + "frameList", framesList);
                    Log.d("new ordered frameList", framesList.toString());
                    framesList.remove(0);
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
                Log.d("deleting item from", keyName);
                switch (keyName) {
                    case "frameList": {
                        // delete frame from current framelist
                        String path = data.get(position);
                        String[] splitPath = path.split("/");
                        String projectName = splitPath[splitPath.length - 1];
                        projectName = projectName.substring(0, projectName.indexOf("frame"));
                        ArrayList<String> framesList = tinyDB.getListString(projectName + "frameList");
                        data.remove(position);
                        framesList.remove(position + 1);
                        tinyDB.putListString(projectName + keyName, framesList);
                        Log.d("New " + projectName + keyName, data.toString());
                        TextView textFrameCount = finView.getRootView().findViewById(R.id.textFrameCount);
                        textFrameCount.setText(data.size() + "/8");
                        // also need delete image from internal storage
                        ContextWrapper cw = new ContextWrapper(context.getApplicationContext());
                        File directory = cw.getDir("imageDir", Context.MODE_PRIVATE);
                        File f = new File(directory, splitPath[splitPath.length - 1]);
                        f.delete();
                        break;
                    }
                    case "projectList": {
                        Log.d("projectList", data.toString());
                        String projectName = data.get(position);
                        data.remove(position);
                        tinyDB.putListString(keyName, data);
                        tinyDB.remove(projectName + "frameList");
                        Log.d("deleted", projectName + "frameList");
                        Log.d(keyName, data.toString());
                        break;
                    }
                    case "deviceList":
                        String deviceName = data.get(position);
                        data.remove(position);
                        tinyDB.putListString(keyName, data);
                        // delete the device data
                        tinyDB.remove(deviceName + "Data");
                        Log.d("deleted", deviceName + "Data");
                        break;
                }
                Log.d("done", "done");
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

