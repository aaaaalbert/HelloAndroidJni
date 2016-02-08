#include <jni.h>
#include <stdio.h>
#include "/home/aaaaa/devel/android-ndk-r10e/platforms/android-21/arch-arm/usr/include/android/log.h"

//# define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, __FILE__, __VA_ARGS__))

JNIEXPORT jstring JNICALL
Java_com_example_aaaaa_helloandroidjni_MainActivity_getMsgFromJni(JNIEnv *env,
                                                                  jobject instance)
{
    jclass main_activity_class;
    jmethodID accelgetter;
    float anacceleration;
    char floatinstring[16];

    main_activity_class = (*env)->FindClass(env,
            "com/example/aaaaa/helloandroidjni/MainActivity");

    accelgetter = (*env)->GetStaticMethodID(env, main_activity_class,
            "getAccelValue", "()F");

    anacceleration = (*env)->CallStaticFloatMethod(env, main_activity_class, accelgetter);



    //LOGI("Acceleration!!!! It's %f", anacceleration);

    sprintf(floatinstring, "%f", anacceleration);
    return (*env)->NewStringUTF(env, floatinstring);
}