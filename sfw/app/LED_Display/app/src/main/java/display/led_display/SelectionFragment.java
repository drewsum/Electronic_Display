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
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link SelectionFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link SelectionFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class SelectionFragment extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private OnFragmentInteractionListener mListener;

    public SelectionFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment SelectionFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static SelectionFragment newInstance(String param1, String param2) {
        SelectionFragment fragment = new SelectionFragment();
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
        Bundle arguments = getArguments();
        String selectionType = arguments.getString("selectionType");
        final String fragmentReturn = arguments.getString("fragmentReturn");
        final View rootView = inflater.inflate(R.layout.fragment_selection, container, false);
        final TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
        TextView textContentType = rootView.findViewById(R.id.textSelectContent);
        textContentType.setText("Select a " + selectionType);
        final ListView contentListview = rootView.findViewById(R.id.contentList);
        ArrayList<String> contentList = new ArrayList<>();
        if (selectionType == "project") {
            contentList = tinyDB.getListString("projectList");
        } else if (selectionType == "device") {
            contentList = tinyDB.getListString("deviceList");
        }
        contentListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), contentList, selectionType + "List"));
        contentListview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Log.d("clickEvent", "item selected");
                String selectedItem = contentListview.getItemAtPosition(i).toString();
                Bundle arguments = new Bundle();
                if (fragmentReturn == "edit") {
                    EditProjectFragment editFrag = new EditProjectFragment();
                    arguments.putString("projectName", selectedItem);
                    editFrag.setArguments(arguments);
                    // switch to edit project screen
                    FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                    fragmentManager.beginTransaction().replace(R.id.flContent, editFrag).commit();
                } else if (fragmentReturn == "preview") {
                    ProjectPreviewFragment previewFrag = new ProjectPreviewFragment();
                    arguments.putString("projectName", selectedItem);
                    previewFrag.setArguments(arguments);
                    // switch to project preview screen
                    FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                    fragmentManager.beginTransaction().replace(R.id.flContent, previewFrag).commit();
                } else if (fragmentReturn == "upload") {
                    // can select device or project from upload

                } else if (fragmentReturn == "control") {
                    // device contol
                    DeviceControlFragment controlFrag = new DeviceControlFragment();
                    arguments.putString("deviceName", selectedItem);
                    controlFrag.setArguments(arguments);
                    // switch to device control screen
                    FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                    fragmentManager.beginTransaction().replace(R.id.flContent, controlFrag).commit();
                }
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
