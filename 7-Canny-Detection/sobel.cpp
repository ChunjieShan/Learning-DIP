//
// Created by 单淳劼 on 2022/3/8.
//

#include "sobel.h"

Sobel::Sobel(cv::Mat& src, cv::Mat& dst, int gx, int gy, int kernelSize)
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

    dst = getResult();
}

Sobel::Sobel(int gx, int gy, int kernelSize)
    : mGx(gx)
    , mGy(gy)
    , mKernelSize(kernelSize)
{
    genGxGyKernel();
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

int Sobel::calcSobel(cv::Mat &src, cv::Mat& dst)
{
    mSrc = src;
    mGxResult = cv::Mat::zeros(mSrc.size(), CV_32S);
    mGyResult = cv::Mat::zeros(mSrc.size(), CV_32S);
    mGxGyResult = cv::Mat::zeros(mSrc.size(), CV_32S);
    calcSobel();

    dst = getResult();

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

    mGxResult.convertTo(mGxResult, CV_8UC1);

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

            mGyResult.at<char>(row, col) = gy;
        }
    }

    mGyResult.convertTo(mGyResult, CV_8UC1);
    return 0;
}

int Sobel::calcGxGySobel()
{
    // calculate both gx and gy
    cv::Mat sobelMat;
    cv::copyMakeBorder(mSrc, sobelMat, 1, 1, 1, 1, cv::BORDER_REPLICATE);
    mSrc.convertTo(sobelMat, CV_32SC1);
    int h = (mKernelSize - 1) / 2;
    int w = (mKernelSize - 1) / 2;

    for (int row = 1; row < sobelMat.rows; row++)
    {
        for (int col = 1; col < sobelMat.cols; col++)
        {
            char gx = 0;
            char gy = 0;

            for (int i = -h; i <= h; i++)
            {
                for (int j = -w; j <= w; j++)
                {
//                    std::cout << sobelMat.at<int>(row + i, col + j) << std::endl;
//                    std::cout << h + i << " " << w + j << " " << std::endl;
                    gx += sobelMat.at<int>(row + i, col + j) * mGxFilter.at<char>(h + i, w + j);
                    gy += sobelMat.at<int>(row + i, col + j) * mGyFilter.at<char>(h + i, w + j);
                }
            }

            mGxResult.at<int>(row, col) = gx;
            mGyResult.at<int>(row, col) = gy;
//            std::cout << "200\n";
        }

    }

    cv::addWeighted(mGxResult, 0.5, mGyResult, 0.5, 0, mGxGyResult);
    mGxGyResult.convertTo(mGxGyResult, CV_8UC1);
    cv::imwrite("../sobel.png", mGxGyResult);

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

std::vector<cv::Mat> Sobel::getGxGyResult()
{
    std::vector<cv::Mat> vGxGyResult = {mGxResult, mGyResult};
    return vGxGyResult;
}

cv::Mat Sobel::getResult()
{
    if (mGx && !mGy)
        return mGxResult;

    else if (!mGx && mGy)
        return mGyResult;

    else if (mGx && mGy)
        return mGxGyResult;
}


