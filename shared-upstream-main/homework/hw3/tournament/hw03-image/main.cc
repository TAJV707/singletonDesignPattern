#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <sys/stat.h>

#include "image.h"
#include "filters/greyscale_filter.h"
#include "filters/gaussian_blur_filter.h"
#include "filters/sobel_filter.h"
#include "filters/non_maximum_suppression.h"
#include "filters/double_threshold.h"
#include "filters/hysteresis_filter.h"
#include "filters/canny_edge_detect_filter.h"

using image_processing::Image;
using image_processing::RGBAPixel;
using image_processing::GreyScaleFilter;
using image_processing::SobelFilter;
using image_processing::GaussianBlurFilter;
using image_processing::NonMaximumSuppression;
using image_processing::DoubleThreshold;
using image_processing::HysteresisFilter;
using image_processing::CannyEdgeDetectFilter;

int main(const int argc, const char* argv[]) {
	if (argc < 2) {
		// argv[0] is the name of this binary
		std::cout << "Usage: " << argv[0] << " <input file path> <output file path>" << std::endl;
		return 1;
	}

	std::string inputFile(argv[1]);
    std::string outputFile(argv[2]);

	Image inputImage(inputFile);
	auto cannyEdgeDetection = CannyEdgeDetectFilter();

	GreyScaleFilter gf;

	Image outputImage = cannyEdgeDetection.Apply({inputImage})[0];
	outputImage.SaveAs(outputFile);
	std::cout << "Wrote output file to " << outputFile << std::endl;
	return 0;
}
