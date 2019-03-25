package display.led_display;

import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Point;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.os.SystemClock;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.webkit.WebView;

import java.util.ArrayList;
import java.util.List;

public class ScreenUtil {

    private static Bitmap getViewBitmapWithoutBottom(View v, int height, int padding) {
        if (null == v) {
            return null;
        }
        v.setDrawingCacheEnabled(true);
        v.buildDrawingCache();
        if (Build.VERSION.SDK_INT >= 11) {
            v.measure(View.MeasureSpec.makeMeasureSpec(v.getWidth(), View.MeasureSpec.EXACTLY), View.MeasureSpec.makeMeasureSpec(v.getHeight(), View.MeasureSpec.EXACTLY));
            v.layout((int) v.getX(), (int) v.getY(), (int) v.getX() + v.getMeasuredWidth(), (int) v.getY() + v.getMeasuredHeight());
        } else {
            v.measure(View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED), View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED));
            v.layout(0, 0, v.getMeasuredWidth(), v.getMeasuredHeight());
        }
        Bitmap bp = Bitmap.createBitmap(v.getDrawingCache(), 0, padding, v.getMeasuredWidth(), height);
        v.setDrawingCacheEnabled(false);
        v.destroyDrawingCache();
        return bp;
    }

    public static List<Bitmap> mBitmaps = new ArrayList<>();
    public static int CROP_PAGE = 0;
    public static int TOTAL_PAGE = 0;
    public static final float EXT_DIS = 5.5f;
    public static final long DURATION = 525L;
    public static Bitmap MERGE_BITMAP = null;

    public static int vh = 0;
    public static Bitmap temp = null;
    public static Handler mHandler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
        }
    };

    public static class MRunnable implements Runnable {

        private int position;

        public MRunnable(int position) {
            this.position = position;
        }

        @Override
        public void run() {

        }

        public int getPosition() {
            return position;
        }

        public void setPosition(int position) {
            this.position = position;
        }
    }

    public static int dip2px(Context context, float dpValue) {
        float scale = context.getResources().getDisplayMetrics().density;
        return (int) (dpValue * scale + 0.5f);
    }

    public static void all(final int viewHeight, final WebView view, final int height, final int top) {
        if (CROP_PAGE == 0 || TOTAL_PAGE == 0 || CROP_PAGE > TOTAL_PAGE) {
            return;
        }
        vh = 0;
        temp = null;
        mBitmaps.clear();
        DisplayActivity.CROP_RESULT_BITMAP = null;
        MERGE_BITMAP = getViewBitmapWithoutBottom(view, height, 0);
        view.scrollTo(0, 0);
        final int specialCount = TOTAL_PAGE - viewHeight / height;
        final int specialLength = viewHeight % height;
        view.buildDrawingCache(true);
        view.setDrawingCacheEnabled(true);
        view.setVerticalScrollBarEnabled(false);
        final int w = getScreenWidth(view.getContext());
        for (int i = 0; i < CROP_PAGE; i++) {
            mHandler.postDelayed(new MRunnable(i) {
                @Override
                public void run() {
                    if (getPosition() == 0) {
                        if (getPosition() >= specialCount) {
                            temp = getViewBitmapWithoutBottom(view, height, (getPosition() - specialCount) * height + specialLength);
                        } else {
                            temp = getViewBitmapWithoutBottom(view, height, top);
                        }
                        mBitmaps.add(temp);
                        MERGE_BITMAP = mergeBitmap(vh, w, temp, 0, vh - height, DisplayActivity.CROP_RESULT_BITMAP, 0, 0);
                    } else {
                        mHandler.postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                if (getPosition() >= specialCount) {
                                    temp = getViewBitmapWithoutBottom(view, height, (getPosition() - specialCount) * height + specialLength);
                                } else {
                                    temp = getViewBitmapWithoutBottom(view, height, top);
                                }
                                mBitmaps.add(temp);
                                MERGE_BITMAP = mergeBitmap(vh, w, temp, 0, vh - height, DisplayActivity.CROP_RESULT_BITMAP, 0, 0);
                            }
                        }, 65);
                        long dowTime = SystemClock.uptimeMillis();
                        view.dispatchTouchEvent(MotionEvent.obtain(dowTime, dowTime,
                                MotionEvent.ACTION_DOWN, 100, 100 + height + top + dip2px(view.getContext(), EXT_DIS), 0));
                        view.dispatchTouchEvent(MotionEvent.obtain(dowTime, dowTime,
                                MotionEvent.ACTION_MOVE, 100, 100 + (height + top + dip2px(view.getContext(), EXT_DIS)) / 3, 0));
                        view.dispatchTouchEvent(MotionEvent.obtain(dowTime, dowTime,
                                MotionEvent.ACTION_MOVE, 100, 100 + (height + top + dip2px(view.getContext(), EXT_DIS)) / 2, 0));
                        view.dispatchTouchEvent(MotionEvent.obtain(dowTime, dowTime,
                                MotionEvent.ACTION_MOVE, 100, 100, 0));
                        view.dispatchTouchEvent(MotionEvent.obtain(dowTime, dowTime,
                                MotionEvent.ACTION_UP, 100, 100, 0));
                    }
                    vh += (height + top);
                }
            }, DURATION * (i + 1));
        }
    }

    /**
     * 拼接图片
     *
     * @param newImageH
     * @param newImageW
     * @param background
     * @param backX
     * @param backY
     * @param foreground
     * @param foreX
     * @param foreY
     * @return
     */
    private static Bitmap mergeBitmap(int newImageH, int newImageW, Bitmap background, float backX, float backY, Bitmap foreground, float foreX, float foreY) {
        if (null == background || null == foreground) {
            return null;
        }
        Bitmap bitmap = Bitmap.createBitmap(newImageW, newImageH, Bitmap.Config.RGB_565);
        Canvas cv = new Canvas(bitmap);
        cv.drawBitmap(foreground, foreX, foreY, null);
        cv.drawBitmap(background, backX, backY, null);
        cv.save();
        cv.restore();
        return bitmap;
    }

    /**
     * get the width of screen
     */
    public static int getScreenWidth(Context ctx) {
        int w = 0;
        if (Build.VERSION.SDK_INT > 13) {
            Point p = new Point();
            ((WindowManager) ctx.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay().getSize(p);
            w = p.x;
        } else {
            w = ((WindowManager) ctx.getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay().getWidth();
        }
        return w;
    }
}
