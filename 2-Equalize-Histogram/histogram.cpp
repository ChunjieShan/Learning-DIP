//
// Created by 单淳劼 on 2022/3/5.
//

#include "histogram.h"

Histogram::Histogram()
    : mHistogram(std::vector<int>(256, 0))
{}

int Histogram::calcGrayHist(cv::Mat &img)
{
    int rows = img.rows;
    int cols = img.cols;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int grayScale = img.at<uchar>(row, col);
            mHistogram[grayScale]++;
        }
    }

    visGrayHist();

    return 1;
}

int Histogram::visGrayHist()
{
    auto maxGrayValue = std::max_element(mHistogram.begin(), mHistogram.end());

    int histogramHeight = *maxGrayValue + 10;

    mVisHistogram = cv::Mat::zeros(*maxGrayValue + 10, 256, CV_16FC1);

    for (int i = 0; i < mHistogram.size(); i++)
    {
        cv::line(mVisHistogram, cv::Point(i, histogramHeight), cv::Point(i, histogramHeight - mHistogram[i]), cv::Scalar(255, 255, 255));
    }

    return 1;
}

