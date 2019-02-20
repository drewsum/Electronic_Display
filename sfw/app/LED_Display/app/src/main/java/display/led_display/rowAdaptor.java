package display.led_display;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.Button;
import android.widget.TextView;

import java.util.ArrayList;

import display.led_display.helper.TinyDB;

public class rowAdaptor extends BaseAdapter {

    Context context;
    String keyName;
    ArrayList<String> data = new ArrayList<String>();
    private static LayoutInflater inflater = null;

    public rowAdaptor(Context context, ArrayList<String> data, String keyName) {
        // TODO Auto-generated constructor stub
        this.context = context;
        this.data = data;
        this.keyName = keyName;
        inflater = (LayoutInflater) context
                .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        // TODO Auto-generated method stub
        return data.size();
    }

    @Override
    public Object getItem(int position) {
        // TODO Auto-generated method stub
        return data.get(position);
    }

    @Override
    public long getItemId(int position) {
        // TODO Auto-generated method stub
        return position;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        // TODO Auto-generated method stub
        View vi = convertView;
        if (vi == null)
            vi = inflater.inflate(R.layout.row, null);
        final View finView = vi;
        TextView text = (TextView) vi.findViewById(R.id.text);
        text.setText(data.get(position));
        Button buttonDelete = (Button) vi.findViewById(R.id.buttonDelete);
        buttonDelete.setFocusable(false);
        buttonDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                data.remove(position);
                TinyDB tinyDB = new TinyDB(finView.getContext());
                tinyDB.putListString(keyName, data);
                Log.d(keyName, data.toString());
                notifyDataSetChanged();
            }
        });
        return vi;
    }
}