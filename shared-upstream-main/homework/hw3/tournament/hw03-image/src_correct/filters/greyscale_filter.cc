#include "filters/greyscale_filter.h"

namespace image_processing {

std::array<Image, 1> GreyScaleFilter::Apply(std::array<Image, 1> original) {
    original[0].ForEachPixel([](PixelLocation pixelLoc, RGBAPixel& pixel) {
        double luminance = pixel.GetLuminance();
        pixel.red = luminance;
        pixel.green = luminance;
        pixel.blue = luminance;
    });
    return original;
}

}