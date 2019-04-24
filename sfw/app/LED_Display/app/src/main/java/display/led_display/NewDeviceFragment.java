package display.led_display;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

import java.util.ArrayList;

import display.led_display.helper.DataManager;

public class NewDeviceFragment extends Fragment {

    public NewDeviceFragment() {
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
        final View rootView = inflater.inflate(R.layout.fragment_new_device, container, false);

        Button buttonCreateDevice = rootView.findViewById(R.id.buttonCreateDevice);
        buttonCreateDevice.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                EditText inputDeviceName = rootView.findViewById(R.id.inputDeviceName);
                String newDeviceName = inputDeviceName.getText().toString();
                EditText inputIpAddress = rootView.findViewById(R.id.inputIPAddress);
                String newIPAddress = inputIpAddress.getText().toString();
                EditText inputPortNumber = rootView.findViewById(R.id.inputPortNumber);
                String newPortNumber = inputPortNumber.getText().toString();
                DataManager dataManager = new DataManager(getContext().getApplicationContext());
                ArrayList<String> deviceList = dataManager.getListString("deviceList");
                deviceList.add(newDeviceName);
                dataManager.putListString("deviceList", deviceList);
                Log.d("deviceList", deviceList.toString());
                ArrayList<String> deviceData = new ArrayList<>();
                deviceData.add(0, newIPAddress);
                deviceData.add(1, newPortNumber);
                dataManager.putListString(newDeviceName + "Data", deviceData);
                // pass args
                UploadProjectFragment uploadFrag = new UploadProjectFragment();
                // switch back to upload fragment
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(uploadFrag.getTag()).replace(R.id.flContent, uploadFrag).commit();
            }
        });
        return rootView;
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("New Device");
    }

}
