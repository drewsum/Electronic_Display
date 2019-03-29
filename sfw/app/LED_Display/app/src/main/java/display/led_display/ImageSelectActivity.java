package display.led_display;

import android.content.Context;
import android.content.ContextWrapper;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Map;

import display.led_display.helper.PixelsConverter;
import display.led_display.helper.TinyDB;
import display.led_display.helper.WiFiController;

public class ImageSelectActivity extends AppCompatActivity {
    TextView textTargetUri;
    //TextView texter;
    ImageView targetImage;
   // SeekBar seekbar;
  //  boolean ready = false;
   Uri targetUri;
   String filePath;

   String projectName;
   int namingNumber;

    Bitmap bitmap;
    Bitmap scaledBitmap;

    // true: Aspect Ratio, false: Stetch to Fit
    Boolean boolAspectRatio = false;

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

        projectName = getIntent().getExtras().getString("projectName");
        namingNumber = getIntent().getExtras().getInt("namingNumber");

        Switch switchAspectRatio = (Switch) findViewById(R.id.switchAspectRatio);
        if (switchAspectRatio != null) {
            switchAspectRatio.setOnCheckedChangeListener(new Switch.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                    if(isChecked) {
                        // switch is "ON" so it is true
                        boolAspectRatio = true;
                        Log.d("switchPressed", "Keep Aspect Ratio");
                        saveOff();
                        TinyDB tinyDB = new TinyDB(getApplicationContext());
                        Map<String, ?> tinyDBAll = tinyDB.getAll();
                        Log.d("print all", tinyDBAll.toString());
                    } else {
                        // switch is "OFF" so it is false
                        boolAspectRatio = false;
                        Log.d("switchPressed", "Stretch To Fit");
                        saveOff();
                    }
                }
            });
        }

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
            // display the image here depending on how the boolean value is
            textTargetUri.setText(targetUri.toString());
            Button confirmButton = (Button) findViewById(R.id.buttonConvert);
            saveOff();
            confirmButton.setOnClickListener(new Button.OnClickListener() {
                @Override
                public void onClick(View arg0) {
                    // TODO Auto-generated method stub
                    convert(targetUri);
                    Intent intent = new Intent();
                    intent.putExtra("filePath", filePath);
                    setResult(RESULT_OK, intent);
                    finish();
                }
            });
        }

    }

    protected void saveOff()
    {
        String filename = projectName + "frame" + namingNumber + ".png";

        try {
            bitmap = BitmapFactory.decodeStream(getContentResolver().openInputStream(targetUri));
            int panels_width = 320;
            int panels_height = 256;
            if(boolAspectRatio == false) {
                scaledBitmap = Bitmap.createScaledBitmap(bitmap, panels_width, panels_height,true);
            } else {
                scaledBitmap = fixedRatio(bitmap, panels_width, panels_height);
            }
            targetImage.setImageBitmap(scaledBitmap);
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
            // switch this to get the image from tinyDB
            bitmap = BitmapFactory.decodeStream(getContentResolver().openInputStream(targetUri));
            // ready = true;
            int panels_width = 5;
            int panels_height = 4;
            scaledBitmap = Bitmap.createScaledBitmap(bitmap,64*panels_width,64*panels_height,true);
            byte[] printMe = pixelsConverter.BitmapToByteArray(scaledBitmap, panels_width, panels_height);
            WiFiController wiFiController = new WiFiController();
            String str = "";
            for(int h = 0; h < 10000; h++) {
                str += String.format("%02X", printMe[h]);
                Log.d("hi", "working...");
            }
            Log.d("bytes", str);
            wiFiController.sendOverWiFi(getBaseContext(), "Display Board","ImageData", str);
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

    private static Bitmap fixedRatio(Bitmap imageToScale, int destinationWidth, int destinationHeight) {
        if (destinationHeight > 0 && destinationWidth > 0 && imageToScale != null) {
            int width = imageToScale.getWidth();
            int height = imageToScale.getHeight();

            //Calculate the max changing amount and decide which dimension to use
            float widthRatio = (float) destinationWidth / (float) width;
            float heightRatio = (float) destinationHeight / (float) height;

            //Use the ratio that will fit the image into the desired sizes
            int finalWidth = (int)Math.floor(width * widthRatio);
            int finalHeight = (int)Math.floor(height * widthRatio);
            if (finalWidth > destinationWidth || finalHeight > destinationHeight) {
                finalWidth = (int)Math.floor(width * heightRatio);
                finalHeight = (int)Math.floor(height * heightRatio);
            }

            //Scale given bitmap to fit into the desired area
            imageToScale = Bitmap.createScaledBitmap(imageToScale, finalWidth, finalHeight, true);

            //Created a bitmap with desired sizes
            Bitmap scaledImage = Bitmap.createBitmap(destinationWidth, destinationHeight, Bitmap.Config.ARGB_8888);
            Canvas canvas = new Canvas(scaledImage);

            //Draw background color
            Paint paint = new Paint();
            paint.setColor(Color.BLACK);
            paint.setStyle(Paint.Style.FILL);
            canvas.drawRect(0, 0, canvas.getWidth(), canvas.getHeight(), paint);

            //Calculate the ratios and decide which part will have empty areas (width or height)
            float ratioBitmap = (float)finalWidth / (float)finalHeight;
            float destinationRatio = (float) destinationWidth / (float) destinationHeight;
            float left = ratioBitmap >= destinationRatio ? 0 : (float)(destinationWidth - finalWidth) / 2;
            float top = ratioBitmap < destinationRatio ? 0: (float)(destinationHeight - finalHeight) / 2;
            canvas.drawBitmap(imageToScale, left, top, null);

            return scaledImage;
        } else {
            return imageToScale;
        }
    }
}
