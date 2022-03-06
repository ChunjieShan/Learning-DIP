//
// Created by 单淳劼 on 2022/3/6.
//

#ifndef EQUAL_HIST_BACK_PROJECTION_H
#define EQUAL_HIST_BACK_PROJECTION_H

#include <opencv2/opencv.hpp>
#include <iostream>
#include "histogram.h"

class BackProjection
{
public:
    BackProjection(cv::Mat& image, cv::Mat& modelImg);
    int calcBackProject();

private:
    std::vector<int> mHistogram;
    std::vector<int> mModelHistogram;

    cv::Mat mImg;
    cv::Mat mModelImg;
    cv::Mat mResultImg;
};


#endif //EQUAL_HIST_BACK_PROJECTION_H
