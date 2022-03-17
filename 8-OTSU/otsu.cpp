//
// Created by 单淳劼 on 2022/3/17.
//

#include "otsu.h"

Otsu::Otsu()
{

}

Otsu::Otsu(cv::Mat& src)
    : mHistTable(std::vector<int>(256, 0))
    , mSrc(src.clone())
    , mThresh(0)
{

}

int Otsu::calcHistogram()
{
    cv::Mat iSrc;
    mSrc.convertTo(iSrc, CV_32SC1);

    for (int i = 0; i < iSrc.rows; i++)
    {
        for (int j = 0; j < iSrc.cols; j++)
        {
            int grayValue = iSrc.at<int>(i, j);
//            std::cout << grayValue << " ";
            mHistTable[grayValue]++;
        }
    }

    return 0;
}

int Otsu::calcThresh()
{
    calcHistogram();

    int u0 = 0;  // mean of background
    int u1 = 0;  // mean of foreground
    int v0 = 0;  // variance of background
    int v1 = 0;  // variance of foreground
    int numPixels = mSrc.rows * mSrc.cols;
    int value = 0;

    for (int i = 0; i < 255; i++)
    {
        u0 = 0;
        u1 = 0;
        v0 = 0;
        v1 = 0;

        for (int j = 0; j <= i; j++)
        {
            v0 += mHistTable[i];
//            std::cout << mHistTable[i] << std::endl;
            u0 += j * mHistTable[i];
        }

        if (v0 == 0)
            break;

        u0 = u0 / v0;
        v0 = v0 / numPixels;

        for (int k = i; k < 255; k++)
        {
            v1 += mHistTable[k];
            u1 += k * mHistTable[k];
        }

        if (v1 == 0)
            break;

        u1 = u1 / v1;
        v1 = v1 / numPixels;

        int currValue = v0 * v1 * std::pow((u1 - u0), 2);
        if (currValue > value)
        {
            value = currValue;
            mThresh = i;
        }
    }

    otsuSegment();

    return 0;
}

int Otsu::otsuSegment()
{
    cv::Mat binaryMat = cv::Mat::zeros(mSrc.size(), CV_32SC1);

    for (int i = 0; i < mSrc.rows; i++)
    {
        for (int j = 0; j < mSrc.cols; j++)
        {
            if (mSrc.at<char>(i, j) < mThresh)
                binaryMat.at<char>(i, j) = 0;
            else
                binaryMat.at<int>(i, j) = 255;
        }
    }

    cv::imwrite("../binary.png", binaryMat);

    return 0;
}
