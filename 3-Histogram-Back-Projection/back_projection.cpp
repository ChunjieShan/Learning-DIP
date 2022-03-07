//
// Created by 单淳劼 on 2022/3/6.
//

#include "back_projection.h"

BackProjection::BackProjection(cv::Mat& image, cv::Mat& modelImg)
    : mHistogram(std::vector<int>(256, 0))
    , mModelHistogram(std::vector<int>(256, 0))
    , mImg(image)
    , mModelImg(modelImg)
    , mResultImg(cv::Mat::zeros(image.rows, image.cols, image.type()))
{
    Histogram hist;
    Histogram modelHist;

    hist.calcGrayHist(mImg);
    mHistogram = hist.getVectorHistogram();

    modelHist.calcGrayHist(mModelImg);
    mModelHistogram = modelHist.getVectorHistogram();
}

int BackProjection::calcBackProject()
{
    for (int i = 0; i < mImg.rows; i++)
    {
        for (int j = 0; j < mImg.cols; j++)
        {
            int grayValue = mImg.at<uchar>(i, j);
            mResultImg.at<uchar>(i, j) = mModelHistogram[grayValue];
        }
    }

    std::cout << "Saving result...\n";
    cv::imwrite("../result.png", mResultImg);

    std::cout << "Saved result to ../result.png\n";

    return 1;
}
