package display.led_display;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.net.Uri;
import android.net.http.SslError;
import android.os.Build;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.webkit.SslErrorHandler;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.isseiaoki.simplecropview.CropImageView;
import com.isseiaoki.simplecropview.callback.CropCallback;
import com.isseiaoki.simplecropview.callback.LoadCallback;
import com.jiang.geo.R;

import java.io.File;

import static android.webkit.WebView.enableSlowWholeDocumentDraw;
import static display.led_display.ScreenUtil.CROP_PAGE;
import static display.led_display.ScreenUtil.DURATION;
import static display.led_display.ScreenUtil.all;

/**
 * 展示文件的页面
 */
public class DisplayActivity extends AppCompatActivity implements LoadCallback, View.OnClickListener {

    public static Bitmap CROP_RESULT_BITMAP;

    // 文件路径
    private String filePath;
    // 裁剪控件
    private CropImageView mCropImageView;
    // 裁剪按钮
    private LinearLayout btnCrop;
    private ImageView no;
    private ImageView yes;
    private ImageView result;
    // 记录被裁剪的目标图片Uri
    private Uri mCropUri;
    // 记录两个菜单按钮，控制显隐
    private MenuItem crop, back;
    private WebView mWebView;
    private boolean isSetHeight;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        enableSlowWholeDocumentDraw();
        setContentView(R.layout.activity_file_display);
        init();
    }

    /**
     * 初始化操作
     */
    public void init() {
        // 设置标题
        setTitle("Display File");
        // 设置返回键
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        // 找到View
        mWebView = (WebView) findViewById(R.id.web);
        mCropImageView = (CropImageView) findViewById(R.id.cropImageView);
        btnCrop = (LinearLayout) findViewById(R.id.btn_crop);
        no = (ImageView) findViewById(R.id.no);
        yes = (ImageView) findViewById(R.id.yes);
        result = (ImageView) findViewById(R.id.result);
        // 设置裁剪选择控件点击事件
        yes.setOnClickListener(this);
        no.setOnClickListener(this);
        // 设置获取文件路径监听
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            mWebView.getSettings().setMixedContentMode(WebSettings.MIXED_CONTENT_ALWAYS_ALLOW);
        }
        mWebView.setWebViewClient(new WebViewClient() {
            @Override
            public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
                handler.proceed();
            }

            @Override
            public void onPageFinished(WebView view, String url) {
                super.onPageFinished(view, url);
                mWebView.getLayoutParams().height = 100000;
            }
        });
        mWebView.getSettings().setUseWideViewPort(true);
        mWebView.getSettings().setJavaScriptEnabled(true);
        mWebView.getSettings().setDisplayZoomControls(false);
        mWebView.getSettings().setUseWideViewPort(true);
        mWebView.getSettings().setLoadWithOverviewMode(true);
        mWebView.loadUrl(getIntent().getStringExtra("path"));
        // mWebView.loadUrl("https://www.sina.com.cn"); // 测试地址
    }

    /**
     * 将对应路径的文件展示到mSuperFileView
     *
     * @param mSuperFileView
     */
    private void getFilePathAndShowFile(SuperFileView mSuperFileView) {
        mSuperFileView.displayFile(new File(getFilePath()));
    }

    /**
     * 页面销毁的声明周期
     */
    @Override
    public void onDestroy() {
        super.onDestroy();
        // 释放mSuperFileView
    }

    public void setFilePath(String fileUrl) {
        this.filePath = fileUrl;
    }

    private String getFilePath() {
        return filePath;
    }

    /**
     * 裁剪菜单
     *
     * @param menu
     * @return
     */
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        crop = menu.findItem(R.id.crop);
        back = menu.findItem(R.id.back);
        return true;
    }

    /**
     * 菜单事件
     *
     * @param item
     * @return
     */
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // 裁剪菜单事件
        if (item.getItemId() == R.id.crop) {
            isSetHeight = false;
            mWebView.postDelayed(new Runnable() {
                @Override
                public void run() {
                    // 让裁剪控件去加载截图的文件
                    mCropImageView.load(mCropUri = Uri.fromFile(new File(CropViewUtil.saveImage(DisplayActivity.this, mWebView)))).execute(DisplayActivity.this);
                    // 展示裁剪相关控件可见
                    mCropImageView.setVisibility(View.VISIBLE);
                    btnCrop.setVisibility(View.VISIBLE);
                }
            }, 100L);
            return true;
        }
        // 回退按钮事件
        if (item.getItemId() == R.id.back) {
            back.setVisible(false);
            crop.setVisible(true);
            // 展示隐藏文件浏览控件
            mWebView.setVisibility(View.VISIBLE);
            // 隐藏之前的裁剪结果
            result.setImageBitmap(null);
            result.setVisibility(View.GONE);
        }
        // 返回按钮事件
        if (item.getItemId() == android.R.id.home) {
            finish();
            return true;
        }
        if (item.getItemId() == R.id.all) {
            isSetHeight = true;
            View view = LayoutInflater.from(DisplayActivity.this)
                    .inflate(R.layout.dialog_info, null, false);
            final EditText et1 = (EditText) view.findViewById(R.id.et1);
            final EditText et2 = (EditText) view.findViewById(R.id.et2);
            new AlertDialog.Builder(DisplayActivity.this)
                    .setTitle("Input Info")
                    .setView(view)
                    .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            String et1s = et1.getText().toString();
                            String et2s = et2.getText().toString();
                            if (TextUtils.isEmpty(et1s) || TextUtils.isEmpty(et2s)) {
                                Toast.makeText(DisplayActivity.this, "Please enter information", Toast.LENGTH_SHORT).show();
                                return;
                            }
                            int int1 = Integer.parseInt(et1s);
                            int int2 = Integer.parseInt(et2s);
                            if (int1 < int2) {
                                Toast.makeText(DisplayActivity.this, "The total number of pages cannot be less than the number of truncated pages", Toast.LENGTH_SHORT).show();
                                return;
                            }
                            ScreenUtil.CROP_PAGE = int2;
                            ScreenUtil.TOTAL_PAGE = int1;
                            Toast.makeText(DisplayActivity.this, "Please set the height of one page of PPT", Toast.LENGTH_SHORT).show();
                            mWebView.postDelayed(new Runnable() {
                                @Override
                                public void run() {
                                    // 让裁剪控件去加载截图的文件
                                    mCropImageView.load(mCropUri = Uri.fromFile(new File(CropViewUtil.saveImage(DisplayActivity.this, mWebView)))).execute(DisplayActivity.this);
                                    // 展示裁剪相关控件可见
                                    mCropImageView.setVisibility(View.VISIBLE);
                                    btnCrop.setVisibility(View.VISIBLE);
                                }
                            }, 500L);
                        }
                    })
                    .setNegativeButton("取消", null)
                    .show();
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private Bitmap captureScreenforRecord(WebView webView, int singleHeight) {
        webView.measure(View.MeasureSpec.makeMeasureSpec(
                View.MeasureSpec.UNSPECIFIED, View.MeasureSpec.UNSPECIFIED),
                View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED));
        webView.layout(0, 0, webView.getMeasuredWidth(),
                webView.getMeasuredHeight());
        webView.setDrawingCacheEnabled(true);
        webView.buildDrawingCache();

        /*Bitmap bm = Bitmap.createBitmap(webView.getMeasuredWidth(),
                webView.getMeasuredHeight(), Bitmap.Config.RGB_565);*/
        Bitmap bm = Bitmap.createBitmap(webView.getMeasuredWidth(),
                singleHeight * CROP_PAGE, Bitmap.Config.RGB_565);

        Canvas bigcanvas = new Canvas(bm);
        Paint paint = new Paint();
        int iHeight = bm.getHeight();
        bigcanvas.drawBitmap(bm, 0, iHeight, paint);
        webView.draw(bigcanvas);
        return bm;
    }

    /**
     * 图片加载成功
     */
    @Override
    public void onSuccess() {

    }

    /**
     * 图片加载失败
     *
     * @param e
     */
    @Override
    public void onError(Throwable e) {
        Toast.makeText(this, "An error occurred while intercepting the image.", Toast.LENGTH_SHORT).show();
    }

    /**
     * 按钮点击事件
     *
     * @param view
     */
    @Override
    public void onClick(View view) {
        if (view == yes && mCropUri != null) {
            mCropImageView.crop(mCropUri)
                    .execute(new CropCallback() {
                        @Override
                        public void onSuccess(final Bitmap cropped) {
                            if (isSetHeight) {
                                isSetHeight = false;
                                all(findViewById(R.id.main).getHeight(), mWebView, cropped.getHeight(), 0);
                                mCropImageView.setVisibility(View.GONE);
                                btnCrop.setVisibility(View.GONE);
                                mWebView.postDelayed(new Runnable() {
                                    @Override
                                    public void run() {
                                        // result.setImageBitmap(CROP_RESULT_BITMAP = captureScreenforRecord(DisplayActivity.this, mWebView, cropped.getHeight()));
                                        result.setImageBitmap(CROP_RESULT_BITMAP);
                                        result.setVisibility(View.VISIBLE);
                                        finish();
                                    }
                                }, DURATION * (CROP_PAGE + 2));
                            } else {
                                crop.setVisible(false);
                                back.setVisible(true);
                                // 隐藏裁剪控件
                                mCropImageView.setVisibility(View.GONE);
                                btnCrop.setVisibility(View.GONE);
                                // 隐藏文件浏览控件
                                mWebView.setVisibility(View.GONE);
                                // 展示并记录裁剪结果
                                result.setImageBitmap(CROP_RESULT_BITMAP = cropped);
                                result.setVisibility(View.VISIBLE);
                                finish();
                            }
                        }

                        @Override
                        public void onError(Throwable e) {
                            mCropImageView.setVisibility(View.GONE);
                            btnCrop.setVisibility(View.GONE);
                            Toast.makeText(DisplayActivity.this, "An error occurred cutting the image.", Toast.LENGTH_SHORT).show();
                        }
                    });
        } else {
            // Uri置null
            mCropUri = null;
            // 隐藏裁剪控件
            mCropImageView.setVisibility(View.GONE);
            btnCrop.setVisibility(View.GONE);
        }
    }
}
