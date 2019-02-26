package display.led_display;

import android.content.Context;
import android.content.ContextWrapper;
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
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

import display.led_display.helper.PixelsConverter;

public class ImageSelectActivity extends AppCompatActivity {
    TextView textTargetUri;
    //TextView texter;
    ImageView targetImage;
   // SeekBar seekbar;
  //  boolean ready = false;
   Uri targetUri;
   String filePath;

   String projectName;
   int index;

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

        Button buttonConvert = (Button) findViewById(R.id.buttonConvert);
        buttonConvert.setOnClickListener(new Button.OnClickListener() {
              @Override
              public void onClick(View arg0) {
                  // TODO Auto-generated method stub
                  Intent intent = new Intent();
                  intent.putExtra("filePath", filePath);
                  setResult(RESULT_OK, intent);
                  finish();
              }
        });

        projectName = getIntent().getExtras().getString("projectName");
        index = getIntent().getExtras().getInt("index");
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
                intent.addFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
                intent.addFlags(Intent.FLAG_GRANT_PERSISTABLE_URI_PERMISSION);
                startActivityForResult(intent, 0);
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (resultCode == RESULT_OK) {
            targetUri = data.getData();
            textTargetUri.setText(targetUri.toString());
            convert(targetUri);
        }
        String filename = projectName + "frame" + index + ".png";

        try {
            bitmap = BitmapFactory.decodeStream(getContentResolver().openInputStream(targetUri));
            int panels_width = 5;
            int panels_height = 4;
            scaledBitmap = Bitmap.createScaledBitmap(bitmap,64*panels_width,64*panels_height,true);
            ContextWrapper cw = new ContextWrapper(getApplicationContext());
            File directory = cw.getDir("imageDir", Context.MODE_PRIVATE);
            // Create imageDir
            File f = new File(directory,filename);
            filePath = f.getPath();
            FileOutputStream outputStream = new FileOutputStream (new File(filePath));
            scaledBitmap.compress(Bitmap.CompressFormat.PNG, 100, outputStream);
            outputStream.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    protected void convert(Uri targetUri)
    {
        try {
            PixelsConverter pixelsConverter = new PixelsConverter();
            bitmap = BitmapFactory.decodeStream(getContentResolver().openInputStream(targetUri));
            // ready = true;
            int panels_width = 5;
            int panels_height = 4;
            scaledBitmap = Bitmap.createScaledBitmap(bitmap,64*panels_width,64*panels_height,true);
            targetImage.setImageBitmap(scaledBitmap);
            byte[] printMe = pixelsConverter.BitmapToByteArray(scaledBitmap, panels_width, panels_height);

            // store to temp file for testing
            File file = new File("/storage/emulated/0/Download" + "/values.txt");
            Log.d("Filepath", file.getAbsolutePath());
            String s = "";
            try (PrintWriter out = new PrintWriter(file)) {
                for(int h = 0; h < printMe.length; h++) {
                    s = String.format("0x%02X, ", printMe[h]);
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
