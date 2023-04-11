#include "utils.h"

namespace utils {

int clamp(int low, int x, int high) {
    if (x < low) {
        return low;
    } else if (x > high) {
        return high;
    } else {
        return x;
    }
}

}
