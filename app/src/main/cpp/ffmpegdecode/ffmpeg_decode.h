//
// Created by binbin on 2018/3/31.
//
#include <jni.h>"
#ifndef MYAPPLICATION_FFMPEG_DECODE_H
#define MYAPPLICATION_FFMPEG_DECODE_H
#ifdef __cplusplus
extern "C"{
#endif
JNIEXPORT jint JNICALL
Java_com_example_binbin_myapplication_ffmpegandroiddecoder_MainActivity_decode(JNIEnv *env,
                                                                               jobject instance,
                                                                               jstring inputurl_,
                                                                               jstring outputurl_);

JNIEXPORT jstring JNICALL
Java_com_example_binbin_myapplication_ffmpegandroiddecoder_MainActivity_avcodecinfo(JNIEnv *env,
                                                                                    jobject instance);

#ifdef  __cplusplus
}
#endif

#endif //MYAPPLICATION_FFMPEG_DECODE_H
