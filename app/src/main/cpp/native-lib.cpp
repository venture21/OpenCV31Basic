#include "module.h"

extern "C" {

    JNIEXPORT jint JNICALL
    Java_com_venture_android_opencvbasic_MainActivity_convertNativeLib(JNIEnv*, jobject, jlong addrInput, jlong addrResult) {

        Mat &img_input = *(Mat *) addrInput;
        Mat &img_result = *(Mat *) addrResult;

        int conv = process(img_input, img_result);
        int ret = (jint) conv;
        return ret;
    }
}


