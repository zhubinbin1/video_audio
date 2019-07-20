//
// Created by binbin on 2018/4/2.
//

#ifndef MYAPPLICATION_NATIVE_LIB_H
#define MYAPPLICATION_NATIVE_LIB_H
#include <jni.h>
#include <string>
#include <android/log.h>
#define  LOG_TAG   "testJni"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getStringFromJNI(JNIEnv *env, jobject instance);


JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_callCpp(JNIEnv *env,jobject instance);
JNIEXPORT jstring JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_changeStr(JNIEnv *env, jobject instance,
                                                                   jstring str_);



JNIEXPORT jintArray JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_parseIntArray(JNIEnv *env,jobject instance,jintArray i_);

extern void call_printFromC(int sec);//回调函数


JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_passData(JNIEnv *env, jobject instance,
                                                                  jobject bean);






JNIEXPORT jint JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getIntFromJNI(JNIEnv *env, jobject instance);
JNIEXPORT jboolean JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getBoolFromJNI(JNIEnv *env, jobject instance);
JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getVoidFromJNI(JNIEnv *env, jobject instance);

JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_setPerson(JNIEnv *env, jobject instance,
        jobject p) ;
#ifdef __cplusplus
}
#endif
#endif //MYAPPLICATION_NATIVE_LIB_H
