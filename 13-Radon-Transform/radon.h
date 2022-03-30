//
// Created by 单淳劼 on 2022/3/30.
//

#ifndef RADON_TRANSFORM_RADON_H
#define RADON_TRANSFORM_RADON_H

#include <opencv2/opencv.hpp>
#include <iostream>

class Radon
{
public:
    Radon();
    int calcRadonTransform(cv::Mat& src, cv::Mat& sinogram, int theta);

private:
    static float deg2rad(int degree);
    int rotate(cv::Mat& src, cv::Mat& dst, int degree);
    int padImage(cv::Mat& src, cv::Mat& dst);

};


#endif //RADON_TRANSFORM_RADON_H
