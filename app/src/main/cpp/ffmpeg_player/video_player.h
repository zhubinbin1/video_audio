//
// Created by binbin on 2018/3/31.
//

#ifndef MYAPPLICATION_VIDEO_PLAYER_H
#define MYAPPLICATION_VIDEO_PLAYER_H

#include <jni.h>

#ifdef __cplusplus
extern "C"{
#endif
//#/Users/binbin/WORK/WORKSPACE/MyApplication/app/src/main/java/com/example/binbin/myapplication/playffmpeg/VideoPlayer.kt
JNIEXPORT jint JNICALL Java_com_example_binbin_myapplication_playffmpeg_VideoPlayer_play
        (JNIEnv *, jclass, jobject,jstring filename);

#ifdef  __cplusplus
}
#endif

#endif //MYAPPLICATION_VIDEO_PLAYER_H
