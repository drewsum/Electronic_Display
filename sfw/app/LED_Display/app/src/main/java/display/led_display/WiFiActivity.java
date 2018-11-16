package display.led_display;

import android.app.AlertDialog;
import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

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

public class WiFiActivity extends AppCompatActivity implements View.OnClickListener {

    public final static String PREF_IP = "PREF_IP_ADDRESS";
    public final static String PREF_PORT = "PREF_PORT_NUMBER";
    // declare buttons and text inputs
    private Button buttonHeartBeat, buttonHeartFade;
    private EditText editTextIPAddress, editTextPortNumber;
    // shared preferences objects used to save the IP address and port so that the user doesn't have to
    // type them next time he/she opens the app.
    SharedPreferences.Editor editor;
    SharedPreferences sharedPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_wifi);

        sharedPreferences = getSharedPreferences("HTTP_HELPER_PREFS",Context.MODE_PRIVATE);
        editor = sharedPreferences.edit();

        // assign text inputs
        editTextIPAddress = (EditText)findViewById(R.id.editTextIPAddress);
        editTextPortNumber = (EditText)findViewById(R.id.editTextPortNumber);

        // assign buttons, which are private member variables of this class;
        buttonHeartBeat = (Button)findViewById(R.id.buttonHeartBeat);
        buttonHeartBeat.setPadding(0, 0, 0, 0);
        buttonHeartBeat.setTextColor(Color.parseColor("#7f3c3c"));
        buttonHeartBeat.setBackgroundResource(R.drawable.mybutton); // mybutton.xml that controls normal, pressed, focused, etc;
        buttonHeartFade = (Button)findViewById(R.id.buttonHeartFade);
        buttonHeartFade.setPadding(0, 0, 0, 0);
        buttonHeartFade.setTextColor(Color.parseColor("#7f3c3c"));
        buttonHeartFade.setBackgroundResource(R.drawable.mybutton); // mybutton.xml that controls normal, pressed, focused, etc;

        // set button listener (this class);
        buttonHeartBeat.setOnClickListener(this);
        buttonHeartFade.setOnClickListener(this);

        // get the IP address and port number from the last time the user used the app,
        // put an empty string "" is this is the first time.
        editTextIPAddress.setText(sharedPreferences.getString(PREF_IP,""));
        editTextPortNumber.setText(sharedPreferences.getString(PREF_PORT,""));
    }


    @Override
    public void onClick(View view) {

        // get the pin number
        String parameterValue = "";
        // get the ip address
        String ipAddress = editTextIPAddress.getText().toString().trim();
        // get the port number
        String portNumber = editTextPortNumber.getText().toString().trim();

        // save the IP address and port for the next time the app is used
        editor.putString(PREF_IP,ipAddress); // set the ip address value to save
        editor.putString(PREF_PORT,portNumber); // set the port number to save
        editor.commit(); // save the IP and PORT

        // get the number from the button that was clicked;
        // if button buttonHeartBeat is pressed, we'll send a "1" to the Arduino, meaning
        // we want to toggle the first heart effect, which is Beat;
        // if button buttonHeartFade is pressed, we'll send a "2" to the Arduino, meaning
        // we want to toggle the second heart effect, which is Fade;
        if (view.getId()==buttonHeartBeat.getId()) {
            parameterValue = "1";
        }
        else if (view.getId()==buttonHeartFade.getId()) {
            parameterValue = "2";
        }


        // execute HTTP request; the only parameter we send is called "effect";
        // which has value 1 if first button is pressed or 2 if second button is pressed;
        if (ipAddress.length()>0 && portNumber.length()>0) {
            new HttpRequestAsyncTask(
                    view.getContext(), parameterValue, ipAddress, portNumber, "effect"
            ).execute();
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
            HttpURLConnection conn = (HttpURLConnection) url.openConnection();
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
            alertDialog.setMessage("Data sent, waiting for reply from server...");
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
            alertDialog.setMessage("Sending data to server, please wait...");
            if (!alertDialog.isShowing()) {
                alertDialog.show();
            }
        }

    }
}
