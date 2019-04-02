package display.led_display;

import android.content.Context;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;
import display.led_display.helper.WiFiController;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link DeviceControlFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link DeviceControlFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class DeviceControlFragment extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private ArrayList<String> deviceList;
    private int brightnessLevel = 0;

    private OnFragmentInteractionListener mListener;

    public DeviceControlFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment DeviceControlFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static DeviceControlFragment newInstance(String param1, String param2) {
        DeviceControlFragment fragment = new DeviceControlFragment();
        Bundle args = new Bundle();
        args.putString(ARG_PARAM1, param1);
        args.putString(ARG_PARAM2, param2);
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            mParam1 = getArguments().getString(ARG_PARAM1);
            mParam2 = getArguments().getString(ARG_PARAM2);
        }
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
        TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
        final WiFiController wiFiController = new WiFiController();
        //deviceList = tinyDB.getListString(projectName + "frameList");
        // set up Ping button
        Button buttonPing = rootView.findViewById(R.id.buttonPing);
        buttonPing.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // Ping the Micro
                wiFiController.sendOverWiFi(getContext(), deviceName, "Control", "hello world");
                Log.d("WiFi", "Pinged Device");
            }
        });
        // set up Power button
        Button buttonPower = rootView.findViewById(R.id.buttonPower);
        buttonPower.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // send WiFi command to Turn Multiplexing ON
                wiFiController.sendOverWiFi(getContext(), deviceName, "Control", "Power=toggle");
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
                //wiFiController.connectToNetwork(getContext());
                wiFiController.sendOverWiFi(getContext(), deviceName, "Control", "Dim=" + brightnessLevel + " ");
           }
       });
        Button buttonSendCommand = rootView.findViewById(R.id.buttonSendCommand);
        buttonSendCommand.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // send AT command to microcontroller
                EditText editWiFiCommands = rootView.findViewById(R.id.inputWiFiCommands);
                String commands = editWiFiCommands.getText().toString();
                wiFiController.sendOverWiFi(getContext(), deviceName, "ATCommand", commands);
                Log.d("wifi", "message sent");
            }
        });
        return rootView;
    }

    // TODO: Rename method, update argument and hook method into UI event
    public void onButtonPressed(Uri uri) {
        if (mListener != null) {
            mListener.onFragmentInteraction(uri);
        }
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        if (context instanceof OnFragmentInteractionListener) {
            mListener = (OnFragmentInteractionListener) context;
        } else {
            throw new RuntimeException(context.toString()
                    + " must implement OnFragmentInteractionListener");
        }
    }

    @Override
    public void onDetach() {
        super.onDetach();
        mListener = null;
    }

    /**
     * This interface must be implemented by activities that contain this
     * fragment to allow an interaction in this fragment to be communicated
     * to the activity and potentially other fragments contained in that
     * activity.
     * <p>
     * See the Android Training lesson <a href=
     * "http://developer.android.com/training/basics/fragments/communicating.html"
     * >Communicating with Other Fragments</a> for more information.
     */
    public interface OnFragmentInteractionListener {
        // TODO: Update argument type and name
        void onFragmentInteraction(Uri uri);
    }
}
