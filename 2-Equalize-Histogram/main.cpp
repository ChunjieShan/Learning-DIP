//
// Created by 单淳劼 on 2022/3/5.
//

#include "histogram.h"
#include "equal_hist.h"

int main()
{
    cv::Mat image = cv::imread("../../image.png", cv::IMREAD_GRAYSCALE);

    // generate histogram
    Histogram hist;
    hist.calcGrayHist(image);
    std::vector<int> vHistogram = hist.getVectorHistogram();

    // calculate histogram equalization
    EqualHist equalHist(vHistogram, image.cols, image.rows);
    equalHist.equalizeHist();

    return 0;
}