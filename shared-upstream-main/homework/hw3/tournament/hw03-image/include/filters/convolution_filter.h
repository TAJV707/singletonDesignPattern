#ifndef FILTERS_CONVOLUTION_FILTER_H__
#define FILTERS_CONVOLUTION_FILTER_H__

#include <vector>
#include "filter.h"

namespace image_processing {

/**
 * @brief Class representing the kernel used by a ConvolutionFilter
 */
class Kernel {
private:
    int width;
    int height;
    std::vector<double> values;
public:
    /**
     * @brief Creates the identity kernel (a 1x1 matrix with containing the number 1)
     */
    Kernel() : Kernel(1, 1, std::vector<double> {1,}) {};

    /**
     * @brief Create a kernel with the specified width and height containing all 0's
     * 
     * both `width` and `height` must be odd
     */
    Kernel(int width, int height);

    /**
     * @brief Create a kernel with the specified width and height containing the
     * given values
     * 
     * both `width` and `height` must be odd
     * additionally, `values` must have a length of `width * height` 
     */
    Kernel(int width, int height, std::vector<double> values);

    double GetEntry(int row, int col) const;
    void SetEntry(int row, int col, double value);
    int GetNumCols() const { return width; }
    int GetNumRows() const { return height; }

    /**
     * @brief Divide the matrix by the sum of its values. The result is that
     * all values in the matrix will then add up to 1
     */
    void Normalize();
};

std::ostream& operator<<(std::ostream &strm, const Kernel& kernel);

/**
 * @brief This filter convolves a Kernel across an image
 */
class ConvolutionFilter : public Filter<1, 1> {
private:
    Kernel kernel;
public:

    /**
     * @brief Create a convolution filter with the identity Kernel
     */
    ConvolutionFilter() : kernel() {}

    /**
     * @brief Create a convolution filter with the given kernel
     */
    ConvolutionFilter(Kernel kernel);

    /**
     * @brief Create a new image through convolution
     * 
     * The kernel is moved around the image. Each pixel in the output image
     * is a weighted average of the pixels in the input image that are near the
     * same location. The weights are determined by the kernel.
     */
    std::array<Image, 1> Apply(std::array<Image, 1> original) override;
};

}

#endif // FILTERS_CONVOLUTION_FILTER_H__