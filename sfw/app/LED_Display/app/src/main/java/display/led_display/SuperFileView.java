package display.led_display;

import android.app.ProgressDialog;
import android.content.Context;
import android.os.Bundle;
import android.os.Environment;
import android.text.TextUtils;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.tencent.smtt.sdk.TbsReaderView;

import java.io.File;

/**
 * SuperFileView，内部使用TBS的TbsReaderView展示文件
 */
public class SuperFileView extends FrameLayout implements TbsReaderView.ReaderCallback {

    // TbsReaderView
    private TbsReaderView mTbsReaderView;
    // 上下文对象
    private Context context;
    // 加载框
    private ProgressDialog mProgressDialog;

    /**
     * 构造器
     *
     * @param context
     */
    public SuperFileView(Context context) {
        this(context, null, 0);
    }

    /**
     * 构造器
     *
     * @param context
     * @param attrs
     */
    public SuperFileView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    /**
     * 构造器
     *
     * @param context
     * @param attrs
     * @param defStyleAttr
     */
    public SuperFileView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        // 初始化创建TbsReaderView
        mTbsReaderView = new TbsReaderView(context, this);
        mProgressDialog = new ProgressDialog(context);
        mProgressDialog.setMessage("Parsing file ... ");
        // 将TbsReaderView添加到该容器布局
        this.addView(mTbsReaderView, new LinearLayout.LayoutParams(-1, -1));
        this.context = context;
    }

    // 获取文件路径的监听
    private OnGetFilePathListener mOnGetFilePathListener;

    // 提供设置OnGetFilePathListener的方法
    public void setOnGetFilePathListener(OnGetFilePathListener mOnGetFilePathListener) {
        this.mOnGetFilePathListener = mOnGetFilePathListener;
    }

    // 生成TbsReaderView的方法
    private TbsReaderView getTbsReaderView(Context context) {
        return new TbsReaderView(context, this);
    }

    // 展示文件
    public void displayFile(File mFile) {
        if (mFile != null && !TextUtils.isEmpty(mFile.toString())) {
            mProgressDialog.show();
            mTbsReaderView.setVisibility(INVISIBLE);
            // 增加下面一句解决没有TbsReaderTemp文件夹存在导致加载文件失败
            String bsReaderTemp = "/storage/emulated/0/TbsReaderTemp";
            File bsReaderTempFile = new File(bsReaderTemp);
            if (!bsReaderTempFile.exists()) {
                boolean mkdir = bsReaderTempFile.mkdir();
                if (!mkdir) {
                    // Toast.makeText(context, "Create /storage/emulated/0/TbsReaderTemp failed.", Toast.LENGTH_SHORT).show();
                }
            }
            // 加载文件
            Bundle localBundle = new Bundle();
            localBundle.putString("filePath", mFile.toString());
            localBundle.putString("tempPath", Environment.getExternalStorageDirectory() + "/" + "TbsReaderTemp");
            if (this.mTbsReaderView == null)
                this.mTbsReaderView = getTbsReaderView(context);
            boolean bool = this.mTbsReaderView.preOpen(getFileType(mFile.toString()), false);
            if (bool) {
                // 打开文件
                this.mTbsReaderView.openFile(localBundle);
            }
        } else {
            // Toast.makeText(context, "Invalid file path.", Toast.LENGTH_SHORT).show();
        }
        // 隐藏"放映"按钮
        hideViews();
    }

    /**
     * 隐藏"放映"按钮
     */
    private void hideViews() {
        postDelayed(new Runnable() {
            @Override
            public void run() {
                View v1 = getTargetView(SuperFileView.this, "放映");
                View v2 = getTargetView(SuperFileView.this, "文件");
                if (v1 != null) v1.setVisibility(GONE);
                if (v2 != null) v2.setVisibility(GONE);
                mTbsReaderView.setVisibility(VISIBLE);
                mProgressDialog.dismiss();
            }
        }, 3000L);
    }

    /**
     * 隐藏"1/8"按钮
     */
    public void hideCountView() {
        View v1 = getTargetView(SuperFileView.this, "/");
        if (v1 != null) v1.setVisibility(GONE);
    }

    /**
     * 遍历获取按钮
     *
     * @return
     */
    private View getTargetView(View root, String text) {
        if (root == null || TextUtils.isEmpty(text)) {
            return null;
        }
        if (root instanceof ViewGroup) {
            ViewGroup group = (ViewGroup) root;
            int childCount = group.getChildCount();
            for (int i = 0; i < childCount; i++) {
                View result = getTargetView(group.getChildAt(i), text);
                if (result != null) {
                    return result;
                }
            }
        } else if (root instanceof TextView) {
            TextView textView = (TextView) root;
            if (textView.getText().toString().indexOf(text) != -1) {
                return textView;
            }
        }
        return null;
    }

    /***
     * 获取文件类型
     *
     * @param paramString
     * @return
     */
    private String getFileType(String paramString) {
        String str = "";

        if (TextUtils.isEmpty(paramString)) {
            return str;
        }
        int i = paramString.lastIndexOf('.');
        if (i <= -1) {
            return str;
        }


        str = paramString.substring(i + 1);
        return str;
    }

    /**
     * 开始展示文件
     */
    public void show() {
        if (mOnGetFilePathListener != null) {
            mOnGetFilePathListener.onGetFilePath(this);
        }
    }

    /***
     * 将获取File路径的工作，“外包”出去
     */
    public interface OnGetFilePathListener {
        void onGetFilePath(SuperFileView mSuperFileView);
    }


    @Override
    public void onCallBackAction(Integer integer, Object o, Object o1) {
    }

    /**
     * 停止
     */
    public void onStopDisplay() {
        if (mTbsReaderView != null) {
            mTbsReaderView.onStop();
        }
    }
}
