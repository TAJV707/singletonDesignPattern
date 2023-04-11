#ifndef FILTERS_GREYSCALE_FILTER_H__
#define FILTERS_GREYSCALE_FILTER_H__

#include "filter.h"

namespace image_processing {

/**
 * @brief This filter makes an image greyscale
 */
class GreyScaleFilter : public Filter<1, 1> {
public:
	/**
 	* @brief Appplies the greyscale filter to one image
 	*
 	* @returns The resulting greyscale image
 	*/
    std::array<Image, 1> Apply(std::array<Image, 1> original) override;
};

}

#endif // FILTERS_GREYSCALE_FILTER_H__
