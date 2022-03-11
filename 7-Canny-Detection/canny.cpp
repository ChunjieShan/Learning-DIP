//
// Created by 单淳劼 on 2022/3/11.
//

#include "canny.h"

Canny::Canny()
    : mGaussianFilter(3, 0.8)
    , mSobel(Sobel(1, 1, 3))
{

}

int Canny::calcGaussFilter(cv::Mat &src, cv::Mat &dst)
{
    int ret = mGaussianFilter.calcGaussFilter(src, dst);

    if (ret == 0)
        return 0;
    else
        return 1;
}

int Canny::calcSobelFilter(cv::Mat &src, cv::Mat &dst)
{
    int ret = mSobel.calcSobel(src, dst);

    if (ret == 0)
        return 0;
    else
        return 1;
}

int Canny::getDirection(cv::Mat &sobelGxMat, cv::Mat& sobelGyMat)
{
    for (int i = 0; i < sobelGxMat.rows; i++)
    {
        for (int j = 0; j < sobelGxMat.cols; j++)
        {
            int gx = sobelGxMat.at<int>(i, j);
            int gy = sobelGyMat.at<int>(i, j);
            float theta = static_cast<float>(gy) / static_cast<float>(gx);
            mDirection.push_back(std::atan(theta));
        }
    }
    return 0;
}

int Canny::localNMS(cv::Mat& src, cv::Mat& dst)
{
    if (dst.empty())
        dst = src.clone();

    int counter = 0;

    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            int value00 = src.at<int>(i - 1, j - 1);
            int value01 = src.at<int>(i - 1, j);
            int value02 = src.at<int>(i - 1, j + 1);
            int value10 = src.at<int>(i, j - 1);
            int value11 = src.at<int>(i, j);
            int value12 = src.at<int>(i, j + 1);
            int value20 = src.at<int>(i + 1, j - 1);
            int value21 = src.at<int>(i + 1, j);
            int value22 = src.at<int>(i + 1, j + 1);

            if (mDirection[counter] > 0 && mDirection[counter] <= 45)
            {
                if (value11 <= value12 + static_cast<float>(value02 - value12) * std::tan(mDirection[i * src.rows + j]) || value11 <= value10 + static_cast<float>(value20 - value10) * std::tan(mDirection[i * src.rows + j])))
                {

                }
            }
        }
    }
    return 0;
}
