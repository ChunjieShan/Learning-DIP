//
// Created by 单淳劼 on 2022/3/30.
//

#include "radon.h"

int main()
{
    cv::Mat img = cv::imread("../phantom.png", cv::IMREAD_GRAYSCALE);
    Radon radon;
    cv::Mat radonImg;
    radon.calcRadonTransform(img, radonImg, 180);
    cv::imwrite("../radon.png", radonImg);
//    std::cout << radonImg << std::endl;

    return 0;
}