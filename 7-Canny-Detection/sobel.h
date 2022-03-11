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
    Sobel(cv::Mat& src, cv::Mat& dst, int gx, int gy, int kernelSize);
    Sobel(int gx, int gy, int kernelSize);
    int calcSobel();
    int calcSobel(cv::Mat& src, cv::Mat& dst);

private:
    cv::Mat mSrc;
    int mGx;
    int mGy;

    cv::Mat mGxFilter;
    cv::Mat mGyFilter;

    cv::Mat mGxResult;
    cv::Mat mGyResult;
    cv::Mat mGxGyResult;
    int mKernelSize;

    int genGxGyKernel();

    int calcGxSobel();
    int calcGySobel();
    int calcGxGySobel();

    cv::Mat getResult();
};


#endif //GAUSSIAN_FILTER_SOBEL_H
