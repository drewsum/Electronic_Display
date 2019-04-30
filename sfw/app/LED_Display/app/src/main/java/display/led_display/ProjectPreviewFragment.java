package display.led_display;

import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;

import display.led_display.helper.DataManager;

public class ProjectPreviewFragment extends Fragment {

    private ArrayList<String> framesList = null;
    private int currentIndex = 0;

    public ProjectPreviewFragment() {
        // Required empty public constructor
    }

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View rootView = inflater.inflate(R.layout.fragment_project_preview, container, false);
        // Inflate the layout for this fragment
        Bundle arguments = getArguments();
        final String projectName = arguments.getString("projectName");
        Log.d("projectName", projectName);
        TextView textDisplayingProject = rootView.findViewById(R.id.textCurrentFrameCount);
        textDisplayingProject.setText(getString(R.string.preview_project_text, projectName));
        DataManager dataManager = new DataManager(getContext().getApplicationContext());
        framesList = dataManager.getListString(projectName + "frameList");
        Log.d("frameList", framesList.toString());
        // set up edit button
        Button buttonEditProject = rootView.findViewById(R.id.buttonEditProject);
        buttonEditProject.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                // pass args
                EditProjectFragment editFrag = new EditProjectFragment();
                Bundle arguments = new Bundle();
                arguments.putString("projectName", projectName);
                editFrag.setArguments(arguments);
                // switch to edit project screen
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(editFrag.getTag()).replace(R.id.flContent, editFrag).commit();
            }
        });
        // set up nav buttons
        ImageButton buttonLeft = rootView.findViewById(R.id.buttonLeft);
        buttonLeft.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                if (currentIndex > 0) {
                    Log.d("Next Image", "" + currentIndex);
                    currentIndex--;
                    updateImage();
                }
            }
        });
        ImageButton buttonRight = rootView.findViewById(R.id.buttonRight);
        buttonRight.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View arg0) {
                if (currentIndex < (framesList.size() - 1)) {
                    Log.d("Prev Image", "" + currentIndex);
                    currentIndex++;
                    updateImage();
                }
            }
        });

        return rootView;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        updateImage();
    }

    private void updateImage() {
        TextView textFrameCount = getView().findViewById(R.id.textFrameDisplayed);
        if (framesList.isEmpty()) {
            ImageView imagePreview = getView().findViewById(R.id.imagePreview);
            imagePreview.setImageBitmap(BitmapFactory.decodeResource(getContext().getResources(), R.drawable.empty_project));
            textFrameCount.setText(getString(R.string.no_images_text));
        } else {
            loadImageFromStorage(framesList.get(currentIndex));
            textFrameCount.setText(getString(R.string.previewing_frame_count_text, (currentIndex + 1), framesList.size()));
        }
    }

    @Override
    public void onResume() {
        super.onResume();
        getActivity().setTitle("Preview Project");
    }

    private void loadImageFromStorage(String fileName) {
        try {
            ContextWrapper cw = new ContextWrapper(getContext().getApplicationContext());
            File directory = cw.getDir(getString(R.string.image_directory), Context.MODE_PRIVATE);
            // Create imageDir
            File f = new File(directory, fileName);
            Bitmap b = BitmapFactory.decodeStream(new FileInputStream(f));
            final ImageView imagePreview = getView().findViewById(R.id.imagePreview);
            imagePreview.setImageBitmap(b);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }
}
