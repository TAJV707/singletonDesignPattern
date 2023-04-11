#include<cstring>
#include<string>
#include "image.h"

// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>

namespace image_processing {

RGBAPixel::RGBAPixel(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {}

float RGBAPixel::GetLuminance() const  {
    float luminance = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
    return luminance;
}

RGBAPixel RGBAPixel::operator+(RGBAPixel color) const  {
    float newRed = red + color.red;
    float newGreen = green + color.green; 
    float newBlue = blue + color.blue;  
    float newAlpha = alpha + color.alpha;

    return RGBAPixel(newRed, newGreen, newBlue, newAlpha); 
}

RGBAPixel RGBAPixel::operator*(float scalar) const {
    float newRed = red * scalar; 
    float newGreen = green * scalar; 
    float newBlue = blue * scalar; 
    float newAlpha = alpha * scalar; 

    return RGBAPixel(newRed, newGreen, newBlue, newAlpha); 
}

RGBAPixel RGBAPixel::operator/(float scalar) const {
    return *this * (1/scalar);
}

bool RGBAPixel::operator==(const RGBAPixel& color) {
    return red == color.red && green == color.green && blue == color.blue && alpha == color.alpha; 
}

Image::Image(int w, int h) : width(w), height(h) {
    this->buffer = std::unique_ptr<RGBAPixel[]> (new RGBAPixel[w * h]);
    for (int i = 0; i < w * h; i++) {
        this->buffer[i] = RGBAPixel();
    }
}

Image::Image(const std::string& filename) {
    int components;
    unsigned char* image = stbi_load(filename.c_str(), &this->width, &this->height, &components, STBI_rgb_alpha);
    components = 4;

    this->buffer = std::unique_ptr<RGBAPixel[]> (new RGBAPixel[this->width * this->height]);
    // Loop through the image pixels and modify values
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Get the pixel as a byte array
            unsigned char *pixel = &image[(row * width + col) * 4];
            RGBAPixel rgbaPixel(
                static_cast<float>(pixel[0]) / 255,
                static_cast<float>(pixel[1]) / 255,
                static_cast<float>(pixel[2]) / 255,
                static_cast<float>(pixel[3]) / 255
            );
            this->buffer[(row * width) + col] = rgbaPixel;
        }
    }

    stbi_image_free(image);
}

Image::Image(const Image& to_copy) {
    *this = to_copy;
}

Image::Image(Image&& to_take) {
    *this = std::move(to_take);
}

Image& Image::operator=(const Image& to_copy) {
    this->width = to_copy.width;
    this->height = to_copy.height;
    std::unique_ptr<RGBAPixel[]> cloned_buffer(new RGBAPixel[to_copy.width * to_copy.height]);
    std::memcpy(cloned_buffer.get(), to_copy.buffer.get(), sizeof(RGBAPixel) * to_copy.width * to_copy.height);
    this->buffer = std::move(cloned_buffer);
    return *this;
}

Image& Image::operator=(Image&& to_take) {
    this->width = to_take.width;
    this->height = to_take.height;
    this->buffer = std::move(to_take.buffer);
    return *this;
}

void Image::SaveAs(const std::string& filename) const {
    std::unique_ptr<unsigned char[]> stbi_image(new unsigned char[width * height * 4]);
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            RGBAPixel pixel = this->GetPixel(col, row);
            unsigned char* stbi_pixel = &stbi_image[(row * width + col) * 4];
            stbi_pixel[0] = static_cast<unsigned char>(pixel.red * 255);
            stbi_pixel[1] = static_cast<unsigned char>(pixel.green * 255);
            stbi_pixel[2] = static_cast<unsigned char>(pixel.blue * 255);
            stbi_pixel[3] = static_cast<unsigned char>(pixel.alpha * 255);
        }
    }
    stbi_write_png(filename.c_str(), width, height, 4, stbi_image.get(), width * 4);
}

RGBAPixel Image::GetPixel(int x, int y) const {
    return this->buffer[(y * width) + x];
}

void Image::ForEachPixel(std::function<void(PixelLocation, RGBAPixel&)> mutator) {
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            mutator(PixelLocation(row, col), this->buffer[row * width + col]);
        }
    }
}

void Image::SetPixel(int x, int y, RGBAPixel pix) {
    int idx = (y * width) + x;
    if (idx < width * height) {
        this->buffer[idx] = pix;
    }
}

int Image::GetWidth() const {
    return this->width;
}

int Image::GetHeight() const {
    return this->height;
}

void Image::Normalize() {
    RGBAPixel maxRGB;

    ForEachPixel([&](PixelLocation loc, RGBAPixel& pix) {
        if (pix.red > maxRGB.red) {
            maxRGB.red = pix.red;
        }
        if (pix.green > maxRGB.green) {
            maxRGB.green = pix.green;
        }
        if (pix.blue > maxRGB.blue) {
            maxRGB.blue = pix.blue;
        }
    });

    ForEachPixel([&](PixelLocation loc, RGBAPixel& pix) {
        if (maxRGB.red > 0) {
            pix.red /= maxRGB.red;
        }
        if (maxRGB.green > 0) {
            pix.green /= maxRGB.green;
        }
        if (maxRGB.blue > 0) {
            pix.blue /= maxRGB.blue;
        }
    });
}

std::ostream& operator<<(std::ostream &strm, const RGBAPixel& pixel) {
    return strm << "RGBAPixel { red = " << static_cast<int>(pixel.red) 
                << ", green = " <<  static_cast<int>(pixel.green) 
                << ", blue = "  << static_cast<int>(pixel.blue) 
                << ", alpha = " <<  static_cast<int>(pixel.alpha) 
                << "}";
}

std::ostream& operator<<(std::ostream &strm, const PixelLocation& pixelLoc) {
    return strm << "PixelLocation { row = " << pixelLoc.row << ", col = " << pixelLoc.col << " }";
}

}
