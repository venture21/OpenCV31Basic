#include <jni.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

extern "C" {

int process(Mat img_input, Mat &img_result)
{

    Mat temp;
    cvtColor( img_input, temp, CV_RGBA2GRAY);
    adaptiveThreshold(temp,img_result,255,ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21,5);

    return(0);
}


JNIEXPORT jint JNICALL
Java_com_venture_android_opencvbasic_MainActivity_convertNativeLib(JNIEnv*, jobject, jlong addrInput, jlong addrResult) {

    Mat &img_input = *(Mat *) addrInput;
    Mat &img_result = *(Mat *) addrResult;

    int conv = process(img_input, img_result);
    int ret = (jint) conv;
    return ret;
}


}


