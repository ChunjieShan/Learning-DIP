//
// Created by 单淳劼 on 2022/3/8.
//

#ifndef GAUSSIAN_FILTER_SOBEL_H
#define GAUSSIAN_FILTER_SOBEL_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Sobel
{
public:
    Sobel(cv::Mat& src, int gx, int gy, int kernelSize);

private:
    cv::Mat mSrc;
    int mGx;
    int mGy;

    cv::Mat mGxFilter;
    cv::Mat mGyFilter;

    cv::Mat mGxResult;
    cv::Mat mGyResult;
    int mKernelSize;

    int genGxGyKernel();
    int calcSobel();
};


#endif //GAUSSIAN_FILTER_SOBEL_H
