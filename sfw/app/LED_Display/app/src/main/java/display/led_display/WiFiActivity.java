package display.led_display;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import display.led_display.helper.WiFiController;

public class WiFiActivity extends AppCompatActivity implements View.OnClickListener {

    public final static String PREF_IP = "PREF_IP_ADDRESS";
    public final static String PREF_PORT = "PREF_PORT_NUMBER";
    // declare buttons and text inputs
    private Button buttonSend0, buttonSend1;
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
        buttonSend0 = (Button)findViewById(R.id.buttonSend0);
        buttonSend0.setPadding(0, 0, 0, 0);
        buttonSend0.setBackgroundResource(R.drawable.mybutton); // mybutton.xml that controls normal, pressed, focused, etc;
        buttonSend1 = (Button)findViewById(R.id.buttonSend1);
        buttonSend1.setPadding(0, 0, 0, 0);
        buttonSend1.setBackgroundResource(R.drawable.mybutton); // mybutton.xml that controls normal, pressed, focused, etc;

        // set button listener (this class);
        buttonSend1.setOnClickListener(this);
        buttonSend0.setOnClickListener(this);

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
        if (view.getId()==buttonSend1.getId()) {
            parameterValue = "1";
        }
        else if (view.getId()==buttonSend0.getId()) {
            parameterValue = "0";
        }


        // execute HTTP request; the only parameter we send is called "effect";
        // which has value 1 if first button is pressed or 2 if second button is pressed;
        if (ipAddress.length()>0 && portNumber.length()>0) {
            WiFiController wifiController = new WiFiController();
            wifiController.sendOverWiFi(getApplicationContext(), "test", "Test", "hi");
        }
    }



}
