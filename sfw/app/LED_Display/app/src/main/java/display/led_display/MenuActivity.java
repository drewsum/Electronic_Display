package display.led_display;

import android.os.Bundle;
import android.support.design.widget.NavigationView;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.MenuItem;

import java.util.ArrayList;

import display.led_display.helper.DataManager;

public class MenuActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        setTheme(R.style.AppTheme);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        DrawerLayout drawer = findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.addDrawerListener(toggle);
        toggle.syncState();

        NavigationView navigationView = findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        DataManager dataManager = new DataManager(getApplicationContext());
        ArrayList<String> deviceList = dataManager.getListString("deviceList");
        if(deviceList.size() == 0)
        {
            deviceList.add("Default Display Board");
            dataManager.putListString("deviceList", deviceList);
            ArrayList<String> deviceData = new ArrayList<>();
            deviceData.add(0, "192.168.4.1");
            deviceData.add(1, "333");
            dataManager.putListString("Default Display BoardData", deviceData);
        }

        UploadProjectFragment firstFrag = new UploadProjectFragment();
        FragmentManager fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().addToBackStack(firstFrag.getTag()).replace(R.id.flContent, firstFrag).commit();

        //setTitle("Upload Project");
    }

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        // Handle navigation view item clicks here.
        int id = item.getItemId();
        Fragment fragment = null;
        Class fragmentClass = null;

        // pass args
        Bundle arguments = new Bundle();

        switch (id) {
            case R.id.nav_add:
                fragmentClass = NewProjectFragment.class;
                break;
            case R.id.nav_edit:
                fragmentClass = SelectionFragment.class;
                arguments.putString("selectionType", "project");
                arguments.putString("fragmentReturn", "edit");
                break;
            case R.id.nav_preview:
                fragmentClass = SelectionFragment.class;
                arguments.putString("selectionType", "project");
                arguments.putString("fragmentReturn", "preview");
                break;
            case R.id.nav_upload:
                fragmentClass = UploadProjectFragment.class;
                break;
            case R.id.nav_new:
                fragmentClass = NewDeviceFragment.class;
                break;
            case R.id.nav_control:
                fragmentClass = SelectionFragment.class;
                arguments.putString("selectionType", "device");
                arguments.putString("fragmentReturn", "control");
                break;
            case R.id.nav_about:
                fragmentClass = AboutFragment.class;
                break;
        }

        try {
            fragment = (Fragment) fragmentClass.newInstance();
            fragment.setArguments(arguments);
        } catch (Exception e) {
            e.printStackTrace();
        }

        // Replace current fragment with new fragment
        FragmentManager fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().addToBackStack(fragment.getTag()).replace(R.id.flContent, fragment).commit();
        item.setChecked(true);
        setTitle(item.getTitle());

        DrawerLayout drawer = findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

}
