package com.example.binbin.myapplication.playffmpeg

import android.app.Activity
import android.os.Bundle
import android.view.Surface
import android.view.SurfaceHolder
import android.view.SurfaceView
import com.example.binbin.myapplication.R

class MainPalyFfmpegActivity : Activity() ,SurfaceHolder.Callback {


    var surfaceView:SurfaceView ?=null
    var surfaceHolder:SurfaceHolder?=null
    var fileName :String =""
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main_paly_ffmpeg)
        surfaceView = findViewById(R.id.surface_view)
        surfaceHolder = surfaceView?.holder
    }
    override fun surfaceChanged(holder: SurfaceHolder?, format: Int, width: Int, height: Int) {
        //To change body of created functions use File | Settings | File Templates.
    }

    override fun surfaceDestroyed(holder: SurfaceHolder?) {
        //To change body of created functions use File | Settings | File Templates.
    }

    override fun surfaceCreated(holder: SurfaceHolder?) {
        //To change body of created functions use File | Settings | File Templates.
        Thread(Runnable { kotlin.run {
            surfaceHolder?.surface?.let { VideoPlayer.play(it,fileName) }
        } }).start()
    }
}
