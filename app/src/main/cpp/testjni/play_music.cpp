#include "opensles.h"
#include "CppBean.h"
#include <unistd.h>
//#include "jni.h"

using namespace std;



JNIEXPORT jstring JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getStringFromJNI(JNIEnv *env, jobject instance) {

    // TODO
//av_register_all();
    string hello = "hello world zhubinbin123";
    LOGE("hello world zhubinbin123");
    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jstring JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_changeStr(JNIEnv *env, jobject instance,
                                                                   jstring str_){
    char *str = (char *) env->GetStringUTFChars(str_, 0);//good
    LOGE("this is changeStr:%s",str);

//    04-02 14:14:39.429 E/testJni (28663): this is changeStr===1===str:good,good,str+i:103
//    04-02 14:14:39.429 E/testJni (28663): this is changeStr===1===str:good,ood,str+i:103
//    04-02 14:14:39.429 E/testJni (28663): this is changeStr===1===str:good,od,str+i:103
//    04-02 14:14:39.429 E/testJni (28663): this is changeStr===1===str:good,d,str+i:103
    char *str2= (char *) "sesdfgsdfgsdfg";
    for (int i = 0; i < strlen(str); ++i) {
//        *(str + i) += 1;
        LOGE("this is changeStr===1===str:%s,%s,str+i:%x",str,(str + i),*(str+i));
    }
    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF(str2);
}

JNIEXPORT jintArray JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_parseIntArray(JNIEnv *env,jobject instance,jintArray i_) {
//    LOGE("hello world zhubinbin123");
    // TODO
//    04-02 14:13:10.064 E/testJni (28494): parseIntArray==intArray:-646469840,*intArray:1,*(intArray + i):1
//    04-02 14:13:10.064 E/testJni (28494): parseIntArray==intArray:-646469840,*intArray:1,*(intArray + i):2
//    04-02 14:13:10.065 E/testJni (28494): parseIntArray==intArray:-646469840,*intArray:1,*(intArray + i):3
    jint *intArray = env->GetIntArrayElements(i_, NULL);
    jsize length = env->GetArrayLength(i_);
    for (int i = 0; i < length; ++i) {
        LOGE("parseIntArray==intArray:%d,*intArray:%d,*(intArray + i):%d" ,intArray,*intArray,*(intArray + i));
    }
    env->ReleaseIntArrayElements(i_, intArray, 0);
    return i_;
}

static JavaVM *m_JavaVM;//java虚拟机
static jclass m_jcls_JNI;
//===========CPP call java -----start=================
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *java_vm, void *reserved) {
    m_JavaVM = java_vm;

    JNIEnv *jni_env = 0;

    //获取JavaVM的JNIEnv
    if (m_JavaVM->GetEnv((void **) (&jni_env), JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    jclass jcls_JNI = jni_env->FindClass("com/example/binbin/myapplication/testjni/Nativecall");
    m_jcls_JNI = (jclass) jni_env->NewGlobalRef((jobject) jcls_JNI);//全局变量，方便调用
    return JNI_VERSION_1_4;
}

void call_printFromC(int sec){
    JNIEnv *env;
    m_JavaVM->AttachCurrentThread(&env, NULL);//获取当前线程的JNIEnv
    jmethodID methodID = env->GetMethodID(m_jcls_JNI, "printFromC", "(I)V");
    jobject native_call = env->AllocObject(m_jcls_JNI);//获取实例对象
    env->CallVoidMethod(native_call,methodID,sec);
//    m_JavaVM->DetachCurrentThread();
}
void runTest() {
    int sec = 3;
    ::sleep(sec); // 睡3秒
    call_printFromC(sec);//需要在native-lib.h中声明
}
JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_callCpp(JNIEnv *env,jobject instance) {
        runTest();
}
//===========CPP call java -----end=================


JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_passData(JNIEnv *env, jobject instance,
                                                                  jobject bean) {

    // TODO
    //可通过env->FindClass(“com/example/binbin/myapplication/testjni/model/CppBean”)
//    jclass  cls_bean = env->GetObjectClass(bean);//同下
    jclass  cls_bean = env->FindClass("com/example/binbin/myapplication/testjni/model/CppBean");
    //静态
    jfieldID  jIId = env->GetStaticFieldID(cls_bean,"jbInt","I");
    jint  jbInt = env->GetStaticIntField(cls_bean,jIId);//若是静态，为字节码对象；非静态，为实例对象
    MCppBean.setcpp_int(jbInt);
    //非静态
    jfieldID jBid = env->GetFieldID(cls_bean,"jbBool","Z");
    jboolean  jBool = env->GetBooleanField(bean,jBid);
    MCppBean.setcpp_Bool(jBool);

    jbyte jb_byte = env->GetByteField(bean, env->GetFieldID(cls_bean, "jbByte", "B"));
    MCppBean.setcpp_byte(jb_byte);

    MCppBean.setcpp_short(env->GetShortField(bean, env->GetFieldID(cls_bean, "jbShort", "S")));

    jlong j_long = env->GetLongField(bean, env->GetFieldID(cls_bean, "jbLong", "J"));
    MCppBean.setcpp_long(j_long);

    MCppBean.setcpp_float(env->GetFloatField(bean, env->GetFieldID(cls_bean, "jbFloat", "F")));

    MCppBean.setcpp_double(env->GetDoubleField(bean, env->GetFieldID(cls_bean, "jbDouble", "D")));
    int cppInt = MCppBean.getcpp_int();
    bool cppBool = MCppBean.getcpp_Bool();
    Byte cppByte = MCppBean.getcpp_byte();
    short cppShort = MCppBean.getcpp_short();
    long cppLong = MCppBean.getcpp_long();
    float cppFloat = MCppBean.getcpp_float();
    double cppDouble = MCppBean.getcpp_double();

    LOGE("MCppBean中：int字段值=%d,Bool字段值=%d,Byte字段值=%d,short字段值=%hd,long字段值=%ld,float字段值=%f,double字段值=%lf",
         cppInt, cppBool,cppByte,
         cppShort, cppLong,
         cppFloat,cppDouble );
//LOGE("%d",MCppBean.getc)
    //字符串
    jfieldID ids_str = env->GetFieldID(cls_bean, "jbStr", "Ljava/lang/String;");
    jstring jb_str = (jstring) env->GetObjectField(bean, ids_str);
    if(jb_str){
        char *str = (char *) env->GetStringUTFChars(jb_str, 0);
        MCppBean.setcpp_str(str);
        string cppStr = MCppBean.getcpp_str();
        env->ReleaseStringUTFChars(jb_str, str);
        LOGI("MCppBean中：string字段值=%s",cppStr.c_str() );
    } else{
        LOGI("MCppBean中：string字段值是null" );
    }

//    LOGI("MCppBean中：string字段值=%s",cppStr.c_str() );

    //数组
    jfieldID ids_intArr = env->GetFieldID(cls_bean, "jbIntArr", "[I");
    jintArray jb_intArr = (jintArray) env->GetObjectField(bean, ids_intArr);
    if(jb_intArr){
        jint *intArray = env->GetIntArrayElements(jb_intArr, NULL);
//        env->GetObjectArrayElement(GetObjectArrayElement)
        jsize length = env->GetArrayLength(jb_intArr);
        MCppBean.setcpp_intArr(intArray, length);
        env->ReleaseIntArrayElements(jb_intArr, intArray, 0);
    } else{
        LOGI("MCppBean中：jbIntArr字段值=null" );
    }

//    for (int i = 0; i < length; i++) {
//        LOGI("数组元素%d：%d", i, *(MCppBean.getcpp_intArr() + i));
//    }
}



/*//内部类
jfieldID ids_child = env->GetFieldID(cls_bean, "jb_ChildBean", "Lcom/hecc/jnitest/JNIBean$JNIChildBean;");//内部类用$符号，而不是/符号。
jobject jb_child = env->GetObjectField(bean, ids_child);
jclass cls_child = env->GetObjectClass(jb_child);
jint jcb_int = env->GetIntField(jb_child, env->GetFieldID(cls_child, "jcb_int", "I"));
LOGI("jcb_int=%d", jcb_int);

//类类型数组
jfieldID ids_arr_child = env->GetFieldID(cls_bean, "jb_arr_ChildBean",
                                         "[Lcom/hecc/jnitest/JNIBean$JNIChildBean;");
jobjectArray jb_arr_child = (jobjectArray) env->GetObjectField(bean, ids_arr_child);
jsize size = env->GetArrayLength(jb_arr_child);
for (int i = 0; i < size; ++i) {
jobject jab_child = env->GetObjectArrayElement(jb_arr_child, i);//获取每个数组的元素
jint jacb_int = env->GetIntField(jab_child,
                                 env->GetFieldID(env->GetObjectClass(jab_child), "jcb_int", "I"));
LOGI("jacb_int=%d",jacb_int);
}*/








JNIEXPORT jint JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getIntFromJNI(JNIEnv *env, jobject instance) {

    return 1;

}
JNIEXPORT jboolean JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getBoolFromJNI(JNIEnv *env, jobject instance) {

    // TODO

}
JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_getVoidFromJNI(JNIEnv *env, jobject instance) {

    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_binbin_myapplication_testjni_Nativecall_setPerson(JNIEnv *env, jobject instance,
                                                           jobject p) {

    // TODO
   jclass  j_class = env->GetObjectClass(instance);
    jmethodID  j_methoodId = env->GetMethodID(j_class,"getStringToNative","()Ljava/lang/String");
    env->CallObjectMethod(instance,j_methoodId);

}



