//
// Created by 单淳劼 on 2022/3/7.
//

#include "gaussian_filter.h"

int main()
{
    GaussianFilter gFilter(3, 0.8);

    cv::Mat img = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;

    gFilter.calcGaussFilter(img, dst);

    cv::imwrite("../result_3.png", dst);

    return 0;
}

