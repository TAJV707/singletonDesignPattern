#include "filters/non_maximum_suppression.h"
#include "utils.h"

namespace image_processing {

std::array<Image, 1> NonMaximumSuppression::Apply(std::array<Image, 2> original){
    Image filtered(original[0]);

    // suppose original[0] is intensity matrix and original[1] is the direction matrix
    Image& intensity = original[0];
    Image& direction = original[1];

    auto clampI = [&](int i) { return utils::clamp(0, i, filtered.GetWidth() - 1); };
    auto clampJ = [&](int j) { return utils::clamp(0, j, filtered.GetHeight() - 1); };

    for (int i = 0; i < filtered.GetWidth(); ++i){
        for (int j = 0; j < filtered.GetHeight(); ++j){

            float x1 = 1;
            float x2 = 1;

            float this_angle = direction.GetPixel(i,j).red * 180.0/M_PI; // each channel is the angle
            if (this_angle < 0) this_angle += 180;
            float this_inten = intensity.GetPixel(i,j).red; // each channel is the intensity


            // 0*
            if ((this_angle >= 0 && this_angle < 22.5) || (this_angle >= 157.5 && this_angle <= 180)){
                    x1 = intensity.GetPixel(i, clampJ(j+1)).red;
                    x2 = intensity.GetPixel(i, clampJ(j-1)).red;
            }
            
            // 45*
            else if (this_angle >= 22.5 && this_angle < 67.5){
                    x1 = intensity.GetPixel(clampI(i+1), clampJ(j-1)).red;
                    x2 = intensity.GetPixel(clampI(i-1), clampJ(j+1)).red;
            }
            
            // 90*
            else if (this_angle >= 67.5 && this_angle < 112.5){
                    x1 = intensity.GetPixel(clampI(i+1), clampJ(j)).red;
                    x2 = intensity.GetPixel(clampI(i-1), clampJ(j)).red;
            }
            
            // 135*
            else if (this_angle >= 112.5 && this_angle < 157.5){
                    x1 = intensity.GetPixel(clampI(i-1), clampJ(j-1)).red;
                    x2 = intensity.GetPixel(clampI(i+1), clampJ(j+1)).red;
            }


            if (this_inten >= x1 && this_inten >= x2){
                filtered.SetPixel(i,j, intensity.GetPixel(i,j));
            } else{
                filtered.SetPixel(i,j, 0);
            }
        }
    }

    return {filtered};
}

}    
