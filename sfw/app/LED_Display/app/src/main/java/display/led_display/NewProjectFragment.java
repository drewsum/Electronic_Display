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

public class NewProjectFragment extends Fragment {

    public NewProjectFragment() {
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
        final View rootView = inflater.inflate(R.layout.fragment_new_project, container, false);

        Button buttonCreateProject = rootView.findViewById(R.id.buttonCreateProject);
        buttonCreateProject.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                EditText inputProjectName = rootView.findViewById(R.id.inputProjectName);
                String newProjectName = inputProjectName.getText().toString();
                DataManager dataManager = new DataManager(getContext().getApplicationContext());
                ArrayList<String> projectList = dataManager.getListString("projectList");
                projectList.add(newProjectName);
                dataManager.putListString("projectList", projectList);
                Log.d("projectList", projectList.toString());
                // create a framesList for project
                ArrayList<String> newFrameList = new ArrayList<>();
                // create a projectData for the project
                ArrayList<String> newDataList = new ArrayList<>();
                newDataList.add(0, "0"); // initial Naming Number
                newDataList.add(1, "10"); // initial frame duration
                dataManager.putListString(newProjectName + "dataList", newDataList);
                dataManager.putListString(newProjectName + "frameList", newFrameList);
                // pass args
                EditProjectFragment editFrag = new EditProjectFragment();
                Bundle arguments = new Bundle();
                arguments.putString( "projectName" , newProjectName);
                editFrag.setArguments(arguments);
                // switch to edit project screen
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(editFrag.getTag()).replace(R.id.flContent, editFrag).commit();
            }
        });
        return rootView;
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("New Project");
    }

}
