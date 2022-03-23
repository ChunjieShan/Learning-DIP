//
// Created by 单淳劼 on 2022/3/23.
//

#include "dilation.h"

Dilation::Dilation(cv::Size kSize)
    : m_kSize(kSize)
{

}

int Dilation::dilate(cv::Mat &src, cv::Mat &dst)
{
    dst = cv::Mat::zeros(src.size(), src.type());

    int kWidth = (m_kSize.width - 1) / 2;
    int kHeight = (m_kSize.height - 1) / 2;

    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            uchar maxValue = 0;

            for (int m = -kWidth; m < kWidth; m++)
            {
                for (int n = -kHeight; n < kHeight; n++)
                {
                    maxValue = std::max(src.at<uchar>(i + m, j + n), maxValue);
                }
            }

            dst.at<uchar>(i, j) = maxValue;
        }
    }

    return 0;
}