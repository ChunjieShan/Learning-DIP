//
// Created by 单淳劼 on 2022/3/11.
//

#include <opencv2/opencv.hpp>
#include <iostream>
#include "canny.h"

int main()
{
    cv::Mat img = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);
//    std::cout << img.rows << " " << img.cols << std::endl;
    cv::Mat gaussDst;
//    GaussianFilter gaussianFilter(3, 0.8);
//    gaussianFilter.calcGaussFilter(img, dst);

    Canny canny(img, gaussDst);
//    canny.calcGaussFilter(img, gaussDst);
////    std::cout << gaussDst.rows << " " << gaussDst.cols << std::endl;
//
//    cv::Mat sobelDst;
//    canny.calcSobelFilter(gaussDst, sobelDst);
//    canny.getDirection();

    return 0;
}