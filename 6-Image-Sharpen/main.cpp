//
// Created by 单淳劼 on 2022/3/9.
//

#include "sharpen.h"

int main()
{
    cv::Mat img = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;
    Sharpen sharpen(img, dst);
    return 0;
}