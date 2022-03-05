//
// Created by 单淳劼 on 2022/3/5.
//

#include "equal_hist.h"

EqualHist::EqualHist(std::vector<int> &vHistogram, int width, int height)
    : mHeight(height)
    , mWidth(width)
    , mHistogram(vHistogram)
    , mEqualHistogram(std::vector<float>(255, 0.0f))
{

}

int EqualHist::equalizeHist()
{
    int numPixel = mWidth * mHeight;

    int prevValue = mHistogram[0];

    for (int i = 1; i < mHistogram.size(); i++)
    {
        mEqualHistogram[i - 1] = static_cast<float>(mHistogram[i] + prevValue) / static_cast<float>(numPixel);

        prevValue += mHistogram[i];
    }

    return 1;
}

