package display.led_display;

import android.arch.persistence.room.Database;
import android.arch.persistence.room.Room;
import android.arch.persistence.room.RoomDatabase;
import android.content.Context;

@Database(entities = {Project.class, Frame.class, PhysicalBoard.class}, version = 1, exportSchema = false)
public abstract class AppDataBase extends RoomDatabase {

    private static AppDataBase instance;


    public abstract ProjectDao projectDao();
    public abstract FrameDao frameDao();
    public abstract PhysicalBoardDao physicalboardDao();


    public static AppDataBase getAppDatabase(Context context) {
        if (instance == null) {
            instance = Room.databaseBuilder(context.getApplicationContext(),
                    AppDataBase.class,
                    "cat-owners-db")
                    .allowMainThreadQueries()
                    .build();
        }
        return instance;
    }
}
