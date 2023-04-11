#ifndef _Non_Maximum_Suppression_
#define _Non_Maximum_Suppression_

/************************************************************************************
 * includes
 * *********************************************************************************/
#include "filter.h"
#include <cmath>

namespace image_processing {
/***********************************************************************************
 * Class Definitions
 **********************************************************************************/


/**
 * @brief Class representing the Non-maximum Suppression Filter used by a canny edge detector
 */
class NonMaximumSuppression : public Filter<2, 1> {
public: 
     /**
      * @brief Empty constructor for non-maximum suppression filter
      * 
      */
     NonMaximumSuppression(){}
     /**
     * @brief Given an the direction and intensity images, eliminate wide and fuzzy edges
     * 
     * @return return an Image with only the strongest pixels
     */
     std::array<Image, 1> Apply(std::array<Image, 2> original);
}; 
}
#endif   // FILTERS_DOUBLE_THRESHOLD_