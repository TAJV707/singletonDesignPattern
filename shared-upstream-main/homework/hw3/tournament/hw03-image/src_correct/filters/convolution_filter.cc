#include "filters/convolution_filter.h"
#include "utils.h"
#include<stdexcept>
#include<iostream>
#include<array>

namespace image_processing {

Kernel::Kernel(int width, int height) : width(width), height(height) {
    if (width % 2 == 0 || height % 2 == 0) {
        throw std::invalid_argument("Kernel constructor was provided with even width/height values, they must be odd");
    } 
    values = std::vector<double>(width * height, 0);
}

Kernel::Kernel(int w, int h, std::vector<double> values) : Kernel(w, h) {
    if (values.size() != width * height) {
        throw std::invalid_argument("Kernel constructor was provided with a set of values that is not width*height large");
    }
    this->values = std::move(values);
}

std::ostream& operator<<(std::ostream &strm, const Kernel& kernel) {
    double sum = 0;
    strm << "Kernel(" << kernel.GetNumRows() << ", " << kernel.GetNumCols() << ") {";
    for (int r = 0; r < kernel.GetNumRows(); r++) {
        strm << std::endl << "  ";
        for (int c = 0; c < kernel.GetNumCols(); c++) {
            auto entry = kernel.GetEntry(r, c);
            strm << entry << ", ";
            sum += entry;
        }
    }
    strm << std::endl << "}" << " (sum: " << sum << ")" << std::endl;
    return strm;
}


double Kernel::GetEntry(int row, int column) const {
    return values[(row * width) + column];
}

void Kernel::SetEntry(int row, int column, double value) {
    values[(row * width) + column] = value;
}

void Kernel::Normalize() {
    double sum = 0;
    double rows = this->GetNumRows(), cols = this->GetNumCols();
    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            sum += this->GetEntry(r, c);
        }
    }
    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < cols; c++) {
            this->SetEntry(r, c, this->GetEntry(r, c) / sum);
        }
    }
}

ConvolutionFilter::ConvolutionFilter(Kernel kernel) : kernel(std::move(kernel)) {}

std::array<Image, 1> ConvolutionFilter::Apply(const std::array<Image, 1> to_convolve) {
    const Image& old_image = to_convolve[0];
    Image new_image(old_image);
    new_image.ForEachPixel([&](PixelLocation pixelLoc, RGBAPixel& pixel) {
        RGBAPixel sum;

        int row_delta = this->kernel.GetNumRows() / 2;
        int col_delta = this->kernel.GetNumCols() / 2;
        for (int kernel_r = 0; kernel_r < kernel.GetNumRows(); kernel_r++) {
            for(int kernel_c = 0; kernel_c < kernel.GetNumCols(); kernel_c++) {
                double kernel_val = kernel.GetEntry(kernel_r, kernel_c);
                int image_r = utils::clamp(0, pixelLoc.row - row_delta + kernel_r, old_image.GetHeight() - 1);
                int image_c = utils::clamp(0, pixelLoc.col - col_delta + kernel_c, old_image.GetWidth() - 1);

                auto pixel_for_kernel = old_image.GetPixel(image_c, image_r);
                sum = sum + (pixel_for_kernel * kernel_val);
            }
        }

        pixel = sum;
    });

    return {new_image};
}

}