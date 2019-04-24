package display.led_display.helper;

import android.app.AlertDialog;
import android.app.Dialog;
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

public class WiFiController {

    private Dialog dialog;
    private static final String TAG = "TCPClient";
    private String ipAddress, incomingMessage;
    private int portNumber;
    private ArrayList<String> messages;
    private TCPClient tcpClient;
    private Context context;
    private ProgressBar pb;
    private TextView textUpdate;
    private String selectedProject;
    private Boolean isProject;
    private int currentIndex;
    private int totalSize;

    private static final int STARTING = 0;
    private static final int SENDING = 1;
    private static final int CONVERTING = 2;

    public WiFiController(View v, Context context, String deviceName) {
        this.context = context;
        DataManager dataManager = new DataManager(context.getApplicationContext());
        ArrayList<String> deviceData = dataManager.getListString(deviceName + "Data");
        this.ipAddress = deviceData.get(0);
        this.portNumber = Integer.parseInt(deviceData.get(1));
        this.dialog = new AlertDialog.Builder(this.context)
                .setTitle("TCP Connection:")
                .setCancelable(true)
                .create();
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

    private Handler handler = new Handler() {
        @Override
        public void handleMessage (Message msg){
            switch (msg.what) {
                case STARTING:
                    Log.d("Handler", "Start Sending image");
                    textUpdate.setText("Sending image " + (msg.arg1 + 1) + " of " + msg.arg2 + "...");
                    break;
                case CONVERTING:
                    Log.d("Handler", "Converting image " + msg.arg1 + " of " + msg.arg2);
                    textUpdate.setText("Converting frame " + msg.arg1 + " of " + msg.arg2 + "...");
                    pb.setProgress(0);
                    if (currentIndex + 1 < totalSize) {
                        currentIndex++;
                    }
                    break;
                case SENDING:
                    Log.d("Handler", "Progress is at "+msg.arg1);
                    pb.setProgress((int)(100*msg.arg1/(double)msg.arg2));
                    if((msg.arg1 == msg.arg2) && ((currentIndex + 1) < totalSize)) {
                        // image is done start the next one
                        new TCPAsyncTask(handler, isProject).execute();
                    }
                    break;
            }
        }
    };

    class TCPAsyncTask extends AsyncTask<Void, Void, TCPClient> {
        private Handler handler;
        private Boolean isProject;
        TCPAsyncTask(Handler handler, Boolean isProject) {
            this.handler = handler;
            this.isProject = isProject;
        }

        @Override
        protected TCPClient doInBackground(Void... params) {
            if(isProject) {
                messages = convertFrame(currentIndex, selectedProject);
                Message msg = new Message();
                msg.what = STARTING;
                msg.arg1 = currentIndex;
                msg.arg2 = totalSize;
                handler.sendMessage(msg);
            }
            try {
                tcpClient = new TCPClient(handler, ipAddress, portNumber, messages);
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
            msg.what = 102;
            msg.arg1 = index + 1;
            msg.arg2 = frameList.size();
            handler.sendMessage(msg);
            if (index == 0) {
                payloadList.add("Power=0");
            }
            // get image from internal storage
            String filename = frameList.get(index);
            ContextWrapper cw = new ContextWrapper(context.getApplicationContext());
            File directory = cw.getDir("imageDir", Context.MODE_PRIVATE);
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
