//
// Created by 单淳劼 on 2022/3/7.
//

#include "gaussian_filter.h"

GaussianFilter::GaussianFilter(int kernelSize, float sigma)
    : mGaussKernel(cv::Mat::zeros(kernelSize, kernelSize, CV_32FC1))
    , mSigma(sigma)
{
    genGaussKernel();
}

GaussianFilter::GaussianFilter(cv::Size kernelSize, float sigma)
    : mGaussKernel(cv::Mat::zeros(kernelSize, CV_32FC1))
    , mSigma(sigma)
{
    genGaussKernel();
}

int GaussianFilter::calcGaussFilter(cv::Mat& src, cv::Mat& dst)
{
    dst = cv::Mat::zeros(src.size(), src.type());

    int h = (mGaussKernel.rows - 1) / 2;
    int w = (mGaussKernel.cols - 1) / 2;

    cv::copyMakeBorder(src, src, h, h, w, w, cv::BORDER_REPLICATE);
    cv::Mat fSrc;
    src.convertTo(fSrc, CV_32FC1);

    for (int row = h; row < src.rows; row++)
    {
        for (int col = w; col < src.cols; col++)
        {
            float sum = 0.0f;

            // convolution operation
            for (int i = -h; i <= h; i++)
            {
                for (int j = -w; j <= w; j++)
                {
                    sum += fSrc.at<float>(row + i, col + j) * mGaussKernel.at<float>(h + i, w + j);
                }
            }

            dst.at<int>(row - h, col - w) = static_cast<int>(sum);
        }
    }

    return 0;
}

int GaussianFilter::genGaussKernel()
{
    int kHeight = mGaussKernel.rows;
    int kWidth  = mGaussKernel.cols;

    int kCenterH = (kHeight - 1) / 2;
    int kCenterW = (kWidth  - 1) / 2;

    float sum = 0.0;  // for normalization

    for (int i = 0; i < mGaussKernel.rows; i++)
    {
        auto x = static_cast<float>(i - kCenterH);
        float x2 = x * x;

        for (int j = 0; j < mGaussKernel.cols; j++)
        {
            auto y = static_cast<float>(j - kCenterW);
            float y2 = y * y;

            float above = (x2 + y2) / static_cast<float>(2 * mSigma * mSigma);
            float exp = std::exp(-1.0f * above);

            mGaussKernel.at<float>(i, j) = exp;
            sum += exp;
        }
    }

    mGaussKernel /= sum;
    return 0;
}