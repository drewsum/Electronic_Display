package display.led_display.helper;

import android.graphics.Bitmap;
import android.util.Log;

import java.util.ArrayList;

class PixelsConverter {

    private Bitmap[][] SplitBitmap(Bitmap bitmap, int dimX, int dimY) {
        Log.d("Splitting bitmap", "X: " + dimX + " Y: " + dimY);
        Bitmap[][] bitmapArray = new Bitmap[dimX][dimY];
        int orig_width = bitmap.getWidth() / dimX;
        int orig_height = bitmap.getHeight() / dimY;
        for (int x = 0; x < dimX; x++) {
            for (int y = 0; y < dimY; y++) {
                bitmapArray[x][y] = Bitmap.createBitmap(bitmap, x * orig_width, y * orig_height, orig_width, orig_height);
            }
        }
        Log.d("Splitting bitmap", "Done");
        return bitmapArray;
    }

    private int[] BitmapToPixels(Bitmap bitmap) {
        int width = bitmap.getWidth();
        int height = bitmap.getHeight();

        int[] pixels = new int[width * height];
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
        return pixels;
    }

    private ArrayList<Integer> PixelsToRGB(int[] pixels) {
        ArrayList<Integer> RGB = new ArrayList<>();
        for (int pixel : pixels) {
            RGB.add((pixel & 0xff0000) >> 16);
            RGB.add((pixel & 0x00ff00) >> 8);
            RGB.add(pixel & 0x0000ff);
        }
        return RGB;
    }

    // This function takes the RGB bytes and converts them each to an
    // 8 bit representation of how intense to display that color
    private ArrayList<Integer> RGBToBits(ArrayList<Integer> rgb) {
        ArrayList<Integer> bytesOfData = new ArrayList<>();
        for (int i = 0; i < rgb.size(); i++)
        {
            int val = rgb.get(i);
            bytesOfData.add(val > 0 ? 1 : 0);
            bytesOfData.add(val > 128 ? 1 : 0);
            bytesOfData.add(val > 32 ? 1 : 0);
            bytesOfData.add(val > 160 ? 1 : 0);
            bytesOfData.add(val > 64 ? 1 : 0);
            bytesOfData.add(val > 192 ? 1 : 0);
            bytesOfData.add(val > 96 ? 1 : 0);
            bytesOfData.add(val > 224 ? 1 : 0);
        }
        return bytesOfData;
    }

    private ArrayList<Integer> BitsToMicro(ArrayList<Integer> bits) {
        ArrayList<Integer> masterScript = new ArrayList<>();
        ArrayList<Integer> finalScript = new ArrayList<>();
        ArrayList<Integer> secondHalf = new ArrayList<>(bits.subList(bits.size() / 2, bits.size()));
        // 8 bit mode
        for (int j = 0; j < 8; j++) {
            finalScript.clear();
            for (int i = 0; i < (secondHalf.size() / 8); i++)
            {
                finalScript.add(2 * i, bits.get(8 * i + j)); // grab every 8th bit and put in order
                finalScript.add(2 * i + 1, secondHalf.get(8 * i + j)); // grab every 8th and put in order
            }
            masterScript.addAll(finalScript);
        }
        return masterScript;
    }

    private byte[] compilePanelLists(ArrayList<Integer> panel0, ArrayList<Integer> panel1, ArrayList<Integer> panel2, ArrayList<Integer> panel3) {
        int size = panel0.size();
        byte[] bites = new byte[size / 2];
        for (int i = 0; i < size / 2; i++)
        {
            byte bite = 0;
            bite |= panel0.get(2 * i);
            bite |= (panel0.get(2 * i + 1) << 1);
            bite |= (panel1.get(2 * i) << 2);
            bite |= (panel1.get(2 * i + 1) << 3);
            bite |= (panel2.get(2 * i) << 4);
            bite |= (panel2.get(2 * i + 1) << 5);
            bite |= (panel3.get(2 * i) << 6);
            bite |= (panel3.get(2 * i + 1) << 7);
            bites[i] = bite;
        }
        return bites;
    }

    // master method that utilizes other pixel converter methods
    public byte[] BitmapToByteArray(Bitmap bitmap, int dimX, int dimY) {
        ArrayList[][] panelList = new ArrayList[dimX][dimY];
        Bitmap[][] bitmapArray = SplitBitmap(bitmap, dimX, dimY);
        for (int i = 0; i < dimX; i++) {
            for (int j = 0; j < dimY; j++) {
                int[] pixels = BitmapToPixels(bitmapArray[i][j]);
                ArrayList<Integer> rgb = PixelsToRGB(pixels);
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
        for (int index = 0; index < (allPillars.length / (192 * 5)); index++) {
            System.arraycopy(pillar0, index * 192, allPillars, (index * 5) * 192, 192);
            System.arraycopy(pillar1, index * 192, allPillars, (index * 5 + 1) * 192, 192);
            System.arraycopy(pillar2, index * 192, allPillars, (index * 5 + 2) * 192, 192);
            System.arraycopy(pillar3, index * 192, allPillars, (index * 5 + 3) * 192, 192);
            System.arraycopy(pillar4, index * 192, allPillars, (index * 5 + 4) * 192, 192);
        }
        return allPillars;
    }
}
