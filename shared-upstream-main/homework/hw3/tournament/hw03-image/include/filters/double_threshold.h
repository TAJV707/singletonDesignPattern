#ifndef _DOUBLE_THRESHOLD_
#define _DOUBLE_THRESHOLD_


/************************************************************************************
 * includes
 * *********************************************************************************/
#include "filter.h"



namespace image_processing {

/***********************************************************************************
 * Class Definitions
 **********************************************************************************/

/**
 * @brief Class representing the Double Threshold Filter used by a canny edge detector
 */

class DoubleThreshold : public Filter<1, 1> {
public: 

    /**
      * @brief a constructor for double threshold filter. It sets highthreshold to thresh1 and 
      *        low threshold to thresh2
      * 
      */
    DoubleThreshold(
      double low,
      double high,
      double strong,
      double weak
    ) : strong(strong),
        weak(weak),
        lowThresholdRatio(low), 
        highThresholdRatio(high) {}

    /**
    * @brief Given the result of non-max image, reduce the range of values in the image's pixels 
    *        to either strong, weak, or zero. It uses high and low threshold values to divide 
    *        pixels into strong, weak, or zero.  
    * 
    * @return return an image with pixel values of strong, weak, or zero
    */
    std::array<Image, 1> Apply(std::array<Image, 1> original);
        

private: 
    double highThresholdRatio;
    double lowThresholdRatio;
    double strong;
    double weak;
}; 

}

#endif  // FILTERS_DOUBLE_THRESHOLD_