//
// Created by 单淳劼 on 2022/3/9.
//

#ifndef SOBEL_SHARPEN_H
#define SOBEL_SHARPEN_H

#include <iostream>
#include <opencv2/opencv.hpp>

class Sharpen
{
public:
    Sharpen(cv::Mat& img, cv::Mat& dst);
    int calcSharpen(cv::Mat& src, cv::Mat& dst);

private:
    cv::Mat mKernel;
    cv::Mat mSrc;
};


#endif //SOBEL_SHARPEN_H
