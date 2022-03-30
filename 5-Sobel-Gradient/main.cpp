//
// Created by 单淳劼 on 2022/3/8.
//

#include "sobel.h"

int main()
{
    cv::Mat img = cv::imread("../lena.png", cv::IMREAD_GRAYSCALE);
    cv::Mat dst;
    Sobel sobel(img, dst, 1, 1, 3);

    cv::imwrite("../resultxy.png", dst);

    return 0;
}

