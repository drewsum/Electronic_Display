package display.led_display;

import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;

import java.util.Stack;

public class MenuActivity extends AppCompatActivity
        implements UploadProjectFragment.OnFragmentInteractionListener,
        NewProjectFragment.OnFragmentInteractionListener,
        NewDeviceFragment.OnFragmentInteractionListener,
        ProjectPreviewFragment.OnFragmentInteractionListener,
        EditProjectFragment.OnFragmentInteractionListener,
        SelectionFragment.OnFragmentInteractionListener,
        DeviceControlFragment.OnFragmentInteractionListener,
        NavigationView.OnNavigationItemSelectedListener {

    public static int SENDING = 1;
    public static int SENT = 2;
    public static int ERROR = 3;
    public static int CONNECTING = 4;
    public static int SHUTDOWN = 5;

    private Stack<MenuItem> menuItemStack = new Stack<>();
    private Fragment curFragment = null;
    private MenuItem prevMenuItem = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

//        Room.databaseBuilder(this, AppDataBase.class,
//                "mu-led").build();
//        database = AppDataBase.getInstance(this);
//        Log.d("db: ", "" + this.database.toString());
//        Log.d("hello", "hi");
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        /*} else {
            if (menuItemStack.size() > 0) {
                prevMenuItem = menuItemStack.pop();
                FragmentManager fragmentManager = getSupportFragmentManager();
                fragmentManager.beginTransaction().remove(curFragment).commit();
                setTitle("MenuActivity");
                if (prevMenuItem != null) {
                    prevMenuItem.setChecked(false);
                }
            } else {
                Class fragmentClass = null;
                // pass args
                Bundle arguments = new Bundle();

                int id = prevMenuItem.getItemId();
                if (id == R.id.nav_add) {
                    fragmentClass = NewProjectFragment.class;
                } else if (id == R.id.nav_edit) {
                    fragmentClass = SelectionFragment.class;
                    arguments.putString( "selectionType" , "project");
                    arguments.putString( "fragmentReturn" , "edit");
                } else if (id == R.id.nav_preview) {
                    fragmentClass = SelectionFragment.class;
                    arguments.putString( "selectionType" , "project");
                    arguments.putString( "fragmentReturn" , "preview");
                } else if (id == R.id.nav_upload) {
                    fragmentClass = UploadProjectFragment.class;
                } else if (id == R.id.nav_control) {
                    fragmentClass = SelectionFragment.class;
                    arguments.putString("selectionType", "device");
                    arguments.putString("fragmentReturn", "control");
                }

                try {
                    curFragment = (Fragment) fragmentClass.newInstance();
                    curFragment.setArguments(arguments);
                } catch (Exception e) {
                    e.printStackTrace();
                }

                // Replace current fragment with new fragment
                FragmentManager fragmentManager = getSupportFragmentManager();
                fragmentManager.beginTransaction().replace(R.id.flContent, curFragment).commit();
                prevMenuItem.setChecked(true);
                setTitle(prevMenuItem.getTitle());
            }
            if(!getTitle().toString().equals("MenuActivity")){
                FragmentManager fragmentManager = getSupportFragmentManager();
                fragmentManager.beginTransaction().remove(curFragment).commit();
                setTitle("MenuActivity");
                if (prevMenuItem != null) {
                    prevMenuItem.setChecked(false);
                }
                return;
            }*/
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();
        Fragment fragment = null;
        Class fragmentClass = null;

        // pass args
        Bundle arguments = new Bundle();

        if (id == R.id.nav_add) {
            fragmentClass = NewProjectFragment.class;
        } else if (id == R.id.nav_edit) {
            fragmentClass = SelectionFragment.class;
            arguments.putString( "selectionType" , "project");
            arguments.putString( "fragmentReturn" , "edit");
        } else if (id == R.id.nav_preview) {
            fragmentClass = SelectionFragment.class;
            arguments.putString( "selectionType" , "project");
            arguments.putString( "fragmentReturn" , "preview");
        } else if (id == R.id.nav_upload) {
            fragmentClass = UploadProjectFragment.class;
        } else if (id == R.id.nav_control) {
            fragmentClass = SelectionFragment.class;
            arguments.putString("selectionType", "device");
            arguments.putString("fragmentReturn", "control");
        }

        try {
            fragment = (Fragment) fragmentClass.newInstance();
            fragment.setArguments(arguments);
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Replace current fragment with new fragment
        FragmentManager fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().replace(R.id.flContent, fragment).addToBackStack(fragment.getTag()).commit();
        item.setChecked(true);
        setTitle(item.getTitle());

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    @Override
    public void onFragmentInteraction(Uri uri){
        //you can leave it empty
    }
}
