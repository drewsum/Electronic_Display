package display.led_display.helper;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.net.wifi.ScanResult;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.ProgressBar;

import java.util.ArrayList;
import java.util.List;

import display.led_display.R;

public class WiFiController {

    private Dialog dialog;
    private static final String TAG = "TCPClient";
    private String ipAddress, incomingMessage;
    private int portNumber;
    private ArrayList<String> messages;
    private TCPClient tcpClient;
    private Context context;
    private ProgressBar pb;

    public WiFiController(View v, Context context, String deviceName) {
        this.context = context;
        DataManager dataManager = new DataManager(context.getApplicationContext());
        ArrayList<String> deviceData = dataManager.getListString(deviceName + "Data");
        this.ipAddress = deviceData.get(0);;
        this.portNumber = Integer.parseInt(deviceData.get(1));
        this.dialog = new AlertDialog.Builder(this.context)
                .setTitle("TCP Connection:")
                .setCancelable(true)
                .create();
        if(v!=null)
            this.pb = v.findViewById(R.id.progressBar);
    }

    public void sendOverWiFi(String messageType, ArrayList<String> messages) {
        this.messages = messages;
        Log.d("data length", "" + messages.size());
        if (messageType == "ImageData") {
            new TCPAsyncTask(handler).execute();
            while(!handler.hasMessages(2)) {

            }
            handler.removeMessages(2);
            Log.d("message removed if false", ""+handler.hasMessages(2));
        } else {
            new TCPAsyncTask(handler).execute();
        }
    }

    private Handler handler = new Handler() {
        public int progress;
        @Override
        public void handleMessage (Message msg){
            Log.d("h", "Handling something");
            Bundle data = msg.getData();
            progress = data.getInt("progress");
            Log.d("Handler Received Progress", ""+progress);
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
                tcpClient = new TCPClient(handler, ipAddress, portNumber, messages);
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
    WifiManager wifiManager;
    ArrayList<String> arrayList;
    public void connectToNetwork(Context context) {
        WifiConfiguration wifiConfig = new WifiConfiguration();
        wifiConfig.SSID = String.format("\"%s\"", "AI-THINKER_5D90B5");
        Log.d("SSID", "" + wifiConfig.SSID);
        wifiManager = (WifiManager)context.getSystemService(Context.WIFI_SERVICE);
        // case 1: Network is already connected
        WifiInfo wifiInfo = wifiManager.getConnectionInfo();
        Log.d("network connected to", "" + wifiInfo.getHiddenSSID());
        Log.d("network connected to", "" + wifiInfo.getBSSID());
        Log.d("network connected to", "" + wifiInfo.getSSID());
        if(wifiConfig.SSID.equals(wifiInfo.getSSID())) {
            Log.d("CONNECTED", "Already Connected to AI-THINKER");
        }
        // case 2: Network is saved on device but not connected
        List<WifiConfiguration> savedConfigs = wifiManager.getConfiguredNetworks();
        if(savedConfigs.contains(wifiConfig)) {
            Log.d("SAVED", "wifi configuration found");
        }
        // case 3: Network is not connected or saved on the device.
        scanWifi();
        List<ScanResult> scanResults = wifiManager.getScanResults();
        Log.d("hi", scanResults.toString());
        for(int i = 0; i < scanResults.size(); i++) {
            Log.d("scanned Item" + i, scanResults.get(i).SSID);
        }
        if(scanResults.contains(wifiConfig)) {
            Log.d("SCANNED", "wifi configuration found on scanner");
        }
        int netId = wifiManager.addNetwork(wifiConfig);
        Log.d("netId", "" + netId);
        boolean worked = wifiManager.disconnect();
        Log.d("worked", String.valueOf(worked));
        wifiManager.enableNetwork(netId, true);
        worked = wifiManager.reconnect();
        Log.d("worked", String.valueOf(worked));

    }

    private void scanWifi() {
        context.registerReceiver(wifiReceiver, new IntentFilter(WifiManager.SCAN_RESULTS_AVAILABLE_ACTION));
        wifiManager.startScan();
    }
    private List<ScanResult> results;

    BroadcastReceiver wifiReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            results = wifiManager.getScanResults();
            context.unregisterReceiver(this);

            for (ScanResult scanResult : results) {
                arrayList.add(scanResult.SSID + " - " + scanResult.capabilities);
            }
        };
    };
}
