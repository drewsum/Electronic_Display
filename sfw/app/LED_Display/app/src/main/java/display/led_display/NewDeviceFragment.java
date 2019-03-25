package display.led_display;

import android.content.Context;
import android.net.Uri;
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

import display.led_display.helper.TinyDB;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link NewDeviceFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link NewDeviceFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class NewDeviceFragment extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private OnFragmentInteractionListener mListener;

    public NewDeviceFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment NewDeviceFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static NewDeviceFragment newInstance(String param1, String param2) {
        NewDeviceFragment fragment = new NewDeviceFragment();
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
        final View rootView = inflater.inflate(R.layout.fragment_new_device, container, false);

        Button buttonCreateDevice = (Button) rootView.findViewById(R.id.buttonCreateDevice);
        buttonCreateDevice.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                EditText inputDeviceName = (EditText) rootView.findViewById(R.id.inputDeviceName);
                String newDeviceName = inputDeviceName.getText().toString();
                EditText inputIpAddress = (EditText) rootView.findViewById(R.id.inputIPAddress);
                String newIPAddress = inputIpAddress.getText().toString();
                EditText inputPortNumber = (EditText) rootView.findViewById(R.id.inputPortNumber);
                String newPortNumber = inputPortNumber.getText().toString();
                TinyDB tinyDB = new TinyDB(getContext());
                ArrayList<String> deviceList = tinyDB.getListString("deviceList");
                deviceList.add(newDeviceName);
                tinyDB.putListString("deviceList", deviceList);
                Log.d("deviceList", deviceList.toString());
                ArrayList<String> deviceData = new ArrayList<String>();
                deviceData.add(0, newIPAddress);
                deviceData.add(1, newPortNumber);
                tinyDB.putListString(newDeviceName + "Data", deviceData);
                // pass args
                UploadProjectFragment uploadFrag = new UploadProjectFragment();
                // switch back to upload fragment
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().replace(R.id.flContent, uploadFrag).commit();
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
