#ifndef FILTERS_HYSTERESIS_FILTER_H__
#define FILTERS_HYSTERESIS_FILTER_H__

#include "filter.h"

namespace image_processing {

/**
 * @brief This filter recognizes softer edges
 */
class HysteresisFilter : public Filter<1, 1> {
public:
	/**
     * @brief create a hysteresis filter with the given bounds
     */
	HysteresisFilter(double strong, double weak) : strong(strong), weak(weak) {}
	/**
     * @brief applies the hysteresis filter to one image
     */
    std::array<Image, 1> Apply(std::array<Image, 1> original) override;

private:
	double weak;
	double strong;
};

}

#endif // FILTERS_HYSTERESIS_FILTER_H__