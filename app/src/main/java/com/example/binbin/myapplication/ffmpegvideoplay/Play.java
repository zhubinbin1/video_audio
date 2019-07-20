package com.example.binbin.myapplication.ffmpegvideoplay;

import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

/**
 * Created by LC on 2017/11/20.
 */

public class Play implements SurfaceHolder.Callback {
    static {
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avutil-55");
//        System.loadLibrary("postproc-53");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
        System.loadLibrary("ffmpeg_jni");

//        System.loadLibrary("avcodec-56");
//        System.loadLibrary("avdevice-56");
//        System.loadLibrary("avfilter-5");
//        System.loadLibrary("avformat-56");
//        System.loadLibrary("avutil-54");
//        System.loadLibrary("postproc-53");
//        System.loadLibrary("swresample-1");
//        System.loadLibrary("swscale-3");
//        System.loadLibrary("ffmpeg_jni");

    }

    private SurfaceView surfaceView;

    public void playJava(String path) {
        if (surfaceView == null) {
            return;
        }
        play(path);
    }

    public void setSurfaceView(SurfaceView surfaceView) {
        this.surfaceView = surfaceView;
        display(surfaceView.getHolder().getSurface());
        surfaceView.getHolder().addCallback(this);

    }

    public native int play(String path);

    public native void display(Surface surface);


    public native void release();

    public native void stop();

    public native int getTotalTime();

    public native double getCurrentPosition();

    public native void seekTo(int msec);

    public native void stepBack();//快退

    public native void stepUp();//快进


    @Override
    public void surfaceCreated(SurfaceHolder surfaceHolder) {

    }

    @Override
    public void surfaceChanged(SurfaceHolder surfaceHolder, int i, int i1, int i2) {
        display(surfaceHolder.getSurface());
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder surfaceHolder) {

    }
}
