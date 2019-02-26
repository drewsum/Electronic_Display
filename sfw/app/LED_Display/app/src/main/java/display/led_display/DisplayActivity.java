package display.led_display;

import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.webkit.WebView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.isseiaoki.simplecropview.CropImageView;
import com.isseiaoki.simplecropview.callback.CropCallback;
import com.isseiaoki.simplecropview.callback.LoadCallback;
import com.jiang.geo.R;

import java.io.File;

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

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
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
        mWebView.getSettings().setUseWideViewPort(true);
        mWebView.getSettings().setJavaScriptEnabled(true);
        mWebView.loadUrl(getIntent().getStringExtra("path"));
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
        return super.onOptionsItemSelected(item);
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
                        public void onSuccess(Bitmap cropped) {
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
