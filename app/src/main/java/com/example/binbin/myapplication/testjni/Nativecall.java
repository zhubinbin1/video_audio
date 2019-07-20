package com.example.binbin.myapplication.testjni;

import android.support.annotation.Keep;
import android.util.Log;

import com.example.binbin.myapplication.testjni.model.CppBean;
import com.example.binbin.myapplication.testjni.model.Person;

/**
 * Created by binbin on 2018/3/17.
 *
 */

public class Nativecall {

    public native String getStringFromJNI();
    public native String changeStr(String str);
    public native int[] parseIntArray(int[] i);
    public native void passData(CppBean bean);
    public native void callCpp();



    //c++调用java的函数==>callCpp
    @Keep
    public void printFromC(int sec) {
        Log.i("Nativecall", "CPP调用java代码成功====hello from c after " + sec + "s");

    }

    public native int getIntFromJNI();
    public native boolean getBoolFromJNI();
    public native void getVoidFromJNI();
    public native void setPerson(Person p);
    public String getStringToNative(){
        return "this is string2FromJNI()";
    }
}
