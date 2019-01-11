package display.led_display;

import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;

@Entity
public class Frame {
    @PrimaryKey(autoGenerate = true)
    public int frameId;

    public enum frameType {
        Image,
        Text
    };
    public byte[] frameData;
}
