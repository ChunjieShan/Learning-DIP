//
// Created by 单淳劼 on 2022/3/23.
//

#include "dilation.h"

int main()
{
    cv::Mat img = cv::imread("../rice_clean.png", cv::IMREAD_GRAYSCALE);
    Dilation dilation(cv::Size(15, 15));

    cv::Mat dst;
    dilation.dilate(img, dst);

    cv::imwrite("../dilate.png", dst);

    return 0;
}
