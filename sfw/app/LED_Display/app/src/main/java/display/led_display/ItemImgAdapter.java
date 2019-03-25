package display.led_display;

import java.util.ArrayList;
import java.util.List;

import android.content.Context;
import android.graphics.Bitmap;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;

import com.jiang.geo.R;

public class ItemImgAdapter extends BaseAdapter {

    private List<Bitmap> objects = new ArrayList<>();

    private Context context;
    private LayoutInflater layoutInflater;

    public ItemImgAdapter(Context context, List<Bitmap> bitmaps) {
        this.context = context;
        this.layoutInflater = LayoutInflater.from(context);
        this.objects = bitmaps;
        notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return objects.size();
    }

    @Override
    public Bitmap getItem(int position) {
        return objects.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        if (convertView == null) {
            convertView = layoutInflater.inflate(R.layout.item_img, null);
            convertView.setTag(new ViewHolder(convertView));
        }
        initializeViews(getItem(position), (ViewHolder) convertView.getTag());
        return convertView;
    }

    private void initializeViews(Bitmap object, ViewHolder holder) {
        holder.img.setImageBitmap(object);
    }

    protected class ViewHolder {
        private ImageView img;

        public ViewHolder(View view) {
            img = (ImageView) view.findViewById(R.id.img);
        }
    }
}
