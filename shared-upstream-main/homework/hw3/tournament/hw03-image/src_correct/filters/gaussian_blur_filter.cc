#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "filters/gaussian_blur_filter.h"

static constexpr double sqr(double x) {
    return x * x;
}

namespace image_processing {

GaussianBlurFilter::GaussianBlurFilter(int size, double sigma) {
    int k = size / 2;
    Kernel kernel(size, size);

    // The equation wants to use 1-based indexing, but the kernel class uses
    // zero based indexing, so our loop is from 1..=n (one based indexing) ...
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            // ... and we subtract 1 here for zero based indexing
            kernel.SetEntry(
                i - 1,
                j - 1,
                // This equation comes from wikipedia: 
                // https://en.wikipedia.org/wiki/Gaussian_blur
                (1 / (2 * M_PI * sigma * sigma)) * exp(
                    // the subexpressions (i - (k+1)) and (j - (k + 1)) represent
                    // distance from the center of the kernel. they transform
                    // matrix indexes into x/y for the wikipedia equation
                    -(sqr(i - (k + 1)) + sqr(j - (k + 1))) / (2 * sigma * sigma)
                )
            );
        }
    }
    kernel.Normalize();
    this->convFilter = std::move(ConvolutionFilter(kernel));
}

std::array<Image, 1> GaussianBlurFilter::Apply(std::array<Image, 1> img) {
    auto ret = this->convFilter.Apply(std::move(img));
    ret[0].Normalize();
    return ret;
}

}
