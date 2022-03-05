#include <iostream>
#include "1-Histogram/histogram.h"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    cv::Mat img = cv::imread("../image.png", cv::IMREAD_GRAYSCALE);
    Histogram hist;
    hist.calcGrayHist(img);
    cv::Mat histogram = hist.getHistogram();

    cv::imwrite("histogram.jpg", histogram);
    return 0;
}
