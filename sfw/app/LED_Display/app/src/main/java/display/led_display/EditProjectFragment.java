package display.led_display;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link EditProjectFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link EditProjectFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class EditProjectFragment extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private int frameCount = 0;
    private String projectName;
    private ArrayList<String> framesList;
    private int namingNumber;

    private OnFragmentInteractionListener mListener;

    public EditProjectFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment NewProject.
     */
    // TODO: Rename and change types and number of parameters
    public static EditProjectFragment newInstance(String param1, String param2) {
        EditProjectFragment fragment = new EditProjectFragment();
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
        View rootView = inflater.inflate(R.layout.fragment_edit_project, container, false);
        // Set Project Name being edited
        Bundle arguments = getArguments();
        // this only works night now if you nav from new project
        projectName = arguments.getString("projectName");
        // get the frames for that project
        TinyDB tinyDB = new TinyDB(getContext());
        framesList = tinyDB.getListString(projectName + "frameList");
        Log.d("FrameList fetched", framesList.toString());
        namingNumber = Integer.parseInt(framesList.get(0));
        framesList.remove(0);
        // framesList.add("filepath in internal storage");
        frameCount = framesList.size();
        ListView listview = rootView.findViewById(R.id.framesList);
        listview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), framesList, "frameList"));

        Button buttonAddFrame = (Button) rootView.findViewById(R.id.buttonAddFrame);
        buttonAddFrame.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // need to give index and project name for imagePath naming convention
                if (frameCount < 8) {
                    namingNumber++;
                    Intent intent = new Intent(getActivity(), ImageSelectActivity.class);
                    intent.putExtra("projectName", projectName);
                    intent.putExtra("namingNumber", namingNumber);
                    startActivityForResult(intent, 1);
                } else {
                    // show a message
                    AlertDialog.Builder builder = new AlertDialog.Builder(getContext());
                    builder.setTitle("Maximum Amount of Frames Reached");
                    builder.setMessage("A single project can only hold up to 8 frames.");
                    builder.setPositiveButton("OK", new DialogInterface.OnClickListener() {
                        public void onClick(DialogInterface dialog, int which) {
                            Log.d("clickEvent", "OK button clicked");
                            dialog.dismiss();
                        }
                    });
                    final AlertDialog alert = builder.create();
                    alert.show();
                }
            }
        });
        TextView textProjectName = (TextView) rootView.findViewById(R.id.textProjectName);
        textProjectName.setText("Editing Project: " + projectName);

        TextView textFrameCount = (TextView) rootView.findViewById(R.id.textFrameCount);
        textFrameCount.setText(frameCount + "/8");
        return rootView;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 1) {
            //Uri targetUri = Uri.parse(data.getExtras().getString("targetUri"));
            String filePath = data.getExtras().getString("filePath");
            Log.d("filePath", filePath);

            TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
            framesList = tinyDB.getListString(projectName + "frameList");
            framesList.add(filePath);
            Log.d("frameList", framesList.toString());
            //framesList.add(0, "" + namingNumber);
            Log.d("frameList", framesList.toString());
            framesList.remove(0);
            framesList.add(0, "" + namingNumber);
            tinyDB.putListString(projectName + "frameList", framesList);
            framesList.remove(0);
            Log.d("frameList", framesList.toString());
            frameCount = framesList.size();
            /*if (frameCount > 7) {
                Button buttonAddFrame = (Button) getView().findViewById(R.id.buttonAddFrame);
                buttonAddFrame.setClickable(false);
            }*/
            TextView textFrameCount = (TextView) this.getView().findViewById(R.id.textFrameCount);
            textFrameCount.setText(frameCount + "/8");
            ListView listView = (ListView) this.getView().findViewById(R.id.framesList);
            //listView.getAdapter().notify();
            listView.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), framesList, "frameList"));
        }
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
