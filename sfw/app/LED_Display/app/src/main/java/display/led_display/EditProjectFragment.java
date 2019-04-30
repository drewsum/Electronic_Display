package display.led_display;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
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

import display.led_display.helper.DataManager;

public class EditProjectFragment extends Fragment {

    private String projectName = null;
    private ArrayList<String> framesList = null;
    private ArrayList<String> dataList = null;
    private int namingNumber = 0;
    private rowAdaptor adaptor = null;

    public EditProjectFragment() {
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
        View rootView = inflater.inflate(R.layout.fragment_edit_project, container, false);
        // Set Project Name being edited
        Bundle arguments = getArguments();
        projectName = arguments.getString("projectName");
        // get the frames for that project
        final DataManager dataManager = new DataManager(getContext().getApplicationContext());
        framesList = dataManager.getListString(projectName + "frameList");
        dataList = dataManager.getListString(projectName + "dataList");
        Log.d("FrameList fetched", framesList.toString());
        Log.d("dataList fetched", dataList.toString());
        namingNumber = Integer.parseInt(dataList.get(0));
        // framesList.add("filepath in internal storage");
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
        textProjectName.setText(getString(R.string.editing_project_text, projectName));

        TextView textFrameCount = rootView.findViewById(R.id.textFrameCount);
        textFrameCount.setText(getString(R.string.frame_count_outof_text, adaptor.getCount()));

        final Spinner dropdown = rootView.findViewById(R.id.spinnerDropdown);
        final ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(rootView.getContext(), R.array.time_values, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        dropdown.setAdapter(adapter);
        dropdown.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String value = (String)adapter.getItem(position);
                dataList.set(1, value);
                dataManager.putListString(projectName + "dataList", dataList);
                Log.d("dataList", dataList.toString());
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        });

        // set the initial value to the current value for the project
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
        if (data != null) {
            //Uri targetUri = Uri.parse(data.getExtras().getString("targetUri"));
            String fileName = data.getExtras().getString("fileName");
            Log.d("fileName", fileName);

            DataManager dataManager = new DataManager(getContext().getApplicationContext());
            framesList = dataManager.getListString(projectName + "frameList");
            framesList.add(fileName);
            dataList.set(0, "" + namingNumber);
            dataManager.putListString(projectName + "frameList", framesList);
            dataManager.putListString(projectName + "dataList", dataList);
            Log.d("frameList", framesList.toString());
            ListView listView = this.getView().findViewById(R.id.framesList);
            adaptor = new rowAdaptor(this.getActivity().getBaseContext(), framesList, "frameList");
            listView.setAdapter(adaptor);
            TextView textFrameCount = this.getView().findViewById(R.id.textFrameCount);
            textFrameCount.setText(getString(R.string.frame_count_outof_text, adaptor.getCount()));
        } else {
            Log.d("no image", "no image came back");
        }
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("Edit Project");
    }

}
