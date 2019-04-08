package display.led_display.helper;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.Context;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Handler;
import android.os.Message;
import android.util.Log;

import java.util.ArrayList;

public class WiFiController {

    private Dialog dialog;
    private static final String TAG = "TCPClient";
    private String ipAddress, incomingMessage;
    private int portNumber;
    private ArrayList<String> messages;
    private TCPClient tcpClient;
    private Context context;

    public WiFiController(Context context, String deviceName) {
        this.context = context;
        TinyDB tinyDB = new TinyDB(context.getApplicationContext());
        ArrayList<String> deviceData = tinyDB.getListString(deviceName + "Data");
        this.ipAddress = deviceData.get(0);;
        this.portNumber = Integer.parseInt(deviceData.get(1));
        this.dialog = new AlertDialog.Builder(this.context)
                .setTitle("TCP Connection:")
                .setCancelable(true)
                .create();
    }

    public void sendOverWiFi(String messageType, ArrayList<String> messages) {
        this.messages = messages;
        Log.d("data length", "" + messages.size());
        if (messageType == "ImageData") {
            new TCPAsyncTask(WiFiController.handler).execute();
            while(!handler.hasMessages(2)) {

            }
            handler.removeMessages(2);
            Log.d("message removed if false", ""+handler.hasMessages(2));
        } else {
            new TCPAsyncTask(WiFiController.handler).execute();
        }
    }

    private static Handler handler = new Handler() {
        @Override
        public void handleMessage (Message msg){
            Log.d("h", "Handling something");
            switch (msg.what) {
                case 0:
                    Log.d("Handler is handling","0");
                    break;
                case 1:
                    Log.d("Handler is handling", "1");
                    break;
            }
        }
    };

    public class TCPAsyncTask extends AsyncTask<Void, Void, TCPClient> {
        private Handler handler;

        public TCPAsyncTask(Handler handler) {
            this.handler = handler;
        }

        @Override
        protected TCPClient doInBackground(Void... params) {
            try {
                tcpClient = new TCPClient(handler, ipAddress, portNumber, messages, new TCPClient.MessageCallback(){
                    @Override
                    public void callbackMessageReceiver(String message) {
                        Log.d("got", "something");
                        publishProgress();
                    }
                });
            } catch (Exception e) {
                e.printStackTrace();
            }
            tcpClient.run();
            //handler.sendEmptyMessage(2);
            return null;
        }

        @Override
        protected void onPreExecute()    {
            super.onPreExecute();
            Log.d("wifi", "On Pre Execute");
            //dialog.show();
        }

        @Override
        protected void onPostExecute(TCPClient result)    {
            super.onPostExecute(result);
            Log.d("wifi", "On Post Execute");
            if(result != null && result.isRunning()){
                result.stopClient();
            }
            //handler.sendEmptyMessage(1);
            //dialog.show();
        }
    }

    public void connectToNetwork(Context context) {
        WifiConfiguration wifiConfig = new WifiConfiguration();
        wifiConfig.SSID = String.format("\"%s\"", "AI-Thinker_5D90B5");

        WifiManager wifiManager = (WifiManager)context.getSystemService(Context.WIFI_SERVICE);
//remember id
        int netId = wifiManager.addNetwork(wifiConfig);
        wifiManager.disconnect();
        wifiManager.enableNetwork(netId, true);
        wifiManager.reconnect();
    }
}
