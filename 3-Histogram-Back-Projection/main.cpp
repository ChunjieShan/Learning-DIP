//
// Created by 单淳劼 on 2022/3/6.
//

#include "back_projection.h"

int main()
{
    cv::Mat src = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);
    cv::Mat model = cv::imread("../model.png", cv::IMREAD_GRAYSCALE);

//    std::cout << model << std::endl;

    BackProjection backProjection(src, model);
    backProjection.calcBackProject();

    return 0;
}
