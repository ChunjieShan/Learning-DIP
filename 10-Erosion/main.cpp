//
// Created by 单淳劼 on 2022/3/22.
//

#include "erosion.h"

int main()
{
    cv::Mat img = cv::imread("../rice_clean.png", cv::IMREAD_GRAYSCALE);
    Erosion erosion(cv::Size(3, 3));

    cv::Mat erodeImg;
    erosion.erode(img, erodeImg);
    cv::imwrite("../erode.png", erodeImg);


    return 0;
}
