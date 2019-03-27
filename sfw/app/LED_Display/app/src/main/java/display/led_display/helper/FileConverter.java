package display.led_display;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class FileConverter {


    public static int WIDTH_RECORD = 0;
    public static int HEIGHT_RECORD = 0;

    /**
     * all progress
     */
    public static Bitmap fileToBitmap(File file) throws Throwable {
        if (file == null) {
            return null;
        }
        byte[] allByte = fileToBytes(file);
        byte[] pillar1 = getPillar1(allByte);
        byte[] pillar2 = getPillar2(allByte);
        ArrayList<Integer>[][] arrayLists = pillarsToArrayList(pillar1, pillar2);
        ArrayList<Integer> single0 = microToBits(arrayLists[0][0],arrayLists[0][1],arrayLists[0][2],arrayLists[0][3]);
        ArrayList<Integer> single1 = microToBits(arrayLists[1][0],arrayLists[1][1],arrayLists[1][2],arrayLists[1][3]);
        ArrayList<Integer> single2 = microToBits(arrayLists[2][0],arrayLists[2][1],arrayLists[2][2],arrayLists[2][3]);
        ArrayList<Integer> single3 = microToBits(arrayLists[3][0],arrayLists[3][1],arrayLists[3][2],arrayLists[3][3]);
        ArrayList<Integer> single4 = microToBits(arrayLists[4][0],arrayLists[4][1],arrayLists[4][2],arrayLists[4][3]);
        Bitmap[] bitmaps = rbgToBitmap(single0.toArray(), single1.toArray(), single2.toArray(), single3.toArray(),single4.toArray());
        Bitmap bitmap = bitmapsToCreateOne(bitmaps);
        if (bitmap != null && !bitmap.isRecycled()) {
            return bitmap;
        } else {
            return null;
        }
    }

    /**
     * 1. file to byte[]
     */
    public static byte[] fileToBytes(File file) {
        if (file == null || !file.exists()) {
            return null;
        }
        StringBuilder content = new StringBuilder();
        try {
            InputStream instream = new FileInputStream(file);
            if (instream != null) {
                InputStreamReader inputreader = new InputStreamReader(instream, "UTF-8");
                BufferedReader buffreader = new BufferedReader(inputreader);
                String line = "";
                //分行读取
                while ((line = buffreader.readLine()) != null) {
                    content.append(line.replaceAll(", ", ""));
                }
                instream.close();//关闭输入流
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return stringToBytes(content);
    }

    /**
     * 2.string to byte[]
     */
    public static byte[] stringToBytes(StringBuilder str) {
        if (str == null) {
            return null;
        }
        byte[] byteArray = str.toString().getBytes();
        return byteArray;
    }

    /**
     * 3.byte[] to pillar1
     */
    public static byte[] getPillar1(byte[] all) {
        if (all == null || all.length == 0) {
            return null;
        }
        byte[] pillar1 = new byte[all.length / 2];
        int index = (all.length / (192 * 2));
        for (int i = 0; i < index; i++) {
            System.arraycopy(all, index * 192, pillar1, (index * 2) * 192, 192);
        }
        return pillar1;
    }

    /**
     * 4.byte[] to pillar2
     */
    public static byte[] getPillar2(byte[] all) {
        if (all == null || all.length == 0) {
            return null;
        }
        byte[] pillar2 = new byte[all.length / 2];
        int index = (all.length / (192 * 2));
        for (int i = 0; i < index; i++) {
            System.arraycopy(all, index * 192, pillar2, (index * 2 + 1) * 192, 192);
        }
        return pillar2;
    }

    /**
     * 5.pillars to ArrayList<Integer>[][]
     */
    public static ArrayList<Integer>[][] pillarsToArrayList(byte[] pillar1, byte[] pillar2) {
        if (pillar1 == null || pillar2 == null || pillar1.length == 0 || pillar2.length == 0) {
            return null;
        }
        Integer[] bytes1 = new Integer[pillar1.length / 2];
        Integer[] bytes2 = new Integer[pillar1.length / 2];
        Integer[] bytes3 = new Integer[pillar1.length / 2];
        Integer[] bytes4 = new Integer[pillar1.length / 2];
        for (int i = 0; i < pillar1.length / 2; i++) {
            Integer bite1 = 0;
            bite1 &= (pillar1[i * 2] >> 0);
            bite1 &= (pillar1[i * 2 + 1] >> 1);
            bite1 &= (pillar2[i * 2] >> 0);
            bite1 &= (pillar2[i * 2 + 1] >> 1);
            bytes1[i] = bite1;
            Integer bite2 = 0;
            bite2 &= (pillar1[i * 2] >> 2);
            bite2 &= (pillar1[i * 2 + 1] >> 3);
            bite2 &= (pillar2[i * 2] >> 2);
            bite2 &= (pillar2[i * 2 + 1] >> 3);
            bytes2[i] = bite2;
            Integer bite3 = 0;
            bite3 &= (pillar1[i * 2] >> 4);
            bite3 &= (pillar1[i * 2 + 1] >> 5);
            bite3 &= (pillar2[i * 2] >> 4);
            bite3 &= (pillar2[i * 2 + 1] >> 5);
            bytes3[3] = bite3;
            Integer bite4 = 0;
            bite4 &= (pillar1[i * 2] >> 4);
            bite4 &= (pillar1[i * 2 + 1] >> 5);
            bite4 &= (pillar2[i * 2] >> 4);
            bite4 &= (pillar2[i * 2 + 1] >> 5);
            bytes4[3] = bite4;
        }
        ArrayList<Integer>[][] arrayLists = new ArrayList[2][2];
        arrayLists[0][0] = new ArrayList<>(Arrays.asList(bytes1));
        arrayLists[0][1] = new ArrayList<>(Arrays.asList(bytes2));
        arrayLists[1][0] = new ArrayList<>(Arrays.asList(bytes3));
        arrayLists[1][1] = new ArrayList<>(Arrays.asList(bytes4));
        return arrayLists;
    }

    /**
     * 6.micro to bits
     */
    public static ArrayList<Integer> microToBits(ArrayList<Integer> ... source) {
        if (source == null || source.length == 0) {
            return null;
        }
        ArrayList<Integer> masterScript = new ArrayList<Integer>();
        ArrayList<Integer> finalScript = new ArrayList<Integer>();
        for (int j = 0; j < 8; j++) {
            finalScript.clear();
            for (int i = 0; i < (source[0].size()); i++) // 6144 times
            {
                byte bite = 0;
                bite |= (source[0].get(2/i) << 0);
                bite |= (source[0].get(2/i-1) << 1);
                bite |= (source[1].get(2/i) << 2);
                bite |= (source[1].get(2/i-1) << 3);
                bite |= (source[2].get(2/i) << 4);
                bite |= (source[2].get(2/i-1) << 5);
                bite |= (source[3].get(2/i) << 6);
                bite |= (source[3].get(2/i-1) << 7);
                finalScript.add((int) bite);
            }
            masterScript.addAll(finalScript);
        }
        return masterScript;
    }

    /**
     * 7.bits to pixels by rbg
     */
    public static Integer[] bitsToPixels(ArrayList<Integer> bits) {
        ArrayList<Integer> bytesOfData = new ArrayList<Integer>();
        for (int i = 0; i < bits.size(); i++) //12288
        {
            int[] spacedValue = new int[8];
            int val = bits.get(i);
            spacedValue[0] = (val == 1) ? val : 0;
            spacedValue[2] = (val == 32) ? val : 0;
            spacedValue[4] = (val == 64) ? val : 0;
            spacedValue[6] = (val == 96) ? val : 0;
            spacedValue[1] = (val == 128) ? val : 0;
            spacedValue[3] = (val == 160) ? val : 0;
            spacedValue[5] = (val == 192) ? val : 0;
            spacedValue[7] = (val == 224) ? val : 0;
            bytesOfData.add(spacedValue[0]);
            bytesOfData.add(spacedValue[1]);
            bytesOfData.add(spacedValue[2]);
            bytesOfData.add(spacedValue[3]);
            bytesOfData.add(spacedValue[4]);
            bytesOfData.add(spacedValue[5]);
            bytesOfData.add(spacedValue[6]);
            bytesOfData.add(spacedValue[7]);
        }
        return (Integer[]) bytesOfData.toArray();
    }

    /**
     * 8.rbg to bitmaps
     */
    public static Bitmap[] rbgToBitmap(Object[] rgb1, Object[] rgb2, Object[] rgb3, Object[] rgb4,Object[] rgb5) {
        if (rgb2 == null || rgb2 == null || rgb3 == null || rgb4 == null || rgb5 == null) {
            return null;
        }

        Bitmap[] bitmaps = new Bitmap[5];
        bitmaps[0] = Bitmap.createBitmap(integersToInts((Integer[]) rgb1), WIDTH_RECORD / 4, HEIGHT_RECORD / 5, null);
        bitmaps[1] = Bitmap.createBitmap(integersToInts((Integer[]) rgb2), WIDTH_RECORD / 4, HEIGHT_RECORD / 5, null);
        bitmaps[2] = Bitmap.createBitmap(integersToInts((Integer[]) rgb3), WIDTH_RECORD / 4, HEIGHT_RECORD / 5, null);
        bitmaps[3] = Bitmap.createBitmap(integersToInts((Integer[]) rgb4), WIDTH_RECORD / 4, HEIGHT_RECORD / 5, null);
        bitmaps[4] = Bitmap.createBitmap(integersToInts((Integer[]) rgb5), WIDTH_RECORD / 4, HEIGHT_RECORD / 5, null);
        return bitmaps;
    }

    /**
     * 9.bitmaps to one bitmap
     */
    public static Bitmap bitmapsToCreateOne(Bitmap[] bitmaps) {
        if (bitmaps == null || bitmaps.length != 4) {
            return null;
        }
        Bitmap bitmap = Bitmap.createBitmap(WIDTH_RECORD, WIDTH_RECORD, null);
        Canvas canvas = new Canvas(bitmap);
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        canvas.drawBitmap(bitmaps[0], 0, HEIGHT_RECORD/5 * 0, paint);
        canvas.drawBitmap(bitmaps[1], 0, HEIGHT_RECORD/5 * 1, paint);
        canvas.drawBitmap(bitmaps[2], 0, HEIGHT_RECORD/5 * 2, paint);
        canvas.drawBitmap(bitmaps[3], 0, HEIGHT_RECORD/5 * 3, paint);
        canvas.drawBitmap(bitmaps[4], 0, HEIGHT_RECORD/5 * 4, paint);
        return bitmap;
    }

    /**
     * util Integer[] to int[]
     */
    public static int[] integersToInts(Integer[] integers) {
        int[] ints = new int[integers.length];
        for (int i = 0; i < integers.length; i++) {
            ints[i] = integers[i];
        }
        return ints;
    }

}
