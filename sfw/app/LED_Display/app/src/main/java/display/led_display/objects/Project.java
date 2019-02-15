package display.led_display.objects;

public class Project {
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
