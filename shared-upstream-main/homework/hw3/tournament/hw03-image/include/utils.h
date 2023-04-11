#ifndef UTILS_H__
#define UTILS_H__

namespace utils {

/**
* @brief Ensures the val is in between the low and high value
*
* @returns The val if high < val > low, otherwise returns high if val > high or low if val < high
*/
int clamp(int val, int low, int high);

}

#endif // UTILS_H__