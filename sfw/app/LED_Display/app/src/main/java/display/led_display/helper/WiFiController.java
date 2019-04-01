package display.led_display.helper;

import android.app.AlertDialog;
import android.content.Context;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Handler;
import android.util.Log;

import java.util.ArrayList;

import display.led_display.MenuActivity;

public class WiFiController {

    public void sendOverWiFi(Context context, String deviceName, String messageType, String data) {
        TinyDB tinyDB = new TinyDB(context.getApplicationContext());
        ArrayList<String> deviceData = tinyDB.getListString(deviceName + "Data");
        String ipAddress = deviceData.get(0);
        String portNumber = deviceData.get(1);
        Log.d("ipAddress", ipAddress);
        Log.d("portNumber", portNumber);
        Log.d("data length", "" + data.length());
        if (messageType == "Test") {
            sendTCP(context, ipAddress, portNumber, data);
        } else if (messageType == "Control") {
            sendTCP(context, ipAddress, portNumber, data);
        } else if (messageType == "ATCommand") {
            sendTCP(context, ipAddress, portNumber, data);
        } else if (messageType == "ImageData") {
            sendTCP(context, ipAddress, portNumber, data);
        }
    }

    public String sendTCP(Context context, String ipAddress, String portNumber, String data)
    {
        Handler handler = new Handler();
        new SendTCPAsyncTask(handler, ipAddress, portNumber, data, context).execute();

        return "";
    }

    public class SendTCPAsyncTask extends AsyncTask<String, String, TCPClient> {
        private String data;
        private TCPClient tcpClient;
        private Handler mHandler;
        private Context context;
        private String ipAddress;
        private int portNumber;
        private AlertDialog alertDialog;
        private static final String TAG = "SendAsyncTask";

        /**
         * ShutdownAsyncTask constructor with handler passed as argument. The UI is updated via handler.
         * In doInBackground(...) method, the handler is passed to TCPClient object.
         *
         * @param mHandler Handler object that is retrieved from MainActivity class and passed to TCPClient
         *                 class for sending messages and updating UI.
         */
        public SendTCPAsyncTask(Handler mHandler, String ipAddress, String portNumber, String data, Context context) {
            this.mHandler = mHandler;
            this.context = context;
            this.ipAddress = ipAddress;
            this.portNumber = Integer.parseInt(portNumber);
            this.data = data;
            alertDialog = new AlertDialog.Builder(this.context)
                    .setTitle("TCP Response Message:")
                    .setCancelable(true)
                    .create();
        }

        /**
         * Overriden method from AsyncTask class. There the TCPClient object is created.
         *
         * @param params From MainActivity class empty string is passed.
         * @return TCPClient object for closing it in onPostExecute method.
         */
        @Override
        protected TCPClient doInBackground(String... params) {
            Log.d(TAG, "In do in background");
            try {
                tcpClient = new TCPClient(mHandler,
                        data,
                        this.ipAddress,
                        this.portNumber,
                        new TCPClient.MessageCallback() {
                            @Override
                            public void callbackMessageReceiver(String message) {
                                publishProgress(message);
                            }
                        });

            } catch (NullPointerException e) {
                Log.d(TAG, "Caught null pointer exception");
                e.printStackTrace();
            }
            tcpClient.run();
            return null;
        }

        @Override
        protected void onPostExecute(TCPClient result){
            super.onPostExecute(result);
            Log.d(TAG, "In on post execute");
            if(result != null){
                result.stopClient();
            }
            mHandler.sendEmptyMessageDelayed(MenuActivity.SENT, 4000);

            alertDialog.setMessage("");
            if (!alertDialog.isShowing()) {
                alertDialog.show(); // show dialog
            }

        }

        // Name: onPreExecute
        // Description: This function is executed before the HTTP request is sent to ip address.
        // The function will set the dialog's message and display the dialog.
        @Override
        protected void onPreExecute() {
            Log.d(TAG, "In on pre execute");
            alertDialog.setMessage("Sending, please wait...");
            if (!alertDialog.isShowing()) {
                alertDialog.show();
            }
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
