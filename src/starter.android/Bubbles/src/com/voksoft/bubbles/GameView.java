package com.voksoft.bubbles;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;



public class GameView extends GLSurfaceView 
{
	public GameView(Context context) 
	{
		super(context);
		setRenderer(new Renderer());
	}
	
	
	private static class Renderer implements GLSurfaceView.Renderer 
	{
        public void onDrawFrame(GL10 gl) 
        {
        	NativeCaller.Update();
        }

        public void onSurfaceChanged(GL10 gl, int width, int height) 
        {
        	NativeCaller.Init(width, height);
        }

        public void onSurfaceCreated(GL10 gl, EGLConfig config) 
        {
            // Do nothing.
        }
    }

}
