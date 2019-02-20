package display.led_display;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ListView;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link UploadProjectFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link UploadProjectFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class UploadProjectFragment extends Fragment implements View.OnClickListener {
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
//        MenuActivity parent = (MenuActivity)this.getActivity().getParent();
//        Project[] projectList = parent.database.projectDao.loadAll();
//        Log.d("projects: ", "" + projectList[0].getProjectName());

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View rootView = inflater.inflate(R.layout.fragment_upload_project, container, false);
        TinyDB tinyDB = new TinyDB(getContext());
        ArrayList<String> projectList = tinyDB.getListString("projectList");
        Log.d("projectList", projectList.toString());
        ArrayList<String> deviceList = tinyDB.getListString("deviceList");
        Log.d("projectList", deviceList.toString());
        ListView projectListview = rootView.findViewById(R.id.projectList);
        projectListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), projectList, "frameList"));
        // populate physical boards list
        ListView boardListview = rootView.findViewById(R.id.deviceList);
        boardListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), deviceList, "deviceList"));
        Button buttonSelectDevice = (Button) rootView.findViewById(R.id.buttonDeviceSelect);
        buttonSelectDevice.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                startActivity(new Intent(getActivity(), WiFiActivity.class));
            }
        });

        Button buttonNewProject = (Button) rootView.findViewById(R.id.buttonNewProject);
        buttonNewProject.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().replace(R.id.flContent, new NewProjectFragment()).commit();
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

    private void moveToNewActivity() {
        Intent i = new Intent(getActivity(), WiFiActivity.class);
        startActivity(i);
        ((Activity) getActivity()).overridePendingTransition(0,0);

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

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.buttonDeviceSelect:
                startActivity(new Intent(getActivity(), WiFiActivity.class));
                break;
        }
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
