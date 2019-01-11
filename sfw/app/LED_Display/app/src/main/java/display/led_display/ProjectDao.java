package display.led_display;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

@Dao
public interface ProjectDao {

    @Insert
    void insert(Project... project);

    @Update
    void update(Project... project);

    @Delete
    void delete(Project... project);

    @Query("Select * FROM project")
    Project[] loadAll();
}