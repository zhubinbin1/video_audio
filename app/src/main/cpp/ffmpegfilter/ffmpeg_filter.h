//
// Created by binbin on 2018/3/31.
//

#ifndef MYAPPLICATION_FFMPEG_FILTER_H
#define MYAPPLICATION_FFMPEG_FILTER_H

#include <jni.h>


#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_com_example_binbin_myapplication_ffmpegandroidavfilter_MainActivity_play
        (JNIEnv *, jclass, jobject);

#ifdef __cplusplus
}
#endif

#endif //MYAPPLICATION_FFMPEG_FILTER_H
