package display.led_display;

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

import display.led_display.helper.DataManager;

public class SelectionFragment extends Fragment {

    public SelectionFragment() {
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
        Bundle arguments = getArguments();
        String selectionType = arguments.getString("selectionType");
        final String fragmentReturn = arguments.getString("fragmentReturn");
        final View rootView = inflater.inflate(R.layout.fragment_selection, container, false);
        final DataManager dataManager = new DataManager(getContext().getApplicationContext());
        TextView textContentType = rootView.findViewById(R.id.textSelectContent);
        textContentType.setText(getString(R.string.selection_text, selectionType));
        final ListView contentListview = rootView.findViewById(R.id.contentList);
        ArrayList<String> contentList = new ArrayList<>();
        if (selectionType.equals("project")) {
            contentList = dataManager.getListString("projectList");
        } else if (selectionType.equals("device")) {
            contentList = dataManager.getListString("deviceList");
        }
        contentListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), contentList, selectionType + "List"));
        contentListview.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Log.d("clickEvent", "item selected");
                String selectedItem = contentListview.getItemAtPosition(i).toString();
                Bundle arguments = new Bundle();
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                switch (fragmentReturn) {
                    case "edit": {
                        EditProjectFragment editFrag = new EditProjectFragment();
                        arguments.putString("projectName", selectedItem);
                        editFrag.setArguments(arguments);
                        // switch to edit project screen
                        fragmentManager.beginTransaction().addToBackStack(editFrag.getTag()).replace(R.id.flContent, editFrag).commit();
                        break;
                    }
                    case "preview": {
                        ProjectPreviewFragment previewFrag = new ProjectPreviewFragment();
                        arguments.putString("projectName", selectedItem);
                        previewFrag.setArguments(arguments);
                        // switch to project preview screen
                        fragmentManager.beginTransaction().addToBackStack(previewFrag.getTag()).replace(R.id.flContent, previewFrag).commit();
                        break;
                    }
                    case "control": {
                        // device contol
                        DeviceControlFragment controlFrag = new DeviceControlFragment();
                        arguments.putString("deviceName", selectedItem);
                        controlFrag.setArguments(arguments);
                        // switch to device control screen
                        fragmentManager.beginTransaction().addToBackStack(controlFrag.getTag()).replace(R.id.flContent, controlFrag).commit();
                        break;
                    }
                }
            }
        });
        return rootView;
    }

}
