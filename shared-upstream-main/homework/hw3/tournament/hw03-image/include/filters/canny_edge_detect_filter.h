#ifndef FILTERS_CANNY_EDGE_DETECT_FILTER_H__
#define FILTERS_CANNY_EDGE_DETECT_FILTER_H__

#include "filters/filter.h"
#include "filters/greyscale_filter.h"
#include "filters/gaussian_blur_filter.h"
#include "filters/sobel_filter.h"
#include "filters/non_maximum_suppression.h"
#include "filters/double_threshold.h"
#include "filters/hysteresis_filter.h"

namespace image_processing {

class CannyEdgeDetectFilter : public Filter<1, 1> {
private:
    GaussianBlurFilter blurFilter;
    GreyScaleFilter greyscaleFilter;
    SobelFilter sobelFilter;
    NonMaximumSuppression nonMaximumSupression;
    DoubleThreshold doubleThreshold;
    HysteresisFilter hysteresis;

public:
    CannyEdgeDetectFilter(
        int blurSize = 5,
        double blurSigma = 2.0) : blurFilter(blurSize, blurSigma),
                                  doubleThreshold(.4, .25, 1, 0.1),
                                  hysteresis(1, 0.1)
    {
    }

    std::array<Image, 1> Apply(std::array<Image, 1> original) {
        auto greyscaledImage = greyscaleFilter.Apply(std::move(original));
        auto blurredImage = blurFilter.Apply(std::move(greyscaledImage));
        // warning: sobel outputs 2 images
        auto sobelFiltered = sobelFilter.Apply(std::move(blurredImage));
        auto nonMaximumSuppressedImage = nonMaximumSupression.Apply(std::move(sobelFiltered));
        auto doubleThresholded = doubleThreshold.Apply(std::move(nonMaximumSuppressedImage));
        auto hysteresisOutput = hysteresis.Apply(std::move(doubleThresholded));

        return hysteresisOutput;
    }
};

}

#endif// FILTERS_CANNY_EDGE_DETECT_FILTER_H__
