#include "gtest/gtest.h"

#include "image.h"
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
using image_processing::PixelLocation;

class ImageProcessingTest : public ::testing::Test {
 public:
  void SetUp( ) {

  }
  void TearDown() {

  }
 protected:
    
};

TEST_F(ImageProcessingTest, ImageHasContentTest) {

}

