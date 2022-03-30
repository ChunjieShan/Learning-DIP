//
// Created by 单淳劼 on 2022/3/17.
//

#ifndef CANNY_OTSU_H
#define CANNY_OTSU_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Otsu
{
public:
    Otsu();
    Otsu(cv::Mat& src);
    int calcThresh();

private:
    int calcHistogram();
    int otsuSegment();

    cv::Mat mSrc;
    std::vector<int> mHistTable;
    int mThresh;
};


#endif //CANNY_OTSU_H
