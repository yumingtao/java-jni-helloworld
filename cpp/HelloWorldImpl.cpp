#include "jni.h"
#include "com_ymt_HelloWorld.h"
#include "MyFunctions.h"
#include <stdio.h>

JNIEXPORT jstring JNICALL Java_com_ymt_HelloWorld_sayHello(JNIEnv *env, jobject obj, jstring name){
    printf("Java_com_ymt_HelloWorld_sayHello...\n");
    jclass js = env->FindClass("java/lang/String");
    jmethodID mid = env->GetMethodID(js, "concat", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring helloStr = env->NewStringUTF("sayHello, ");
    jstring res = (jstring) env->CallObjectMethod(helloStr, mid, name);

    return res;
}

JNIEXPORT jstring JNICALL Java_com_ymt_HelloWorld_sayHello2(JNIEnv *env, jobject obj, jstring name){
    printf("Java_com_ymt_HelloWorld_sayHello2...\n");
    const char* strName = env->GetStringUTFChars(name, 0);
    string helloStr = sayHello(strName);
    env->ReleaseStringUTFChars(name, strName);
    const char* helloStrChar = helloStr.data();
    jstring hellRtn = env->NewStringUTF(helloStrChar);

    return hellRtn;
}