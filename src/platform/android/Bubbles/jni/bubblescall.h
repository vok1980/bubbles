
#pragma once

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif


     //                       com/voksoft/bubbles/NativeCaller;.Init:(JJ)
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_Init(JNIEnv * env, jobject jobj, jlong iWidth, jlong iHeight);
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_Update(JNIEnv * env, jobject jobj);
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_OnClick(JNIEnv * env, jobject jobj, jlong iPosX, jlong iPosY);


#ifdef __cplusplus
}
#endif




