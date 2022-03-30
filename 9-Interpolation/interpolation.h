//
// Created by 单淳劼 on 2022/3/21.
//

#ifndef LEARNINGDIP_INTERPOLATION_H
#define LEARNINGDIP_INTERPOLATION_H

const int NEAREST = 0;
const int BILINEAR = 1;

#include <iostream>
#include <opencv2/opencv.hpp>

class Interp
{
public:
    Interp(int type, int height, int width);
    int interpolate(cv::Mat& src, cv::Mat& dst);

private:
    cv::Mat mSrc;
    int mType;
    int mHeight;
    int mWidth;

    int nearestInterp(cv::Mat& src, cv::Mat& dst);
    int bilinearInterp(cv::Mat& src, cv::Mat& dst);
};


#endif //LEARNINGDIP_INTERPOLATION_H
