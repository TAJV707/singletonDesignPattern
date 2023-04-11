#ifndef FILTERS_SOBEL_FILTER_H__
#define FILTERS_SOBEL_FILTER_H__

#include "filter.h"
#include "convolution_filter.h"

namespace image_processing {

/**
 * @brief This filter calculates the gradient of an image. The resulting images
 * indicate where pixel values change significantly (the intensity of the change)
 * as well as the directtion of the change
 */
class SobelFilter : public Filter<1, 2> {
private:
    static ConvolutionFilter kXConv;
    static ConvolutionFilter kYConv;
public:
    /**
     * @brief Given a greyscale image, calculate the gradient
     * 
     * @returns an array containing two Images. the first is the Sobel intensity
     * result, the second is the Sobel direction result
     */
    std::array<Image, 2> Apply(std::array<Image, 1> original);
};

}

#endif // FILTERS_SOBEL_FILTER_H__
