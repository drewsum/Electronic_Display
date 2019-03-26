package display.led_display.helper;

import android.app.AlertDialog;
import android.content.Context;
import android.os.AsyncTask;
import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.List;

import javax.net.ssl.HttpsURLConnection;

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
            new HttpRequestAsyncTask(context, data.toString(), ipAddress, portNumber, messageType).execute();
        } else if (messageType == "Control") {
            new HttpRequestAsyncTask(context, data.toString(), ipAddress, portNumber, messageType).execute();
        } else if (messageType == "ATCommand") {
            new HttpRequestAsyncTask(context, data.toString(), ipAddress, portNumber, messageType).execute();
        } else if (messageType == "ImageData") {
            new HttpRequestAsyncTask(context, data.toString(), ipAddress, portNumber, messageType).execute();
        }
    }
    // I create my own local NameValuePair class as a substitute for the
    // one that used to come with org.apache.http.NameValuePair;
    // I use it to create lists for http connections;
    public static class NameValuePair {
        private final String name;
        private final String value;
        public NameValuePair(final String name, final String value) {
            this.name = name;
            this.value = value;
        }
        String getName() {
            return name;
        }
        String getValue() {
            return value;
        }
    }

    // Description: Send an HTTP Get request to a specified ip address and port.
    // Also send a parameter "parameterName" with the value of "parameterValue".
    // @param parameterValue the pin number to toggle
    // @param ipAddress the ip address to send the request to
    // @param portNumber the port number of the ip address
    // @param parameterName
    // @return The ip address' reply text, or an ERROR message is it fails to receive one
    public String sendRequest(String parameterValue, String ipAddress, String portNumber, String parameterName)
            throws Exception {

        String serverResponse = "";
        // method 1:
        // define the URL e.g. http://myIpaddress:myport/?pin=13 (to toggle pin 13 for example)
        // if we had just a parameter at a time to send, we could use the form commented below;
        // for more parameters, we can use the list with several parameters;
        String requestURL = "http://"+ipAddress+":"+portNumber+"/?"+parameterName+"="+parameterValue;
        // method 2: include here as many parameters to params as needed;
        // right now, this is just a place-holder;
        //String requestURL = "http://"+ipAddress;
        List<NameValuePair> params = new ArrayList<NameValuePair>();
        //params.add(new NameValuePair(parameterName, parameterValue));
        //params.add(new BasicNameValuePair("secondParam", paramValue2));
        //params.add(new BasicNameValuePair("thirdParam", paramValue3));

        try {
            // create the URL object, and set the connection so that we can write to it;
            URL url = new URL(requestURL);
            Log.d("url", url.toString());
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
            Log.d("conn", conn.toString());
            conn.setReadTimeout(15000);
            conn.setConnectTimeout(15000);
            conn.setRequestMethod("POST");
            conn.setDoInput(true);
            conn.setDoOutput(true);

            // create an output stream on the connection and open an OutputStreamWriter on it;
            // if the URL does not support output, getOutputStream method throws an UnknownServiceException;
            // if the URL does support output, then this method returns an output stream that is connected
            // to the input stream of the URL on the server side ? the client's output is the server's input;
            OutputStream os = conn.getOutputStream();
            BufferedWriter writer = new BufferedWriter( new OutputStreamWriter(os, "UTF-8") );
            // write the required information to the output stream and closes the stream;
            // this writes to the output stream using the write method;
            writer.write( getPostDataString(params) );
            writer.flush();
            writer.close();
            os.close();

            // now we need to read the string the server has sent back;
            int responseCode=conn.getResponseCode();
            if (responseCode == HttpsURLConnection.HTTP_OK) {
                String line;
                BufferedReader br=new BufferedReader(new InputStreamReader(conn.getInputStream()));
                while ((line=br.readLine()) != null) {
                    serverResponse+=line;
                }
            }
            else {
                serverResponse="ERROR";
            }
        } catch (Exception e) {
            serverResponse = e.getMessage();
            e.printStackTrace();
        }

        // return the server's reply/response text
        return serverResponse;
    }

    // used inside sendRequest() above;
    private String getPostDataString(List<NameValuePair> params) throws UnsupportedEncodingException {
        StringBuilder result = new StringBuilder();
        boolean first = true;
        for (NameValuePair pair : params) {
            if (first)
                first = false;
            else
                result.append("&");

            result.append(URLEncoder.encode(pair.getName(), "UTF-8"));
            result.append("=");
            result.append(URLEncoder.encode(pair.getValue(), "UTF-8"));
        }
        return result.toString();
    }

    // An AsyncTask is needed to execute HTTP requests in the background so that they do not
    // block the user interface.
    private class HttpRequestAsyncTask extends AsyncTask<Void, Void, Void> {

        // declare variables needed
        private String requestReply,ipAddress, portNumber;
        private Context context;
        private AlertDialog alertDialog;
        private String parameter;
        private String parameterValue;

        // Description: The asyncTask class constructor. Assigns the values used in its other methods.
        // @param context the application context, needed to create the dialog
        // @param parameterValue the pin number to toggle
        // @param ipAddress the ip address to send the request to
        // @param portNumber the port number of the ip address
        public HttpRequestAsyncTask(Context context, String parameterValue,
                                    String ipAddress, String portNumber, String parameter) {
            this.context = context;

            alertDialog = new AlertDialog.Builder(this.context)
                    .setTitle("HTTP Response From IP Address:")
                    .setCancelable(true)
                    .create();

            this.ipAddress = ipAddress;
            this.parameterValue = parameterValue;
            this.portNumber = portNumber;
            this.parameter = parameter;
        }

        // Name: doInBackground
        // Description: Sends the request to the ip address
        // @param voids
        // @return
        @Override
        protected Void doInBackground(Void... voids) {
            alertDialog.setMessage("Data sent, waiting for receipt confirmation from device...");
            if (!alertDialog.isShowing()) {
                alertDialog.show();
            }

            try {
                requestReply = sendRequest(parameterValue, ipAddress,portNumber, parameter);
            } catch (Exception e) {
                e.printStackTrace();
            }
            return null;
        }

        // Name: onPostExecute
        // Description: This function is executed after the HTTP request returns from the ip address.
        // The function sets the dialog's message with the reply text from the server and display the dialog
        // if it's not displayed already (in case it was closed by accident);
        // @param aVoid void parameter
        @Override
        protected void onPostExecute(Void aVoid) {
            alertDialog.setMessage(requestReply);
            if (!alertDialog.isShowing()) {
                alertDialog.show(); // show dialog
            }
        }

        // Name: onPreExecute
        // Description: This function is executed before the HTTP request is sent to ip address.
        // The function will set the dialog's message and display the dialog.
        @Override
        protected void onPreExecute() {
            alertDialog.setMessage("Sending, please wait...");
            if (!alertDialog.isShowing()) {
                alertDialog.show();
            }
        }

    }
}
