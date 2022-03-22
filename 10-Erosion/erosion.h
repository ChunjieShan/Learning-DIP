//
// Created by 单淳劼 on 2022/3/22.
//

#ifndef LEARNINGDIP_EROSION_H
#define LEARNINGDIP_EROSION_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Erosion
{
public:
    Erosion(cv::Size kernelSize);
    int erode(cv::Mat& src, cv::Mat& dst);

private:
    cv::Size mKernelSize;
    cv::Mat mSE;

};


#endif // LEARNINGDIP_EROSION_H
