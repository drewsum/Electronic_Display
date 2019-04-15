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
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Spinner;
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
    private ArrayList<String> dataList;
    private int namingNumber;
    private rowAdaptor adaptor;

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
        getActivity().setTitle("Edit Project");
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View rootView = inflater.inflate(R.layout.fragment_edit_project, container, false);
        // Set Project Name being edited
        Bundle arguments = getArguments();
        projectName = arguments.getString("projectName");
        // get the frames for that project
        final TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
        framesList = tinyDB.getListString(projectName + "frameList");
        dataList = tinyDB.getListString(projectName + "dataList");
        Log.d("FrameList fetched", framesList.toString());
        Log.d("dataList fetched", dataList.toString());
        namingNumber = Integer.parseInt(dataList.get(0));
        // framesList.add("filepath in internal storage");
        frameCount = framesList.size();
        ListView listview = rootView.findViewById(R.id.framesList);
        adaptor = new rowAdaptor(this.getActivity().getBaseContext(), framesList, "frameList");
        listview.setAdapter(adaptor);
        Button buttonAddFrame = rootView.findViewById(R.id.buttonAddFrame);
        buttonAddFrame.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // need to give index and project name for imagePath naming convention
                if (adaptor.getCount() < 8) {
                    Log.d("row count", "" + adaptor.getCount());
                    Log.d("frameCount", "" + frameCount);
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
        TextView textProjectName = rootView.findViewById(R.id.textProjectName);
        textProjectName.setText("Editing Project: " + projectName);

        TextView textFrameCount = rootView.findViewById(R.id.textFrameCount);
        textFrameCount.setText(frameCount + "/8");

        final Spinner dropdown = rootView.findViewById(R.id.spinnerDropdown);
        final ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(rootView.getContext(), R.array.time_values, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        dropdown.setAdapter(adapter);
        dropdown.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String value = (String)adapter.getItem(position);
                dataList.set(1, value);
                tinyDB.putListString(projectName + "dataList", dataList);
                Log.d("dataList", dataList.toString());
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        // set the intial value to the current value for the project
        String[] a = getResources().getStringArray(R.array.time_values);
        for (int item = 0; item < a.length; item++) {
            if(a[item].equals(dataList.get(1))) {
                dropdown.setSelection(item);
            }

        }

        return rootView;
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        if (requestCode == 1) {
            //Uri targetUri = Uri.parse(data.getExtras().getString("targetUri"));
            String fileName = data.getExtras().getString("fileName");
            Log.d("fileName", fileName);

            TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
            framesList = tinyDB.getListString(projectName + "frameList");
            framesList.add(fileName);
            dataList.set(0, "" + namingNumber);
            tinyDB.putListString(projectName + "frameList", framesList);
            tinyDB.putListString(projectName + "dataList", dataList);
            Log.d("frameList", framesList.toString());
            frameCount = framesList.size();
            /*if (frameCount > 7) {
                Button buttonAddFrame = (Button) getView().findViewById(R.id.buttonAddFrame);
                buttonAddFrame.setClickable(false);
            }*/
            TextView textFrameCount = this.getView().findViewById(R.id.textFrameCount);
            textFrameCount.setText(frameCount + "/8");
            ListView listView = this.getView().findViewById(R.id.framesList);
            adaptor = new rowAdaptor(this.getActivity().getBaseContext(), framesList, "frameList");
            listView.setAdapter(adaptor);
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
