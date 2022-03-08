//
// Created by 单淳劼 on 2022/3/8.
//

#include "sobel.h"

Sobel::Sobel(cv::Mat& src, int gx, int gy, int kernelSize)
    : mSrc(src)
    , mGx(gx)
    , mGy(gy)
    , mGxResult(cv::Mat::zeros(src.size(), CV_8SC1))
    , mGyResult(cv::Mat::zeros(src.size(), CV_8SC1))
    , mKernelSize((kernelSize - 1) / 2)
    , mGxFilter(cv::Mat::zeros(cv::Size(kernelSize, kernelSize), CV_8SC1))
    , mGyFilter(cv::Mat::zeros(cv::Size(kernelSize, kernelSize), CV_8SC1))
{
    genGxGyKernel();

    calcSobel();
}

int Sobel::calcSobel()
{
    if (mGx && !mGy)
        calcGxSobel();

    else if (!mGx && mGy)
        calcGySobel();

    else if (mGx && mGy)
        calcGxGySobel();

    return 0;
}

int Sobel::calcGxSobel()
{
    // calculate gx
    for (int row = 1; row < mSrc.rows; row++)
    {
        for (int col = 1; col < mSrc.cols; col++)
        {
            char gx = 0;

            for (int i = -mKernelSize; i <= mKernelSize; i++)
            {
                for (int j = -mKernelSize; j <= mKernelSize; j++)
                {
                    gx += mSrc.at<char>(row + i, col + j) * mGxFilter.at<char>(mKernelSize + i, mKernelSize + j);
                }
            }

            mGxResult.at<char>(row, col) = gx;
        }

    }

    return 0;
}

int Sobel::calcGySobel()
{
    // calculate gy
    for (int row = 1; row < mSrc.rows; row++)
    {
        for (int col = 1; col < mSrc.cols; col++)
        {
            char gy = 0;

            for (int i = -mKernelSize; i <= mKernelSize; i++)
            {
                for (int j = -mKernelSize; j <= mKernelSize; j++)
                {
                    gy += mSrc.at<char>(row + i, col + j) * mGyFilter.at<char>(mKernelSize + i, mKernelSize + j);
                }
            }

            mGxResult.at<char>(row, col) = gy;
        }

    }
    return 0;
}

int Sobel::calcGxGySobel()
{
    // calculate both gx and gy
    for (int row = 1; row < mSrc.rows; row++)
    {
        for (int col = 1; col < mSrc.cols; col++)
        {
            char gx = 0;
            char gy = 0;

            for (int i = -mKernelSize; i <= mKernelSize; i++)
            {
                for (int j = -mKernelSize; j <= mKernelSize; j++)
                {
                    gx += mSrc.at<char>(row + i, col + j) * mGxFilter.at<char>(mKernelSize + i, mKernelSize + j);
                    gy += mSrc.at<char>(row + i, col + j) * mGyFilter.at<char>(mKernelSize + i, mKernelSize + j);
                }
            }

            mGxResult.at<char>(row, col) = gx;
            mGyResult.at<char>(row, col) = gy;
        }

    }

    cv::addWeighted(mGxResult, 0.5, mGyResult, 0.5, 0, mGxGyResult);
    cv::imwrite("../resultxy.png", mGxGyResult);

    return 0;
}

int Sobel::genGxGyKernel()
{
    mGxFilter = (cv::Mat_<char>(3, 3) <<
                -1, -2, -1,
                 0,  0,  0,
                 1,  2,  1
    );

    mGyFilter = (cv::Mat_<char>(3, 3) <<
           -1 , 0,  1,
           -2 , 0,  2,
           -1 , 0,  1
    );

    return 0;
}

