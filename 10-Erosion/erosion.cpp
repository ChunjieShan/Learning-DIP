//
// Created by 单淳劼 on 2022/3/22.
//

#include "erosion.h"

Erosion::Erosion(cv::Size kernelSize)
    : mKernelSize(kernelSize)
{

}

int Erosion::getStructElement()
{

    return 0;
}

int Erosion::erode(cv::Mat &src, cv::Mat &dst)
{
    dst = cv::Mat::zeros(src.size(), src.type());
    for (int i = mKernelSize.height; i < src.rows; i++)
    {
        for (int j = mKernelSize.width; j < src.cols; j++)
        {
            uchar minV = 255;

            for (int m = -mKernelSize.height; m < mKernelSize.height; m++)
            {
                for (int n = -mKernelSize.width; n < mKernelSize.width; n++)
                {
                    int x = i + m;
                    int y = j + n;
                    minV = std::min<uchar>(minV, src.at<uchar>(x, y));
                }
            }

            dst.at<uchar>(i, j) = minV;
        }
    }

    return 0;
}

