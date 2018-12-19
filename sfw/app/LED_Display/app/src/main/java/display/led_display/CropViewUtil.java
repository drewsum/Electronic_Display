package display.led_display;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Rect;
import android.view.View;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import static display.led_display.MApplication.PPT_CROP_DIR;

/**
 * 指定控件区域截屏，获取Bitmap
 */
public class CropViewUtil {

    /**
     * 生成视图的预览
     * @param activity
     * @param v
     * @return  视图生成失败返回null
     *          视图生成成功返回视图的绝对路径
     */
    public static String saveImage(Activity activity, View v) {
        Bitmap bitmap;
        String path =  PPT_CROP_DIR + System.currentTimeMillis() +".png";
        View view = activity.getWindow().getDecorView();
        view.setDrawingCacheEnabled(true);
        view.buildDrawingCache();
        bitmap = view.getDrawingCache();
        Rect frame = new Rect();
        activity.getWindow().getDecorView().getWindowVisibleDisplayFrame(frame);
        int[] location = new int[2];
        v.getLocationOnScreen(location);
        try {
            bitmap = Bitmap.createBitmap(bitmap, location[0], location[1], v.getWidth(), v.getHeight());
            FileOutputStream fout = new FileOutputStream(path);
            bitmap.compress(Bitmap.CompressFormat.PNG, 100, fout);
            return path;
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IllegalArgumentException e) {
        } finally {
            // 清理缓存
            view.destroyDrawingCache();
        }
        return null;

    }
}
