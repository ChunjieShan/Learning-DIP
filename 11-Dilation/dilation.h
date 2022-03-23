//
// Created by 单淳劼 on 2022/3/23.
//

#ifndef DILATION_DILATION_H
#define DILATION_DILATION_H

#include <opencv2/opencv.hpp>

class Dilation
{
public:
    Dilation(cv::Size kSize);
    int dilate(cv::Mat& src, cv::Mat& dst);

private:
    cv::Size m_kSize;

};


#endif //DILATION_DILATION_H
