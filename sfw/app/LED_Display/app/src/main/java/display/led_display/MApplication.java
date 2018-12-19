package display.led_display;

import android.app.Application;
import android.os.Environment;

import com.tencent.smtt.sdk.QbSdk;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

/**
 * 全局Application
 */
public class MApplication extends Application {

    public static final String TEST_PPT_FILE = "final_concept.pptx";
    public static final String PPT_CROP_DIR = Environment.getExternalStorageDirectory().getAbsolutePath() + "/ppt_crop/";

    @Override
    public void onCreate() {
        super.onCreate();
        // TBS 初始化
        QbSdk.initX5Environment(this, null);
        File cropDir = new File(PPT_CROP_DIR);
        if(!cropDir.exists()) cropDir.mkdirs();
        copyAssetAndWrite(TEST_PPT_FILE);
    }

    /**
     * 将asset文件写入缓存
     */
    private boolean copyAssetAndWrite(String fileName) {
        try {
            File externalStorage = Environment.getExternalStorageDirectory();
            if (!externalStorage.exists()) {
                externalStorage.mkdirs();
            }
            File outFile = new File(externalStorage, fileName);
            if (!outFile.exists()) {
                boolean res = outFile.createNewFile();
                if (!res) {
                    return false;
                }
            } else {
                if (outFile.length() > 10) {//表示已经写入一次
                    return true;
                }
            }
            InputStream is = getAssets().open(fileName);
            FileOutputStream fos = new FileOutputStream(outFile);
            byte[] buffer = new byte[1024];
            int byteCount;
            while ((byteCount = is.read(buffer)) != -1) {
                fos.write(buffer, 0, byteCount);
            }
            fos.flush();
            is.close();
            fos.close();
            return true;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }

}
