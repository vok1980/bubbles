package com.voksoft.bubbles;

import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.content.Context;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;



public class GameView extends GLSurfaceView 
{
	class Point
	{
		Point(long _x, long _y)
		{
			x = _x;
			y = _y;
		}
		
		long x;
		long y;
	};
	
	private Queue<Point> mTouchPoints = new ConcurrentLinkedQueue<Point>();
	
	public GameView(Context context) 
	{
		super(context);
		setRenderer(new Renderer(mTouchPoints));
	}
	
	@Override
	public boolean onTouchEvent(MotionEvent event) 
	{
		if (MotionEvent.ACTION_DOWN == event.getAction())
		{
//			NativeCaller.OnClick((long)event.getX(), (long)event.getY());
			mTouchPoints.offer(new Point((long)event.getX(), (long)event.getY()));
			return true;
		}
		
		// TODO Auto-generated method stub
		return super.onTouchEvent(event);
	}
	
	
	private static class Renderer implements GLSurfaceView.Renderer 
	{
		final Queue<Point> mTouchPoints;
		
		Renderer( Queue<Point> touchPoints )
		{
			mTouchPoints = touchPoints;			
		}
		
        public void onDrawFrame(GL10 gl) 
        {
        	Point point = null;
        	
        	while ( null != (point = mTouchPoints.poll()) )
        	{        		
        		NativeCaller.OnClick(point.x, point.y);
        	}
        	 
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
