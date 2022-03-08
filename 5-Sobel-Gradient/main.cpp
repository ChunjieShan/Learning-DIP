//
// Created by 单淳劼 on 2022/3/8.
//

#include "sobel.h"

int main()
{
    cv::Mat img = cv::imread("../lena.png", cv::IMREAD_GRAYSCALE);

    Sobel sobel(img, 1, 1, 3);

    return 0;
}

