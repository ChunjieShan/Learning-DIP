//
// Created by 单淳劼 on 2022/3/21.
//

#include "interpolation.h"

int main()
{
    cv::Mat img = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);
    Interp interp(BILINEAR, 1200, 1200);
    cv::Mat dst;

    interp.interpolate(img, dst);
    cv::imwrite("../result_bilinear.png", dst);

    return 0;
}