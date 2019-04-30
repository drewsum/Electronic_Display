package display.led_display.helper;

import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

import display.led_display.R;

public class WiFiController {

    private final String ipAddress;
    private final int portNumber;
    private ArrayList<String> messages = null;
    private TCPClient tcpClient = null;
    private final Context context;
    private ProgressBar pb = null;
    private TextView textUpdate = null;
    private String selectedProject = null;
    private Boolean isProject = null;
    private int currentIndex = 0;
    private int totalSize = 0;

    private static final int STARTING = 0;
    private static final int SENDING = 1;
    private static final int CONVERTING = 2;

    public WiFiController(Context context, String deviceName) {
        this.context = context;
        DataManager dataManager = new DataManager(context.getApplicationContext());
        ArrayList<String> deviceData = dataManager.getListString(deviceName + "Data");
        this.ipAddress = deviceData.get(0);
        this.portNumber = Integer.parseInt(deviceData.get(1));
    }

    // for control messages
    public void sendOverWiFi(ArrayList<String> messages) {
        this.messages = messages;
        this.isProject = false;
        Log.d("data length", "" + messages.size());
        new TCPAsyncTask(handler, isProject).execute();
    }

    // for image uploads
    public void sendOverWiFi(String selectedProject, ProgressBar pb, TextView textUpdate) {
        this.textUpdate = textUpdate;
        this.pb = pb;
        this.selectedProject = selectedProject;
        this.isProject = true;
        DataManager dataManager = new DataManager(context.getApplicationContext());
        ArrayList<String> frameList = dataManager.getListString(selectedProject + "frameList");
        this.totalSize = frameList.size();
        this.currentIndex = 0;
        new TCPAsyncTask(handler, isProject).execute();
    }

    private final Handler handler = new Handler() {
        @Override
        public void handleMessage (Message msg){
            switch (msg.what) {
                case STARTING:
                    Log.d("Handler", "Sending image " + (msg.arg1) + " of " + msg.arg2 + "...");
                    textUpdate.setText(context.getString(R.string.sending_image_text, msg.arg1, msg.arg2));
                    currentIndex++;
                    break;
                case CONVERTING:
                    Log.d("Handler", "Converting image " + msg.arg1 + " of " + msg.arg2);
                    textUpdate.setVisibility(View.VISIBLE);
                    textUpdate.setText(context.getString(R.string.converting_frame_text, msg.arg1, msg.arg2));
                    pb.setProgress(0);
                    if (pb.getVisibility() != View.VISIBLE) {
                        pb.setVisibility(View.VISIBLE);
                    }
                    break;
                case SENDING:
                    Log.d("Handler", "Progress is at "+msg.arg1);
                    pb.setProgress((int)(100*msg.arg1/(double)msg.arg2));
                    if(msg.arg1 == msg.arg2) {
                        if (currentIndex < totalSize) {
                            // image is done start the next one
                            new TCPAsyncTask(handler, isProject).execute();
                        } else {
                            pb.setProgress(0);
                            pb.setVisibility(View.INVISIBLE);
                            textUpdate.setText(context.getString(R.string.upload_complete));
                        }
                    }
                    break;
            }
        }
    };

    class TCPAsyncTask extends AsyncTask<Void, Void, TCPClient> {
        private final Handler handler;
        private final Boolean isProject;
        TCPAsyncTask(Handler handler, Boolean isProject) {
            this.handler = handler;
            this.isProject = isProject;
        }

        @Override
        protected TCPClient doInBackground(Void... params) {
            if(isProject) {
                // sending images
                messages = convertFrame(currentIndex, selectedProject);
                Message msg = new Message();
                msg.what = STARTING;
                msg.arg1 = currentIndex + 1;
                msg.arg2 = totalSize;
                handler.sendMessage(msg);
            }
            try {
                tcpClient = new TCPClient(handler, ipAddress, portNumber, messages, isProject);
            } catch (Exception e) {
                e.printStackTrace();
            }
            tcpClient.run();
            return null;
        }

        @Override
        protected void onPreExecute()    {
            super.onPreExecute();
            Log.d("wifi", "On Pre Execute");
        }

        @Override
        protected void onPostExecute(TCPClient result)    {
            super.onPostExecute(result);
            Log.d("wifi", "On Post Execute");
            if(result != null && result.isRunning()){
                result.stopClient();
            }
        }

        private ArrayList<String> convertFrame(int index, String selectedProject) {
            DataManager dataManager = new DataManager(context.getApplicationContext());
            ArrayList<String> frameList = dataManager.getListString(selectedProject + "frameList");
            ArrayList<String> dataList = dataManager.getListString(selectedProject + "dataList");
            ArrayList<String> payloadList = new ArrayList<>();
            PixelsConverter pixelsConverter = new PixelsConverter();
            int panels_width = 5;
            int panels_height = 4;
            Bitmap bitmap = null;
            payloadList.clear();
            Message msg = new Message();
            msg.what = CONVERTING;
            msg.arg1 = index + 1;
            msg.arg2 = frameList.size();
            handler.sendMessage(msg);
            if (index == 0) {
                payloadList.add("Power=0");
            }
            // get image from internal storage
            String filename = frameList.get(index);
            ContextWrapper cw = new ContextWrapper(context.getApplicationContext());
            File directory = cw.getDir(context.getResources().getString(R.string.image_directory), Context.MODE_PRIVATE);
            File f = new File(directory, filename);
            Log.d("directory", directory.toString());
            Log.d("fileName", filename);
            try {
                InputStream is = new FileInputStream(f);
                bitmap = BitmapFactory.decodeStream(is);
                is.close();
            } catch (IOException io) {
                io.printStackTrace();
            }
            byte[] printMe = pixelsConverter.BitmapToByteArray(bitmap, panels_width, panels_height);
            StringBuilder str = new StringBuilder();
            payloadList.add("Clear_EBI");

            for (int h = 0; h < printMe.length; h++) {
                if (h % 512 == 0) {
                    str.setLength(0);
                    str.append(String.format("ImageData=Addr=0x%06X,Data=", h));
                }
                str.append(String.format("%02X", printMe[h]));
                if (h % 512 == 511) {
                    payloadList.add(str.toString());
                }
            }
            payloadList.add("EBI_2_Flash=" + (index + 1) + " ");
            if (index == frameList.size() - 1) {
                payloadList.add("Project_Data=" + (frameList.size()) + "," + dataList.get(1) + "_");
                payloadList.add("Restart_State_Machine");
            }
            return payloadList;
        }
    }
}
