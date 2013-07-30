package com.voksoft.bubbles;


import android.app.Activity;
import android.os.Bundle;


public class BubblesActivity extends Activity 
{
	private GameView mView;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) 
    {
        super.onCreate(savedInstanceState);        
        mView = new GameView(getApplication());
        setContentView(mView);

//        contentView.setOnClickListener(
//        		new View.OnClickListener() 
//		        {
//					@Override
//					public void onClick(View arg0) 
//					{
//						
//					}
//		
//		        }
//        );
    }
    
    
    @Override protected void onPause() 
    {
        super.onPause();
        mView.onPause();
    }

    
    @Override protected void onResume() {
        super.onResume();
        mView.onResume();
    }
  
}
