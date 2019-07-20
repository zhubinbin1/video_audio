package com.example.binbin.myapplication.testjni

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.Toast
import com.example.binbin.myapplication.R
import com.example.binbin.myapplication.R.id.call_cpp_btn
import com.example.binbin.myapplication.R.id.sample_text
import com.example.binbin.myapplication.testjni.model.CppBean
import kotlinx.android.synthetic.main.activity_main_testjni.*


class MainActivity : AppCompatActivity() {
    var nativecall : Nativecall? =null
    private  val TAG = "MainActivity";

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main_testjni)
        nativecall = Nativecall()
        // Example of a call to a native method
        Log.e(TAG,nativecall?.changeStr("good"))
        passDate()
       val arr =  nativecall?.parseIntArray(intArrayOf(1,2,3))
//        Log.e(TAG,""+"")
        sample_text.text = nativecall?.stringFromJNI
        call_cpp_btn.setOnClickListener {

            Toast.makeText(this@MainActivity,"callCpp",Toast.LENGTH_LONG).show()
            Thread(Runnable { kotlin.run {
                nativecall?.callCpp()
            } }).start()
        }
    }

//    /**
//     * A native method that is implemented by the 'native-lib' native library,
//     * which is packaged with this application.
//     */
//    external fun stringFromJNI(): String
//    external fun ObjectFromJNI(): Person
//    external fun string2FromJNI(): String
    fun passDate(){
        val bean = CppBean()
        CppBean.jbInt = 11
        bean.jbBool = true
        bean.jbByte= 22
        bean.jbShort = 33
        bean.jbLong = 30000000000L
        bean.jbFloat = 12.34f
        bean.jbDouble = 56.789
        bean.jbStr = "我是测试代码"
        bean.jbIntArr = intArrayOf(1, 23, 456, 78, 9)
        nativecall?.passData(bean)
    }
    companion object {

        // Used to load the 'native-lib' library on application startup.
        init {
            System.loadLibrary("ffmpeg_jni")
        }
    }
}
