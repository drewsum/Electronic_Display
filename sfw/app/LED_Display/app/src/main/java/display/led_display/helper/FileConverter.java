package display.led_display.helper;

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
        ArrayList<Integer> single00 = microToBits(arrayLists[0][0]);
        ArrayList<Integer> single01 = microToBits(arrayLists[0][1]);
        ArrayList<Integer> single10 = microToBits(arrayLists[1][0]);
        ArrayList<Integer> single11 = microToBits(arrayLists[1][1]);
        Bitmap[] bitmaps = rbgToBitmap(single00.toArray(), single01.toArray(), single10.toArray(), single11.toArray());
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
    public static ArrayList<Integer> microToBits(ArrayList<Integer> source) {
        if (source == null || source.size() == 0) {
            return null;
        }
        ArrayList<Integer> masterScript = new ArrayList<Integer>();
        ArrayList<Integer> finalScript = new ArrayList<Integer>();
        for (int j = 0; j < 8; j++) {
            finalScript.clear();
            for (int i = 0; i < (source.size()); i++) // 6144 times
            {
                finalScript.add(2 * i, source.get(i + j)); // grab every 8th bit and put in order
                finalScript.add(2 * i + 1, source.get(i + j)); // grab every 8th and put in order
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
    public static Bitmap[] rbgToBitmap(Object[] rgb00, Object[] rgb01, Object[] rgb10, Object[] rgb11) {
        if (rgb00 == null || rgb01 == null || rgb10 == null || rgb11 == null) {
            return null;
        }

        Bitmap[] bitmaps = new Bitmap[4];
        bitmaps[0] = Bitmap.createBitmap(integersToInts((Integer[]) rgb00), WIDTH_RECORD / 2, HEIGHT_RECORD / 2, null);
        bitmaps[1] = Bitmap.createBitmap(integersToInts((Integer[]) rgb01), WIDTH_RECORD / 2, HEIGHT_RECORD / 2, null);
        bitmaps[2] = Bitmap.createBitmap(integersToInts((Integer[]) rgb10), WIDTH_RECORD / 2, HEIGHT_RECORD / 2, null);
        bitmaps[3] = Bitmap.createBitmap(integersToInts((Integer[]) rgb11), WIDTH_RECORD / 2, HEIGHT_RECORD / 2, null);
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
        canvas.drawBitmap(bitmaps[0], 0, 0, paint);
        canvas.drawBitmap(bitmaps[1], WIDTH_RECORD / 2, 0, paint);
        canvas.drawBitmap(bitmaps[2], 0, HEIGHT_RECORD / 2, paint);
        canvas.drawBitmap(bitmaps[3], WIDTH_RECORD / 2, HEIGHT_RECORD / 2, paint);
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
