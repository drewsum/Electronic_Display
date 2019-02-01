package display.led_display.objects;

public class Frame {
    public int frameId;

    public enum frameType {
        Image,
        Text
    };
    public byte[] frameData;
}
