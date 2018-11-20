package display.led_display;

import android.graphics.Bitmap;
import android.util.Log;

import java.util.ArrayList;

public class PixelsConverter {
    public int[] BitmapToPixels(Bitmap bitmap) {
        bitmap.getRowBytes();
        int width = bitmap.getWidth();
        int height = bitmap.getHeight();

        int[] pixels = new int[width * height];
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
        //Log.d("width=", "" + width);
        //Log.d("height=", "" + height);
        int R, G, B;
        for(int i = 0; i < pixels.length; i++)
        {
            //Log.d("pix" + i, "" + pixels[i]);
            R = (pixels[i] & 0xff0000) >> 16;
            G = (pixels[i] & 0x00ff00) >> 8;
            B = (pixels[i] & 0x0000ff) >> 0;
            //Log.d("R, G, B", "" + R + ", " + G + ", " + B);

        }
        Log.d("Pixels Length: ", "" + pixels.length);
        return pixels;
    }
    public ArrayList<Integer> PixelsToRGB(int[] pixels) {
        ArrayList<Integer> RGB = new ArrayList<Integer>();
        for(int i = 0; i < pixels.length; i++)
        {
            RGB.add((pixels[i] & 0xff0000) >> 16);
            RGB.add((pixels[i] & 0x00ff00) >> 8);
            RGB.add((pixels[i] & 0x0000ff) >> 0);
        }
        Log.d("RGB array Length: ", "" + RGB.size());
        return RGB;
    }
    public ArrayList<Integer> RGBToBits(ArrayList<Integer> rgb) {
        ArrayList<Integer> bytesOfData = new ArrayList<Integer>();
        for(int i = 0; i < rgb.size(); i++)
        {
            int[] spacedValue = new int[8];
            int val = rgb.get(i);
            spacedValue[0] = (val < 32) ? 1 : 0;
            spacedValue[2] = (val < 64) ? 1 : 0;
            spacedValue[4] = (val < 96) ? 1 : 0;
            spacedValue[6] = (val < 128) ? 1 : 0;
            spacedValue[1] = (val < 160) ? 1 : 0;
            spacedValue[3] = (val < 192) ? 1 : 0;
            spacedValue[5] = (val < 224) ? 1 : 0;
            spacedValue[7] = (val < 256) ? 1 : 0;
            bytesOfData.add(spacedValue[0]);
            bytesOfData.add(spacedValue[1]);
            bytesOfData.add(spacedValue[2]);
            bytesOfData.add(spacedValue[3]);
            bytesOfData.add(spacedValue[4]);
            bytesOfData.add(spacedValue[5]);
            bytesOfData.add(spacedValue[6]);
            bytesOfData.add(spacedValue[7]);
        }
        Log.d("bytes of data Length: ", "" + bytesOfData.size());
        return bytesOfData;
    }
    public ArrayList<Integer> BitsToMicro(ArrayList<Integer> bits) {
        ArrayList<Integer> masterScript = new ArrayList<Integer>();
        ArrayList<Integer> finalScript = new ArrayList<Integer>();
        ArrayList<Integer> secondHalf = new ArrayList<Integer>(bits.subList(bits.size() / 2, bits.size()-1));
        for(int j = 0; j < 8; j++)
        {
            finalScript.clear();
            for(int i = 0; i < secondHalf.size()/8; i++)
            {
                finalScript.add(2*i, bits.get(8*i+j));
                finalScript.add(2*i+1, secondHalf.get(8*i+j));
            }
            Log.d("final script size: ", "" + finalScript.size());
            masterScript.addAll(finalScript);
        }
        Log.d("master script size: ", "" + masterScript.size());
        return masterScript;
    }

    public byte[] compilePanelLists(ArrayList<Integer> panel0, ArrayList<Integer> panel1, ArrayList<Integer> panel2, ArrayList<Integer> panel3) {
        byte[] bites = new byte[panel1.size() / 2];
        for(int i = 0; i < panel0.size() / 2; i++)
        {
            byte bite = 0;
            bite |= (panel0.get(2*i) << 0);
            bite |= (panel0.get(2*i+1) << 1);
            bite |= (panel1.get(2*i) << 2);
            bite |= (panel1.get(2*i+1) << 3);
            bite |= (panel2.get(2*i) << 4);
            bite |= (panel2.get(2*i+1) << 5);
            bite |= (panel3.get(2*i) << 6);
            bite |= (panel3.get(2*i+1) << 7);
            bites[i] = bite;
        }
        return bites;
    }

    public byte[] BitmapToByteArray(Bitmap bitmap) {
        int[] pixels = BitmapToPixels(bitmap);
        ArrayList<Integer> rgb = PixelsToRGB(pixels);
        ArrayList<Integer> bits = RGBToBits(rgb);
        ArrayList<Integer> panel0 = BitsToMicro(bits);
        return compilePanelLists(panel0, panel0, panel0, panel0);
    }
}
