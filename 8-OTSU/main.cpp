//
// Created by 单淳劼 on 2022/3/17.
//

#include "otsu.h"

int main()
{
    cv::Mat img = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);

    Otsu otsu(img);
    otsu.calcThresh();

    int thresh = otsu.calcThresh();
    std::cout << thresh << std::endl;
    return 0;
}
