package com.example.binbin.myapplication.playffmpeg

/**
 * Created by binbin on 2018/3/31.
 */
object VideoPlayer {

    init {
        System.loadLibrary("VideoPlayer")
    }

    external fun play(surface: Any,fileName: String): Int
}