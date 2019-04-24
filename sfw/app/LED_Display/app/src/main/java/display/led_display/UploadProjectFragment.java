package display.led_display;

import android.content.Context;
import android.net.Uri;
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


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link UploadProjectFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link UploadProjectFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class UploadProjectFragment extends Fragment {

    private String selectedProject;
    private String selectedDevice;


    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private OnFragmentInteractionListener mListener;

    public UploadProjectFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment UploadProjectFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static UploadProjectFragment newInstance(String param1, String param2) {
        UploadProjectFragment fragment = new UploadProjectFragment();
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
        getActivity().setTitle("Upload Project");
//        MenuActivity parent = (MenuActivity)this.getActivity().getParent();
//        Project[] projectList = parent.database.projectDao.loadAll();
//        Log.d("projects: ", "" + projectList[0].getProjectName());

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
                WiFiController wiFiController = new WiFiController(getView(), getActivity().getBaseContext(), selectedDevice);
                TextView textUpdate = getView().findViewById(R.id.textUpdate);
                ProgressBar pb = getView().findViewById(R.id.progressBar);
                wiFiController.sendOverWiFi(selectedProject, pb, textUpdate);
            }
        });

        return rootView;
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
