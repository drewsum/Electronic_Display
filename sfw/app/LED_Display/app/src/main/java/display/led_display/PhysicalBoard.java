package display.led_display;

import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;

@Entity
public class PhysicalBoard {
    @PrimaryKey(autoGenerate = true)
    public int physicalboardId;

    public String boardName;
    //public int[] ipAddress;
    public int portNumber;
    public int pinNumber;
}
