package display.led_display;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;

/**
 * Created by Kevin on 10/8/2018.
 */

public class SplashActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);

        TinyDB tinyDB = new TinyDB(getApplicationContext());
        ArrayList<String> deviceList = tinyDB.getListString("deviceList");
        if(deviceList.size() == 0)
        {
            deviceList.add("Default Display Board");
            tinyDB.putListString("deviceList", deviceList);
            ArrayList<String> deviceData = new ArrayList<>();
            deviceData.add(0, "192.168.4.1");
            deviceData.add(1, "333");
            tinyDB.putListString("Default Display BoardData", deviceData);
        }

        int time = 1000;
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(SplashActivity.this, MenuActivity.class));
            }
        }, time);


    }
}
