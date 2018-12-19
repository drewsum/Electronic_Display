package display.led_display;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;

public class ImageSelectActivity extends AppCompatActivity {
    TextView textTargetUri;
    //TextView texter;
    ImageView targetImage;
   // SeekBar seekbar;
  //  boolean ready = false;

    Bitmap bitmap;
    Bitmap scaledBitmap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image_select);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);
        Button buttonLoadImage = (Button) findViewById(R.id.loadimage);
        //texter = (TextView) findViewById(R.id.texter);
        textTargetUri = (TextView) findViewById(R.id.targeturi);
        targetImage = (ImageView) findViewById(R.id.targetimage);

       // seekbar = (SeekBar) findViewById(R.id.seekbar);
       // seekbar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
//            @Override
//            public void onProgressChanged(SeekBar seekBar, int progress, boolean b) {
//                PixelsConverter pixelsConverter = new PixelsConverter();
//                if (ready) {
                    // targetImage.setImageBitmap(pixelsConverter.changeBitmapContrastBrightness(bitmap, (float) progress / 100f, 1));
                    // texter.setText("Contrast: " + (float) progress / 100f);
//                    scaledBitmap = Bitmap.createScaledBitmap(bitmap,128,128,true);
//                    byte[] printMe = pixelsConverter.BitmapToByteArray(scaledBitmap, 2, 2);
//                    File file = new File("/storage/emulated/0/Download" + "/values.txt");
//                    Log.d("Filepath", file.getAbsolutePath());
//                    try (PrintWriter out = new PrintWriter(file)) {
//                        for(int h = 0; h < printMe.length; h++) {
//                            String s = String.format("0x%02X, ", printMe[h]);
//                            if(h == printMe.length-1)
//                            {
//                                s = String.format("0x%02X", printMe[h]);
//                            }
//                            if(h % 10 == 0)
//                            {
//                                out.println();
//                            }
//                            out.print(s);
//                        }
//                    } catch (IOException io) {
//                        System.out.println(io);
//                    }
//                }
//            }

//            @Override
//            public void onStartTrackingTouch(SeekBar seekBar) {}
//
//            @Override
//            public void onStopTrackingTouch(SeekBar seekBar) {}
//        });

//        seekbar.setMax(200);
//        seekbar.setProgress(100);

        buttonLoadImage.setOnClickListener(new Button.OnClickListener() {

            @Override
            public void onClick(View arg0) {
                // TODO Auto-generated method stub
                Intent intent = new Intent(Intent.ACTION_PICK,
                        android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
                startActivityForResult(intent, 0);
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == RESULT_OK){
            Uri targetUri = data.getData();
            textTargetUri.setText(targetUri.toString());
            try {
                PixelsConverter pixelsConverter = new PixelsConverter();
                bitmap = BitmapFactory.decodeStream(getContentResolver().openInputStream(targetUri));
                // ready = true;
                scaledBitmap = Bitmap.createScaledBitmap(bitmap,128,128,true);
                targetImage.setImageBitmap(scaledBitmap);
                byte[] printMe = pixelsConverter.BitmapToByteArray(scaledBitmap, 2, 2);
                File file = new File("/storage/emulated/0/Download" + "/values.txt");
                Log.d("Filepath", file.getAbsolutePath());
                try (PrintWriter out = new PrintWriter(file)) {
                    for(int h = 0; h < printMe.length; h++) {
                        String s = String.format("0x%02X, ", printMe[h]);
                        if(h == printMe.length-1)
                        {
                            s = String.format("0x%02X", printMe[h]);
                        }
                        if(h % 10 == 0)
                        {
                            out.println();
                        }
                        out.print(s);
                    }
                } catch (IOException io) {
                    System.out.println(io);
                }
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }
    }

}
