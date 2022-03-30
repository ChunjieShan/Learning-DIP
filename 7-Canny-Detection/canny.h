//
// Created by 单淳劼 on 2022/3/11.
//

#ifndef CANNY_CANNY_H
#define CANNY_CANNY_H

#include "gaussian_filter.h"
#include "sobel.h"

class Canny
{
public:
    Canny(cv::Mat& src, cv::Mat& dst);
    int calcGaussFilter(cv::Mat& src, cv::Mat& dst);
    int calcSobelFilter(cv::Mat& src, cv::Mat& dst);
    int getDirection(cv::Mat& sobelGxMat, cv::Mat& sobelGyMat);
    int localNMS(cv::Mat& src, cv::Mat& dst);
    int doubleThreshLink(cv::Mat& src, cv::Mat& dst, float highThresh, float lowThresh);
    int calcCannyBorder(cv::Mat& src, cv::Mat dst, float highThresh, float lowThresh);

private:
    GaussianFilter mGaussianFilter;
    Sobel mSobel;
    std::vector<float> mDirection;
    cv::Mat mSrc;
    cv::Mat mDst;

};


#endif //CANNY_CANNY_H
