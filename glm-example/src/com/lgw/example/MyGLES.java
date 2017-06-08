package com.lgw.example;

import android.util.Log;
import android.view.View;
import android.app.Activity;

public class MyGLES extends android.app.NativeActivity
{
	static
	{
		System.loadLibrary( "lgw-gles" );
	}
	
	@Override 
	public void onWindowFocusChanged (boolean hasFocus)
	{
		if(hasFocus) 
		{
			getWindow().getDecorView().setSystemUiVisibility(
					View.SYSTEM_UI_FLAG_LAYOUT_STABLE
					| View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
					| View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
					| View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
					| View.SYSTEM_UI_FLAG_FULLSCREEN
					| View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);
		}
	}
}
