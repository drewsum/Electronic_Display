package display.led_display;

import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;
import java.security.Timestamp;
import java.util.List;

@Entity
public class Project {
    @PrimaryKey(autoGenerate = true)
    public int projectId;

    public String projectName;
    //public Timestamp changeDate;
    public enum projectTypes {
        CUSTOM,
        POWERPOINT
    };
    //public List<Frame> frameList;
    public String getProjectName() {
        return projectName;
    }

    public void setProjectName(String projectName) {
        this.projectName = projectName;
    }

}
