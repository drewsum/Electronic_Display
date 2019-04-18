package display.led_display;

import android.content.Context;
import android.content.ContextWrapper;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
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

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;

import display.led_display.helper.PixelsConverter;
import display.led_display.helper.TinyDB;
import display.led_display.helper.WiFiController;


/**
 * A simple {@link Fragment} subclass.
 * Activities that contain this fragment must implement the
 * {@link UploadProjectFragment.OnFragmentInteractionListener} interface
 * to handle interaction events.
 * Use the {@link UploadProjectFragment#newInstance} factory method to
 * create an instance of this fragment.
 */
public class UploadProjectFragment extends Fragment {
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
        getActivity().setTitle("Upload Project");
//        MenuActivity parent = (MenuActivity)this.getActivity().getParent();
//        Project[] projectList = parent.database.projectDao.loadAll();
//        Log.d("projects: ", "" + projectList[0].getProjectName());

    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View rootView = inflater.inflate(R.layout.fragment_upload_project, container, false);
        final View finView = rootView;
        final TinyDB tinyDB = new TinyDB(getContext().getApplicationContext());
        final ArrayList<String> projectList = tinyDB.getListString("projectList");
        Log.d("projectList", projectList.toString());
        final ArrayList<String> deviceList = tinyDB.getListString("deviceList");
        Log.d("deviceList", deviceList.toString());
        final ListView projectListview = rootView.findViewById(R.id.projectList);
        projectListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), projectList, "projectList"));
        // populate physical boards list
        final ListView deviceListview = rootView.findViewById(R.id.deviceList);
        deviceListview.setAdapter(new rowAdaptor(this.getActivity().getBaseContext(), deviceList, "deviceList"));
        Button buttonNewDevice = rootView.findViewById(R.id.buttonNewDevice);
        buttonNewDevice.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                NewDeviceFragment newDeviceFragment = new NewDeviceFragment();
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(newDeviceFragment.getTag()).replace(R.id.flContent, newDeviceFragment).commit();
            }
        });

        Button buttonNewProject = rootView.findViewById(R.id.buttonNewProject);
        buttonNewProject.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                NewProjectFragment newProjectFragment = new NewProjectFragment();
                FragmentManager fragmentManager = getActivity().getSupportFragmentManager();
                fragmentManager.beginTransaction().addToBackStack(newProjectFragment.getTag()).replace(R.id.flContent, newProjectFragment).commit();
            }
        });
        Button buttonUploadProject = rootView.findViewById(R.id.buttonUpload);
        buttonUploadProject.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // add the code to send start the upload project routine
                ListView projectListview = getView().findViewById(R.id.projectList);
                String selectedProject = projectList.get(projectListview.getSelectedItemPosition()+1);
                ArrayList<String> frameList = tinyDB.getListString(selectedProject + "frameList");
                ArrayList<String> dataList = tinyDB.getListString(selectedProject + "dataList");
                ListView deviceListview = getView().findViewById(R.id.deviceList);
                String selectedDevice = deviceList.get(deviceListview.getSelectedItemPosition()+1);
                ArrayList<String> deviceData = tinyDB.getListString(selectedDevice + "Data");
                Log.d("projectSelected", selectedProject);
                Log.d("deviceSelected", selectedDevice);

                PixelsConverter pixelsConverter = new PixelsConverter();
                int panels_width = 5;
                int panels_height = 4;
                Bitmap bitmap = null;
                ArrayList<String> payloadList = new ArrayList<>();
                Log.d("frameList size", ""+frameList.size());
                Log.d("frameList", frameList.toString());

                for(int i = 0; i < frameList.size(); i++) {
                    payloadList.clear();
                    if(i == 0) {
                        payloadList.add("Power=0");
                    }
                    // get image from internal storage
                    String filename = frameList.get(i);
                    ContextWrapper cw = new ContextWrapper(getActivity().getApplicationContext());
                    File directory = cw.getDir("imageDir", Context.MODE_PRIVATE);
                    File f = new File(directory, filename);
                    Log.d("directory", directory.toString());
                    Log.d("fileName", filename);
                    try {
                        InputStream is = new FileInputStream(f);
                        bitmap = BitmapFactory.decodeStream(is);
                        is.close();
                    } catch (IOException io) {
                        io.printStackTrace();
                    }
                    byte[] printMe = pixelsConverter.BitmapToByteArray(bitmap, panels_width, panels_height);
                    WiFiController wiFiController = new WiFiController(getView(), getActivity().getBaseContext(), selectedDevice);
                    String str = "";
                    // use a string builder
                    payloadList.add("Clear_EBI");
                    File file = new File("/storage/emulated/0/Download" + "/values.txt");
                    Log.d("Filepath", file.getAbsolutePath());
                    String s = "";
//                    try (PrintWriter out = new PrintWriter(file)) {
//                        for(int w = 0; w < printMe.length; w++) {
//                            s = String.format("0x%02X, ", printMe[w]);
//                            if(w == printMe.length-1)
//                            {
//                                s = String.format("0x%02X", printMe[w]);
//                            }
//                            if(w % 10 == 0)
//                            {
//                                out.println();
//                            }
//                            out.print(s);
//                        }
//                    } catch (FileNotFoundException io) {
//                        System.out.println(io);
//                    }

                    for (int h = 0; h < printMe.length; h++) {
                        if (h % 512 == 0) {
                            str = "";
                            str += String.format("ImageData=Addr=0x%06X,Data=", h);
                        }
                        str += String.format("%02X", printMe[h]);
                        if (h % 512 == 511) {
                            payloadList.add(str);
                        }
                    }
                    payloadList.add("EBI_2_Flash=" + (i+1) + " ");
                    if(i == frameList.size()-1) {
                        payloadList.add("Project_Data=" + (frameList.size()) + "," + dataList.get(1) + "_");
                        payloadList.add("Restart_State_Machine");
                    }
                    Log.d("size of payload", "" + payloadList.size());
                    wiFiController.sendOverWiFi("ImageData", payloadList);
                    Log.d("wifi commands sent", "" + payloadList.size());
                }
            }
        });

        return rootView;
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
