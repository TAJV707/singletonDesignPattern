#include "filters/sobel_filter.h"
#include "filters/convolution_filter.h"

#include<cmath>
#include<limits>


namespace image_processing {

// convolution filter to tell how pixels are changing from left to right
ConvolutionFilter SobelFilter::kXConv(Kernel(3, 3, {
    -1, 0, 1,
    -2, 0, 2,
    -1, 0, 1
}));

// convolution filter to tell how pixels are changing from top to bottom
ConvolutionFilter SobelFilter::kYConv(Kernel(3, 3, {
     1,  2,  1,
     0,  0,  0,
    -1, -2, -1
}));


std::array<Image, 2> SobelFilter::Apply(std::array<Image, 1> original) {
    const Image iXimg = kXConv.Apply(original)[0];
    const Image iYimg = kYConv.Apply(std::move(original))[0];

    Image Intensity(iXimg.GetWidth(), iXimg.GetHeight());
    Image Direction(iXimg.GetWidth(), iXimg.GetHeight());

    Intensity.ForEachPixel([&](PixelLocation pixelLoc, RGBAPixel& pixel) {
        auto iX = iXimg.GetPixel(pixelLoc.col, pixelLoc.row).red;
        auto iY = iYimg.GetPixel(pixelLoc.col, pixelLoc.row).red;
        
        pixel.red = sqrt(iX * iX + iY * iY);
        pixel.green = sqrt(iX * iX + iY * iY);
        pixel.blue = sqrt(iX * iX + iY * iY);
        pixel.alpha = 1.0;
    });

    Direction.ForEachPixel([&](PixelLocation pixelLoc, RGBAPixel& pixel) {
        auto iX = iXimg.GetPixel(pixelLoc.col, pixelLoc.row).red;
        auto iY = iYimg.GetPixel(pixelLoc.col, pixelLoc.row).red;
        
        // find angle of pixel intensity change
        // atan2f32 is an arctan function that uses 32-bit floats
        auto angle = std::atan2(iY, iX);
        if (angle < 0) {
            angle += 2 * M_PI;
        }
        angle = fmod(angle, (2 * M_PI));

        pixel.red = angle;
        pixel.green = angle;
        pixel.blue = angle;
        pixel.alpha = 1.0;
    });


    // normalize intensity to go from 0 to 1
    Intensity.Normalize();
    Direction.Normalize();

    return {Intensity, Direction};
}

}
