//
// Created by 单淳劼 on 2022/3/5.
//

#ifndef LEARNING_DIP_HISTOGRAM_H
#define LEARNING_DIP_HISTOGRAM_H
#include "opencv2/opencv.hpp"


class Histogram
{
public:
    Histogram();
    int calcGrayHist(cv::Mat& img);
    cv::Mat getHistogram() { return mVisHistogram; };

private:
    std::vector<int> mHistogram;
    cv::Mat mVisHistogram;

    int visGrayHist();
};


#endif //LEARNING_DIP_HISTOGRAM_H
