//
// Created by 单淳劼 on 2022/3/30.
//

#include "radon.h"

Radon::Radon()
{

}

int Radon::calcRadonTransform(cv::Mat &src, cv::Mat& sinogram, int theta)
{
    sinogram.create(cv::Size(theta, src.rows), CV_32FC1);

    for (int angle = 0; angle < theta; angle++)
    {
        cv::Mat rotated;

        rotate(src, rotated, angle);
        std::cout << rotated.rows << " " << rotated.cols << std::endl;
        rotated.convertTo(rotated, CV_32FC1);

        for (int i = 0; i < rotated.cols; i++)
        {
            cv::Mat rCol = rotated.col(i);

            for (int row = 0; row < rCol.rows; row++)
            {
                sinogram.at<float>(i, angle) += rCol.at<float>(row, 0);
            }
        }
    }

    cv::normalize(sinogram, sinogram, 0, 255, cv::NORM_MINMAX);
    return 0;
}

float Radon::deg2rad(int degree)
{
    float rad = static_cast<float>(degree) * CV_PI / 180.0f;
    return rad;
}

int Radon::rotate(cv::Mat &src, cv::Mat& dst, int degree)
{
    int center = src.rows / 2;
    dst.create(src.size(), src.type());

    cv::Mat m0 = (cv::Mat_<float>(3, 3) << 1, 0, -center,
        0, 1, -center,
        0, 0, 1
    );

    cv::Mat m1 = (cv::Mat_<float>(3, 3) << 1, 0, center,
            0, 1, center,
            0, 0, 1);

    float rad = deg2rad(degree);
    cv::Mat mR = (cv::Mat_<float>(3, 3) << std::cos(rad), std::sin(rad), 0,
            -std::sin(rad), std::cos(rad), 0,
            0, 0, 1);

    cv::Mat rotateMat = m1 * mR * m0;
    cv::warpPerspective(src, dst, rotateMat, cv::Size(src.rows, src.cols), cv::WARP_INVERSE_MAP);

    return 0;
}

int Radon::padImage(cv::Mat &src, cv::Mat &dst)
{
    int shapeMin = std::min(src.rows, src.cols);
    int radius = shapeMin / 2;

    return 0;
}
