//
// Created by 单淳劼 on 2022/3/9.
//

#include "sharpen.h"

Sharpen::Sharpen(cv::Mat &img, cv::Mat& dst)
{
    dst = cv::Mat::zeros(img.size(), CV_32S);
    img.convertTo(mSrc, CV_32S);
    mKernel = (cv::Mat_<int>(3, 3) <<
            -1, -1, -1,
            -1,  8, -1,
            -1, -1, -1);

    calcSharpen(mSrc, dst);
    img.convertTo(img, CV_32S);
    dst = img + dst;
    cv::imwrite("../result.png", dst);
}

int Sharpen::calcSharpen(cv::Mat &src, cv::Mat& dst)
{
    int kH = (mKernel.rows - 1) / 2;
    int kW = (mKernel.cols - 1) / 2;

    cv::copyMakeBorder(src, src, kH, kH, kW, kW, cv::BORDER_REPLICATE);

    for (int row = 1; row < src.rows - 1; row++)
    {
        for (int col = 1; col < src.cols - 1; col++)
        {
             int sum = 0;
             for (int i = -kH; i <= kH; i++)
             {
                 for (int j = -kW; j <= kW; j++)
                 {
                     sum += src.at<int>(row + i, col + j) * mKernel.at<int>(i + kH, j + kW);
                 }
             }

             sum = sum > 255 ? 255 : sum;
             sum = sum < 0   ? 0   : sum;

            dst.at<int>(row - kH, col - kW) = sum;
        }
    }

    return 0;
}
