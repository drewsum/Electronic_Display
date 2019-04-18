package display.led_display;

import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
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


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link ProjectPreviewFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link ProjectPreviewFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class ProjectPreviewFragment extends Fragment {
    // TODO: Rename parameter arguments, choose names that match
    // the fragment initialization parameters, e.g. ARG_ITEM_NUMBER
    private static final String ARG_PARAM1 = "param1";
    private static final String ARG_PARAM2 = "param2";

    // TODO: Rename and change types of parameters
    private String mParam1;
    private String mParam2;

    private OnFragmentInteractionListener mListener;

    private ArrayList<String> framesList;
    private int currentIndex = 0;

    public ProjectPreviewFragment() {
        // Required empty public constructor
    }

    /**
     * Use this factory method to create a new instance of
     * this fragment using the provided parameters.
     *
     * @param param1 Parameter 1.
     * @param param2 Parameter 2.
     * @return A new instance of fragment ProjectPreviewFragment.
     */
    // TODO: Rename and change types and number of parameters
    public static ProjectPreviewFragment newInstance(String param1, String param2) {
        ProjectPreviewFragment fragment = new ProjectPreviewFragment();
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
        getActivity().setTitle("Project Preview");
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
        textDisplayingProject.setText("Preview Project: " + projectName);
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
        if(!framesList.isEmpty()) {
            loadImageFromStorage(framesList.get(currentIndex));
            textFrameCount.setText("Previewing Frame: " + (currentIndex + 1) + "/" + framesList.size());
        } else {
            ImageView imagePreview = getView().findViewById(R.id.imagePreview);
            imagePreview.setImageBitmap(BitmapFactory.decodeResource(getContext().getResources(), R.drawable.empty_project));
            textFrameCount.setText("There are not any images in this project yet");
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

    private void loadImageFromStorage(String fileName) {
        try {
            ContextWrapper cw = new ContextWrapper(getContext().getApplicationContext());
            File directory = cw.getDir("imageDir", Context.MODE_PRIVATE);
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
