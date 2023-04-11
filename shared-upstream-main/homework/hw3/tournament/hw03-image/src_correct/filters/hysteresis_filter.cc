#include "filters/hysteresis_filter.h"
#include "utils.h"

namespace image_processing {

using utils::clamp;

std::array<Image, 1> HysteresisFilter::Apply(std::array<Image, 1> original) {
    auto isStrong = [&](RGBAPixel pix) { return pix.red > weak; };
    auto isWeak = [&](RGBAPixel pix) { return pix.red < strong && pix.red > 0; };

    Image new_image(original[0]);
    for (int y = 0; y < original[0].GetHeight(); y++) {
        for(int x = 0; x < original[0].GetWidth(); x++) {
            if(isWeak(original[0].GetPixel(x, y).red)){

                int topClamp = clamp(0, y + 1, original[0].GetHeight() - 1);
                int bottomClamp = clamp(0, y - 1, original[0].GetHeight() - 1);
                int leftClamp = clamp(0, x - 1, original[0].GetWidth() - 1);
                int rightClamp = clamp(0, x + 1, original[0].GetWidth() - 1);

                if (isStrong(original[0].GetPixel(rightClamp, y).red == strong) || isStrong(original[0].GetPixel(leftClamp, y)) ||
                    isStrong(original[0].GetPixel(x, bottomClamp)) || isStrong(original[0].GetPixel(x, topClamp)) ||
                    isStrong(original[0].GetPixel(leftClamp, topClamp)) || isStrong(original[0].GetPixel(leftClamp, bottomClamp)) ||
                    isStrong(original[0].GetPixel(rightClamp, topClamp)) || isStrong(original[0].GetPixel(rightClamp, bottomClamp)))
                {
                    new_image.SetPixel(x, y, RGBAPixel(strong, strong, strong));
                }
                else{
                    new_image.SetPixel(x, y, RGBAPixel(0, 0, 0));
                }
            }
        }
    }
    return {new_image};
}

}