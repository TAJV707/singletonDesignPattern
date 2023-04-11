#include "filters/double_threshold.h"
#include <iostream>

namespace image_processing {

std::array<Image, 1> DoubleThreshold::Apply(std::array<Image, 1> original){
    Image newImage(original[0]);
        //calculating the maximum value in the intensity 
        float max = 0; 
        original[0].ForEachPixel([&](PixelLocation pixelLoc, RGBAPixel& pixel) {
            if (pixel.red > max)
                max = pixel.red; 
        }); 
        
        float highThreshold = max*highThresholdRatio;
        float lowThreshold = highThreshold*lowThresholdRatio; 
               
        original[0].ForEachPixel([&](PixelLocation pixelLoc, RGBAPixel& pixel) {
                int i = pixelLoc.col; 
                int j = pixelLoc.row; 
                float pixVal = pixel.red;  
                if(pixVal >= highThreshold)
                    newImage.SetPixel(i,j, RGBAPixel(strong, strong, strong)) ; 
                else if (pixVal <= highThreshold && pixVal >= lowThreshold)
                    newImage.SetPixel(i,j, RGBAPixel(weak, weak, weak)) ;
                else 
                    newImage.SetPixel(i,j, RGBAPixel(0, 0, 0)) ;
            
        }); 

    return {newImage};      
}



}