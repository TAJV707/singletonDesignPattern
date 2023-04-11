#ifndef FILTERS_GAUSSIAN_BLUR_H__
#define FILTERS_GAUSSIAN_BLUR_H__

#include "filter.h"
#include "convolution_filter.h"

namespace image_processing {

/**
 * @brief This filter blurs an image using the Gaussian blur technique
 */
class GaussianBlurFilter : public Filter<1, 1> {
private:
    ConvolutionFilter convFilter;
public:
    /**
     * @brief Create a Gaussian blur filter with the given kernel size and
     * sigma value (standard deviation)
     * 
     * Generally, both a higher kernel size and a higher sigma value can be 
     * expected to blur the image more
     */
    GaussianBlurFilter(int size, double sigma);
    /**
     * @brief Apply the gaussian blur to one image
     * 
     * @returns the resulting image
     */
    std::array<Image, 1> Apply(std::array<Image, 1> img) override;
};

}


#endif