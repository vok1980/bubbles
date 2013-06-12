package com.voksoft.bubbles;


public class NativeCaller 
{
	static 
	{
		System.loadLibrary("gnustl_shared");
	    System.loadLibrary("bubbles");
	}
    
    public static native void Init(long iWidth, long iHeight);
    public static native void Update();
    public static native void OnClick(long iPosX, long iPosY);

}
