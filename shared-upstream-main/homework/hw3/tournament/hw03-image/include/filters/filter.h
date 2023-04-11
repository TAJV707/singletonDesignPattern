#ifndef FILTER_H__
#define FILTER_H__

#include <array>
#include "../image.h"

namespace image_processing {

/**
 * @brief Class for a filter that transforms an Image in some way
 */
template <std::size_t NUM_IMGS_IN, std::size_t NUM_IMGS_OUT>
class Filter {
public:
    virtual ~Filter() { };

    /**
     * @brief Given or more images, transform it them some way, producing
     * one or more images as a result
     * 
     * @return the newly produced images
     */
    virtual std::array<Image, NUM_IMGS_OUT> Apply(std::array<Image, NUM_IMGS_IN> original) = 0;

    // utilities for template nonsense
    static const std::size_t numInputImgs = NUM_IMGS_IN;
    static const std::size_t numOutputImgs = NUM_IMGS_OUT;
    typedef std::array<Image, NUM_IMGS_IN> input;
    typedef std::array<Image, NUM_IMGS_OUT> output;
};

}


#endif // FILTER_H__