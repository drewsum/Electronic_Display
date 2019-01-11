package display.led_display;

import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

@Dao
public interface PhysicalBoardDao {

    @Insert
    void insert(PhysicalBoard... physicalBoard);

    @Update
    void update(PhysicalBoard... physicalBoard);

    @Delete
    void delete(PhysicalBoard... physicalBoard);

    @Query("Select * FROM physicalBoard")
    PhysicalBoard[] loadAll();
}