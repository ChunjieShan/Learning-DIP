//
// Created by 单淳劼 on 2022/3/11.
//

#include "canny.h"

Canny::Canny(cv::Mat& src, cv::Mat& dst)
    : mSobel(1, 1, 3)
    , mGaussianFilter(3, 0.8)
    , mSrc(cv::Mat::zeros(src.size(), CV_32S))
    , mDst(cv::Mat::zeros(src.size(), CV_32S))
{
    calcCannyBorder(src, dst, 100.f, 200.f);
//    cv::imwrite("../double.png", mDst);
}

int Canny::calcCannyBorder(cv::Mat &src, cv::Mat dst, float highThresh, float lowThresh)
{
    src.convertTo(mSrc, CV_32S);
    calcGaussFilter(mSrc, mDst);
    calcSobelFilter(mDst, mDst);

    std::vector<cv::Mat> vGxGyResult = mSobel.getGxGyResult();

    getDirection(vGxGyResult[0], vGxGyResult[1]);
    localNMS(mDst, mDst);
    doubleThreshLink(mDst, mDst, 5.f, 10.f);
    return 0;
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

            if (gx == 0)
            {
                if (gy > 0)
                    mDirection.push_back(90.f);
                else if (gy < 0)
                    mDirection.push_back(-90.f);
            }

            else if (gy == 0)
            {
                mDirection.push_back(0.0f);
            }
            else
            {
                float theta = (static_cast<float>(gy) / static_cast<float>(gx));
                theta = std::atan(theta) * 180.0f / CV_PI;
//                std::cout << gx << " " << gy << std::endl;
//                std::cout << theta << std::endl;
                mDirection.push_back(std::atan(theta));
            }
        }
    }
    return 0;
}

int Canny::localNMS(cv::Mat& src, cv::Mat& dst)
{
    if (dst.empty())
        dst = src.clone();

    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            int index = (i - 1) * dst.rows + j;
            float angle = mDirection[index];
            if ((angle >= 0.0f && angle <= 22.5f) || (angle >= 157.5f))
            {
                int value = src.at<int>(i, j);
                int value1 = src.at<int>(i, j + 1);
                int value2 = src.at<int>(i, j - 1);

                if (value < value1 || value < value2)
                    dst.at<int>(i, j) = 0;
            }

            else if (angle >= 22.5f && angle < 67.5f)
            {
                int value = src.at<int>(i, j);
                int value1 = src.at<int>(i + 1, j - 1);
                int value2 = src.at<int>(i - 1, j + 1);

                if (value < value1 || value < value2)
                    dst.at<int>(i, j) = 0;
            }

            else if (angle >= 67.5f && angle < 112.5f)
            {
                int value = src.at<int>(i, j);
                int value1 = src.at<int>(i + 1, j);
                int value2 = src.at<int>(i - 1, j);

                if (value < value1 || value < value2)
                    dst.at<int>(i, j) = 0;
            }

            else if (angle >= 112.5f && angle < 157.5f)
            {
                int value = src.at<int>(i, j);
                int value1 = src.at<int>(i - 1, j - 1);
                int value2 = src.at<int>(i + 1, j + 1);

                if (value < value1 || value < value2)
                    dst.at<int>(i, j) = 0;
            }
        }
    }

    return 0;
}

int Canny::doubleThreshLink(cv::Mat &src, cv::Mat &dst, float lowThresh, float highThresh)
{
    if (dst.empty())
        dst = src.clone();

    else
        src.convertTo(dst, CV_32S);
    for (int i = 1; i < src.rows - 1; i++)
    {
        for (int j = 1; j < src.cols - 1; j++)
        {
            int value = src.at<int>(i, j);
            float fValue = static_cast<float>(value);
//            std::cout << value << " " << fValue << std::endl;

            if (fValue < lowThresh)
                dst.at<int>(i, j) = 0;

            else if (fValue > highThresh)
                dst.at<int>(i, j) = 255;

            else
            {

                if (
                    src.at<int>(i - 1, j - 1) > highThresh || src.at<int>(i, j - 1) < highThresh || src.at<int>(i + 1, j - 1) < highThresh ||
                    src.at<int>(i - 1, j) < highThresh || src.at<int>(i + 1, j) < highThresh ||
                    src.at<int>(i - 1, j + 1) < highThresh || src.at<int>(i, j + 1) < highThresh || src.at<int>(i + 1, j + 1) < highThresh
                )
                {
                    dst.at<int>(i, j) = 0;
                }
            }

//            std::cout << dst.at<int>(i, j) << " ";
        } // for j
    } // for i

    return 0;
}

