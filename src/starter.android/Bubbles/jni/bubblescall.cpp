
#include <android/log.h>

#include "bubblescall.h"

#include "platformGL.h"
#include "game.h"


#define  LOG_TAG    "bubbles"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
    LOGI("GL %s = %s\n", name, v);
}


CGame& GetGame(void)
{
	static CGame game;
	return game;
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_Init(JNIEnv * env, jobject jobj, jlong iWidth, jlong iHeight)
{
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    glViewport(0, 0, iWidth, iHeight);
//    checkGlError("glViewport");

	GetGame().Init((long)iWidth, (long)iHeight);
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_Update(JNIEnv * env, jobject jobj)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
///	checkGlError("glClearColor");
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
//	checkGlError("glClear");

	GetGame().OnGameLoopTick(0.03); ///<\todo: update time correctly
}


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_OnClick(JNIEnv * env, jobject jobj, jlong iPosX, jlong iPosY)
{
	SPoint point = {(long)iPosX, (long)iPosY};
	GetGame().OnMouseClick( point );
}

