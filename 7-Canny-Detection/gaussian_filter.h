//
// Created by 单淳劼 on 2022/3/7.
//

#ifndef GAUSSIAN_FILTER_GAUSSIAN_FILTER_H
#define GAUSSIAN_FILTER_GAUSSIAN_FILTER_H

#include <opencv2/opencv.hpp>
#include <iostream>

class GaussianFilter
{
public:
    GaussianFilter(int kernelSize, float sigma);
    GaussianFilter(cv::Size kernelSize, float sigma);
    int calcGaussFilter(cv::Mat& src, cv::Mat& dst);

private:
    int genGaussKernel();

    float mSigma;
    cv::Mat mGaussKernel;
};


#endif //GAUSSIAN_FILTER_GAUSSIAN_FILTER_H
