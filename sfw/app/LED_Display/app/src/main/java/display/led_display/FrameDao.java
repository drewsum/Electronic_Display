package display.led_display;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

@Dao
public interface FrameDao {

    @Insert
    void insert(Frame... frame);

    @Update
    void update(Frame... frame);

    @Delete
    void delete(Frame... frame);

    @Query("Select * FROM frame")
    Frame[] loadAll();
}