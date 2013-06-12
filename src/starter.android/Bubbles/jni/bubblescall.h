
#pragma once

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeInit(JNIEnv * env, jobject jobj, jint iWidth, jint iHeight);
JNIEXPORT void JNICALL Java_com_voksoft_bubbles_NativeCaller_nativeUpdate(JNIEnv * env, jobject jobj);


#ifdef __cplusplus
}
#endif
#endif



