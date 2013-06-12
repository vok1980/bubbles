 
#include "bubblescall.h"

#include "game.h"


CGame& GetGame(void)
{
	static CGame game;
	return game;
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeInit(JNIEnv * env, jobject jobj, jlong iWidth, jlong iHeight)
{
	GetGame().Init((long)iWidth, (long)iHeight);
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeUpdate(JNIEnv * env, jobject jobj)
{
	GetGame().OnGameLoopTick(0.1); ///<\todo: update time
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeOnClick(JNIEnv * env, jobject jobj, jlong iPosX, jlong iPosY)
{
	SPoint point = {(long)iPosX, (long)iPosY};
	GetGame().OnMouseClick( point );
}

