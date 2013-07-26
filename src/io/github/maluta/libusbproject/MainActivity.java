package io.github.maluta.libusbproject;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;
import android.widget.EditText;
import io.github.maluta.libusbproject.R;

public class MainActivity extends Activity {
	private static final String TAG = null;
	private NativeLib nativeLib = new NativeLib();
	private EditText t;
	private String usb_devices;

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);

		usb_devices = nativeLib.listDevices();
		t = (EditText) findViewById(R.id.editText1);
		t.setText(usb_devices);

	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

}
