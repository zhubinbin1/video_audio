package com.example.binbin.myapplication.ffmpegopensles;

import android.Manifest;
import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.example.binbin.myapplication.R;

/**
 * FFmpeg使用OpenSLES播放音乐，能停止
 */
public class MainActivity extends Activity {


    private MusicPlay musicPlay = new MusicPlay();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_opensles);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            requestPermissions(new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE,Manifest.permission.RECORD_AUDIO,Manifest.permission.READ_EXTERNAL_STORAGE}, 5);
        }
    }

    public void play(View view){
        musicPlay.play();
    }

    public void stop(View view){
        musicPlay.stop();
    }


}
