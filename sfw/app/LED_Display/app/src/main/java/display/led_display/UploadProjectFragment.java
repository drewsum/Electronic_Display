package display.led_display;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.DataManager;
import display.led_display.helper.WiFiController;

public class UploadProjectFragment extends Fragment {

    private String selectedProject = null;
    private String selectedDevice = null;

    public UploadProjectFragment() {
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
        View rootView = inflater.inflate(R.layout.fragment_upload_project, container, false);
        final DataManager dataManager = new DataManager(getContext().getApplicationContext());
        final ArrayList<String> projectList = dataManager.getListString("projectList");
        Log.d("projectList", projectList.toString());
        final ArrayList<String> deviceList = dataManager.getListString("deviceList");
        Log.d("deviceList", deviceList.toString());
        final ListView projectListview = rootView.findViewById(R.id.projectList);
        projectListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), projectList, "projectList"));
        projectListview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                selectedProject = projectListview.getItemAtPosition(position).toString();
            }
        });
        // populate physical boards list
        final ListView deviceListview = rootView.findViewById(R.id.deviceList);
        deviceListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), deviceList, "deviceList"));
        deviceListview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                selectedDevice = deviceListview.getItemAtPosition(position).toString();
            }
        });
        Button buttonUploadProject = rootView.findViewById(R.id.buttonUpload);
        buttonUploadProject.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // add the code to send start the upload project routine
                WiFiController wiFiController = new WiFiController(getActivity().getBaseContext(), selectedDevice);
                TextView textUpdate = getView().findViewById(R.id.textUpdate);
                ProgressBar pb = getView().findViewById(R.id.progressBar);
                wiFiController.sendOverWiFi(selectedProject, pb, textUpdate);
            }
        });

        return rootView;
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("Upload Project");
    }

}
