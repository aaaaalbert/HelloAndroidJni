#include <jni.h>
#include <stdio.h>
#include <unistd.h>
#include <android/log.h>

# define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, __FILE__, __VA_ARGS__))

/*
 * This function should be called when the Java code does
 * `System.loadLibrary()`.
 * See https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/invocation.html#JNI_OnLoad
*/
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("Look Ma and Pa, I'm writing to the Android log!");
    return JNI_VERSION_1_6;
}


JNIEXPORT jstring JNICALL
Java_com_example_aaaaa_helloandroidjni_MainActivity_getMsgFromJni(JNIEnv *env,
                                                                  jobject instance)
{
    jclass main_activity_class;
    jmethodID accelgetter;
    float anacceleration;
    char floatinstring[16];
    size_t size = 256;
    char current_working_dir[size];

    LOGI("Blix Blypsilon %s", getcwd(current_working_dir, size));


    main_activity_class = (*env)->FindClass(env,
            "com/example/aaaaa/helloandroidjni/MainActivity");

    accelgetter = (*env)->GetStaticMethodID(env, main_activity_class,
            "getAccelValue", "()F");

    anacceleration = (*env)->CallStaticFloatMethod(env, main_activity_class, accelgetter);



    LOGI("Acceleration!!!! It's %f", anacceleration);

    sprintf(floatinstring, "%f", anacceleration);
    return (*env)->NewStringUTF(env, floatinstring);
}
