
#pragma once

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeInit(JNIEnv * env, jobject jobj, jlong iWidth, jlong iHeight);
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeUpdate(JNIEnv * env, jobject jobj);
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeOnClick(JNIEnv * env, jobject jobj, jlong iPosX, jlong iPosY);


#ifdef __cplusplus
}
#endif




