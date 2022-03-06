//
// Created by 单淳劼 on 2022/3/5.
//

#ifndef LEARNING_DIP_EQUAL_HIST_H
#define LEARNING_DIP_EQUAL_HIST_H

#endif //LEARNING_DIP_EQUAL_HIST_H

#include <opencv2/opencv.hpp>
#include <iostream>

class EqualHist
{
public:
    EqualHist(std::vector<int>& vHistogram, int width, int height);
    int equalizeHist();

private:
    int mWidth;
    int mHeight;
    std::vector<int> mHistogram;
    std::vector<float> mEqualHistogram;
};