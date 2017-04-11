#include "module.h"

int process(Mat img_input, Mat &img_result)
{
    Mat temp;
    cvtColor( img_input, temp, CV_RGBA2GRAY);
    adaptiveThreshold(temp,img_result,255,ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 21,5);

    return(0);
}