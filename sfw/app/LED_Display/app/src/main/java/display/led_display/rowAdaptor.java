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

import display.led_display.helper.DataManager;

class rowAdaptor extends BaseAdapter {

    private final Context context;
    private final String keyName;
    private ArrayList<String> data;
    private static LayoutInflater inflater = null;

    public rowAdaptor(Context context, ArrayList<String> data, String keyName) {
        // TODO Auto-generated constructor stub
        this.context = context;
        this.data = data;
        this.keyName = keyName;
        inflater = (LayoutInflater) context.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
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

    private Bitmap loadImageFromStorage(String fileName)
    {
        Bitmap b = null;
        try {
            ContextWrapper cw = new ContextWrapper(context.getApplicationContext());
            File directory = cw.getDir(context.getResources().getString(R.string.image_directory), Context.MODE_PRIVATE);
            File f=new File(directory, fileName);
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
            if (keyName.equals("frameList")) {
                vi = inflater.inflate(R.layout.image_row, parent, false);
            } else { // projectList and deviceList
                vi = inflater.inflate(R.layout.row, parent, false);
            }
        }
        final View finView = vi;
        TextView text = vi.findViewById(R.id.text);
        text.setText(data.get(position)); // populate rows
        Button buttonDelete = vi.findViewById(R.id.buttonDelete);
        buttonDelete.setFocusable(false); // needed to allow row to still be clickable
        if (keyName.equals("frameList")) {
            ImageView thumbnail = vi.findViewById(R.id.imageThumb);
            thumbnail.setImageBitmap(loadImageFromStorage(data.get(position)));
            text.setText(context.getString(R.string.frame_num, (position + 1))); // populate rows
            // use up and down arrows to adjust ordering
            ImageButton buttonUp = vi.findViewById(R.id.buttonUp);
            buttonUp.setFocusable(false); // needed to allow row to still be clickable
            ImageButton buttonDown = vi.findViewById(R.id.buttonDown);
            buttonDown.setFocusable(false); // needed to allow row to still be clickable
            final DataManager dataManager = new DataManager(vi.getContext().getApplicationContext());
            //data.get(position);
            String filename = data.get(position);
            final String projectName = filename.substring(0, filename.indexOf("frame"));
            final ArrayList<String> framesList = dataManager.getListString(projectName + "frameList");
            final ArrayList<String> dataList = dataManager.getListString(projectName + "dataList");
            final String namingNumber = dataList.get(0);
            buttonUp.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Log.d("clickEvent", "up button clicked");
                    Log.d("original list location", "" + position);
                    // decrement the position of image only if its not the 0th image
                    if (position != 0) {
                        Collections.swap(framesList, position, position - 1);
                    }
                    // save off the ordering
                    dataList.set(0, namingNumber);
                    dataManager.putListString(projectName + "frameList", framesList);
                    Log.d("new ordered frameList", framesList.toString());
                    data = framesList;
                    notifyDataSetChanged();
                }
            });
            buttonDown.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    Log.d("clickEvent", "down button clicked");
                    // increment the position of image only if its not the last image
                    if(position != framesList.size() - 1) {
                        Collections.swap(framesList, position, position + 1);
                    }
                    // save off the ordering
                    dataList.set(0, namingNumber);
                    dataManager.putListString(projectName + "frameList", framesList);
                    Log.d("new ordered frameList", framesList.toString());
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
                DataManager dataManager = new DataManager(finView.getContext().getApplicationContext());
                Log.d("deleting item from", keyName);
                switch (keyName) {
                    case "frameList": {
                        // delete frame from current framelist
                        String filename = data.get(position);
                        String projectName = filename.substring(0, filename.indexOf("frame"));
                        ArrayList<String> framesList = dataManager.getListString(projectName + "frameList");
                        data.remove(position);
                        framesList.remove(position);
                        dataManager.putListString(projectName + keyName, framesList);
                        Log.d("New " + projectName + keyName, data.toString());
                        TextView textFrameCount = finView.getRootView().findViewById(R.id.textFrameCount);
                        textFrameCount.setText(context.getString(R.string.frame_count_num, data.size()));
                        // also need delete image from internal storage
                        ContextWrapper cw = new ContextWrapper(context.getApplicationContext());
                        File directory = cw.getDir(context.getResources().getString(R.string.image_directory), Context.MODE_PRIVATE);
                        File f = new File(directory, filename);
                        f.delete();
                        break;
                    }
                    case "projectList": {
                        Log.d("projectList", data.toString());
                        String projectName = data.get(position);
                        data.remove(position);
                        dataManager.putListString(keyName, data);
                        dataManager.remove(projectName + "frameList");
                        dataManager.remove(projectName + "dataList");
                        Log.d("deleted", projectName + "frameList");
                        Log.d(keyName, data.toString());
                        break;
                    }
                    case "deviceList":
                        String deviceName = data.get(position);
                        data.remove(position);
                        dataManager.putListString(keyName, data);
                        // delete the device data
                        dataManager.remove(deviceName + "Data");
                        Log.d("deleted", deviceName + "Data");
                        break;
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

