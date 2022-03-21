//
// Created by 单淳劼 on 2022/3/21.
//

#include "interpolation.h"

Interp::Interp(int type, int height, int width)
    : mType(type)
    , mHeight(height)
    , mWidth(width)
{

}

int Interp::interpolate(cv::Mat &src, cv::Mat &dst)
{
    switch (mType)
    {
        case NEAREST:
            nearestInterp(src, dst);
            break;
        case BILINEAR:
            bilinearInterp(src, dst);
            break;
    }

    return 0;
}

int Interp::nearestInterp(cv::Mat &src, cv::Mat &dst)
{
    dst = cv::Mat::zeros(cv::Size(mWidth, mHeight), src.type());

    float fx = static_cast<float>(src.rows) / static_cast<float>(mHeight);
    float fy = static_cast<float>(src.cols) / static_cast<float>(mWidth);

    for (int i = 0; i < mHeight; i++)
    {
        for (int j = 0; j < mWidth; j++)
        {
            int newX = std::round(static_cast<float>(i) * fy);
            int newY = std::round(static_cast<float>(j) * fx);

//            std::cout << "new x:\t" << newX << std::endl;
//            std::cout << "new y:\t" << newY << std::endl;

            if (newX >= src.rows)
                newX = src.rows - 1;

            if (newY >= src.cols)
                newY = src.cols - 1;

            dst.at<uchar>(i, j) = src.at<uchar>(newX, newY);
        }
    }

    return 0;
}

int Interp::bilinearInterp(cv::Mat &src, cv::Mat &dst)
{
    cv::Mat fSrc;
    src.convertTo(fSrc, CV_32FC1);

    dst = cv::Mat::zeros(cv::Size(mWidth, mHeight), fSrc.type());

    for (int i = 0; i < mHeight; i++)
    {
        for (int j = 0; j < mWidth; j++)
        {

            float srcX = (static_cast<float>(i) + 0.5f) * (static_cast<float>(src.cols) / static_cast<float>(mWidth)) - 0.5f;
            float srcY = (static_cast<float>(j) + 0.5f) * (static_cast<float>(src.rows) / static_cast<float>(mHeight)) - 0.5f;

            srcX = srcX < 0 ? 0: srcX;
            srcY = srcY < 0 ? 0: srcY;

            srcX = srcX > static_cast<float>(src.rows) - 1.0f ? static_cast<float>(src.rows) - 1.0f: srcX;
            srcY = srcY > static_cast<float>(src.cols) - 1.0f ? static_cast<float>(src.cols) - 1.0f: srcY;

            float u = srcX - std::floor(srcX);
            float v = srcY - std::floor(srcY);

            dst.at<float>(i, j) = (1.0f - u) * (1.0f - v) * fSrc.at<float>((int)srcX, (int)srcY)
                    + (1.0f - u) * v * fSrc.at<float>((int)srcX, (int)srcY + 1)
                    + u * (1.0f - v) * fSrc.at<float>((int)srcX + 1, (int)srcY)
                    + u * v * fSrc.at<float>((int)srcX + 1, (int)srcY + 1);
        }
    }

    return 0;
}

