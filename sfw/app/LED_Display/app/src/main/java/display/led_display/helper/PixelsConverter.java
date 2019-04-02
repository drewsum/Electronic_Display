package display.led_display.helper;

import android.graphics.Bitmap;
import android.util.Log;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class PixelsConverter {

    private Bitmap[][] SplitBitmap(Bitmap bitmap, int dimX, int dimY) {
        Bitmap[][] bitmapArray = new Bitmap[dimX][dimY];
        int orig_width = bitmap.getWidth() / dimX;
        int orig_height = bitmap.getHeight() / dimY;
        Log.d("wwidth", "" + orig_width);
        Log.d("hheight", "" + orig_height);
        for (int x = 0; x < dimX; x++) {
            for (int y = 0; y < dimY; y++) {
                bitmapArray[x][y] = Bitmap.createBitmap(bitmap, x * orig_width, y * orig_height, orig_width, orig_height);
            }
        }
        return bitmapArray;
    }

    private int[] BitmapToPixels(Bitmap bitmap) {
        bitmap.getRowBytes();
        int width = bitmap.getWidth();
        int height = bitmap.getHeight();

        int[] pixels = new int[width * height];
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
        //Log.d("width=", "" + width);
        //Log.d("height=", "" + height);
        return pixels;
    }

    private ArrayList<Integer> PixelsToRGB(int[] pixels) {
        ArrayList<Integer> RGB = new ArrayList<Integer>();
        for (int i = 0; i < pixels.length; i++) {
//            if (pixels[i] == 0x000000) {
//                pixels[i] = 0x010101;
//            }
            RGB.add((pixels[i] & 0xff0000) >> 16);
            RGB.add((pixels[i] & 0x00ff00) >> 8);
            RGB.add((pixels[i] & 0x0000ff) >> 0);
        }
        Log.d("RGB array Length: ", "" + RGB.size());
        return RGB;
    }

    private ArrayList<Integer> RGBToBits(ArrayList<Integer> rgb) {
        ArrayList<Integer> bytesOfData = new ArrayList<Integer>();
        for (int i = 0; i < rgb.size(); i++) //12288
        {
            int[] spacedValue = new int[8];
            int val = rgb.get(i);
            // 8 bit mode
            spacedValue[0] = (val > 0) ? 1 : 0;
            spacedValue[2] = (val > 32) ? 1 : 0;
            spacedValue[4] = (val > 64) ? 1 : 0;
            spacedValue[6] = (val > 96) ? 1 : 0;
            spacedValue[1] = (val > 128) ? 1 : 0;
            spacedValue[3] = (val > 160) ? 1 : 0;
            spacedValue[5] = (val > 192) ? 1 : 0;
            spacedValue[7] = (val > 224) ? 1 : 0;
            // 8 bit mode
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

    private ArrayList<Integer> BitsToMicro(ArrayList<Integer> bits) { // bits = 98304
        ArrayList<Integer> masterScript = new ArrayList<Integer>();
        ArrayList<Integer> finalScript = new ArrayList<Integer>();
        ArrayList<Integer> secondHalf = new ArrayList<Integer>(bits.subList(bits.size() / 2, bits.size())); // 49152 - 98304
        Log.d("second half size: ", "" + secondHalf.size());
        Log.d("bits size: ", "" + bits.size());
        // 8 bit mode
        for (int j = 0; j < 8; j++) {
            finalScript.clear();
            for (int i = 0; i < (secondHalf.size() / 8); i++) // 6144 times
            {
                finalScript.add(2 * i, bits.get(8 * i + j)); // grab every 8th bit and put in order
                finalScript.add(2 * i + 1, secondHalf.get(8 * i + j)); // grab every 8th and put in order
            }
            Log.d("final script size: ", "" + finalScript.size()); // 12288 long (1 time worth for full panel)
            masterScript.addAll(finalScript);
        }
        Log.d("master script size: ", "" + masterScript.size()); // 98304 (8 times worth for 1 panel
        return masterScript;
    }

    private byte[] compilePanelLists(ArrayList<Integer> panel0, ArrayList<Integer> panel1, ArrayList<Integer> panel2, ArrayList<Integer> panel3) {
        Log.d("Panel0 size: ", "" + panel0.size());
        Log.d("Panel1 size: ", "" + panel0.size()); // 98304
        int size = panel0.size();
        byte[] bites = new byte[size / 2]; // 49152
        for (int i = 0; i < size / 2; i++) // 49152
        {
            byte bite = 0;
            bite |= (panel0.get(2 * i) << 0);
            bite |= (panel0.get(2 * i + 1) << 1);
            bite |= (panel1.get(2 * i) << 2);
            bite |= (panel1.get(2 * i + 1) << 3);
            bite |= (panel2.get(2 * i) << 4);
            bite |= (panel2.get(2 * i + 1) << 5);
            bite |= (panel3.get(2 * i) << 6);
            bite |= (panel3.get(2 * i + 1) << 7);
            bites[i] = bite;
        }
        Log.d("bites size: ", "" + bites.length);
        return bites; // 49152
    }

    public byte[] BitmapToByteArray(Bitmap bitmap, int dimX, int dimY) {
        ArrayList<Integer>[][] panelList = new ArrayList[dimX][dimY];
        Bitmap[][] bitmapArray = SplitBitmap(bitmap, dimX, dimY);
        for (int i = 0; i < dimX; i++) {
            for (int j = 0; j < dimY; j++) {
                int[] pixels = BitmapToPixels(bitmapArray[i][j]);
                ArrayList<Integer> rgb = PixelsToRGB(pixels);
                File file = new File("/storage/emulated/0/Download" + "/rgb.txt");
                Log.d("Filepath", file.getAbsolutePath());
                try (PrintWriter out = new PrintWriter(file)) {
                    for (int h = 0; h < rgb.size(); h++) {
                        String s = String.format("%d, ", rgb.get(h));
                        if (h % 9 == 0) {
                            out.println();
                        }
                        out.print(s);
                    }
                } catch (IOException io) {
                    System.out.println(io);
                }
                ArrayList<Integer> bits = RGBToBits(rgb);
                panelList[i][j] = BitsToMicro(bits);
            }
        }
        byte[] pillar0 = compilePanelLists(panelList[0][0], panelList[0][1], panelList[0][2], panelList[0][3]); // 49152
        byte[] pillar1 = compilePanelLists(panelList[1][0], panelList[1][1], panelList[1][2], panelList[1][3]);
        byte[] pillar2 = compilePanelLists(panelList[2][0], panelList[2][1], panelList[2][2], panelList[2][3]);
        byte[] pillar3 = compilePanelLists(panelList[3][0], panelList[3][1], panelList[3][2], panelList[3][3]);
        byte[] pillar4 = compilePanelLists(panelList[4][0], panelList[4][1], panelList[4][2], panelList[4][3]);
        byte[] allPillars = new byte[pillar0.length + pillar1.length + pillar2.length + pillar3.length + pillar4.length];
        Log.d("pillar size: ", "" + pillar0.length);
        for (int index = 0; index < (allPillars.length / (192 * 5)); index++) {
            System.arraycopy(pillar0, index * 192, allPillars, (index * 5) * 192, 192);
            System.arraycopy(pillar1, index * 192, allPillars, (index * 5 + 1) * 192, 192);
            System.arraycopy(pillar2, index * 192, allPillars, (index * 5 + 2) * 192, 192);
            System.arraycopy(pillar3, index * 192, allPillars, (index * 5 + 3) * 192, 192);
            System.arraycopy(pillar4, index * 192, allPillars, (index * 5 + 4) * 192, 192);
        }
        Log.d("total size: ", "" + allPillars.length);
        return allPillars;
    }
}
