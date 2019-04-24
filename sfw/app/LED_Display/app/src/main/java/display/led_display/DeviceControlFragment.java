package display.led_display;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.DataManager;
import display.led_display.helper.WiFiController;

public class DeviceControlFragment extends Fragment {

    private ArrayList<String> deviceList;
    private int brightnessLevel = 0;
    private boolean powerToggle = false;

    public DeviceControlFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        final View rootView = inflater.inflate(R.layout.fragment_device_control, container, false);
        Bundle arguments = getArguments();
        final String deviceName = arguments.getString("deviceName");
        TextView textDeviceName = rootView.findViewById(R.id.textDeviceName);
        textDeviceName.setText("Controlling Device: " + deviceName);
        DataManager dataManager = new DataManager(getContext().getApplicationContext());
        final WiFiController wiFiController = new WiFiController(getView(), getContext(), deviceName);
        //deviceList = dataManager.getListString(projectName + "frameList");
        // set up Ping button
        Button buttonPing = rootView.findViewById(R.id.buttonPing);
        buttonPing.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // Ping the Micro
                ArrayList<String> messageList = new ArrayList<>();
                messageList.add("ping");
                wiFiController.sendOverWiFi(messageList);
                Log.d("WiFi", "Pinged Device");
            }
        });
        // set up Power buttons
        Button buttonPowerOn = rootView.findViewById(R.id.buttonPowerOn);
        buttonPowerOn.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // send WiFi command to Turn Multiplexing ON
                ArrayList<String> messageList = new ArrayList<>();
                messageList.add("Restart_State_Machine");
                wiFiController.sendOverWiFi(messageList);
            }
        });
        Button buttonPowerOff = rootView.findViewById(R.id.buttonPowerOff);
        buttonPowerOff.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // send WiFi command to Turn Multiplexing ON
                ArrayList<String> messageList = new ArrayList<>();
                messageList.add("Power=0");
                wiFiController.sendOverWiFi(messageList);
            }
        });
        // set up Brightness seekbar
        final TextView textBrightness = rootView.findViewById(R.id.textBrightness);
        SeekBar seekbar = rootView.findViewById(R.id.seekBar);
        seekbar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
           @Override
           public void onProgressChanged(SeekBar seekBar, int progress, boolean b) {
               brightnessLevel = progress;
                textBrightness.setText("Brightness: " + progress);
           }
            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

           }
            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {
                ArrayList<String> messageList = new ArrayList<>();
                messageList.add("Dim=" + brightnessLevel + "_");
                wiFiController.sendOverWiFi(messageList);
           }
       });
        Button buttonUploadProj = rootView.findViewById(R.id.buttonUploadProj);
        buttonUploadProj.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                UploadProjectFragment uploadFrag = new UploadProjectFragment();
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(uploadFrag.getTag()).replace(R.id.flContent, uploadFrag).commit();
            }
        });
        return rootView;
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("Device Control");
    }

}
