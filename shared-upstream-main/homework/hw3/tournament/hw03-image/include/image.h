#ifndef IMAGE_H_
#define IMAGE_H_

#include<memory>
#include<string>
#include<functional>

namespace image_processing {

/**
 * @brief RGBAPixel represents color using values between 0 and 1
 */
struct RGBAPixel {
    float red;
    float green;
    float blue;
    float alpha;

    RGBAPixel(float r = 0, float g = 0, float b = 0, float a = 1.0);

    float GetLuminance() const;

    RGBAPixel operator+(RGBAPixel color) const;

    RGBAPixel operator*(float scalar) const;

    RGBAPixel operator/(float scalar) const;

    bool operator==(const RGBAPixel& color);
};

struct PixelLocation {
    int row;
    int col;
    PixelLocation(int r, int c) : row(r), col(c) {};
};

std::ostream& operator<<(std::ostream &strm, const PixelLocation& pixelLoc);

/**
 * @brief Represents an image using RGBA color values
 */
class Image {
private:
    int width;
    int height;
    std::unique_ptr<RGBAPixel[]> buffer;

public:
    /**
     * @brief default constructor creates a 0x0 image (i.e it contains no pixels)
     */
    Image() : Image(0, 0) {};

    /**
     * @brief create a blank image with the given dimensions
     */
    Image(int width, int height);

    /**
     * @brief Load an image by filename
     */
    Image(const std::string& filename);
    /**
     * @brief Copy constructor
     */
    Image(const Image&);

    /**
     * @brief Move constructor
     * 
     * Often, it can be more memory-efficient to move an image with std::move
     * instead of copying it.
     */
    Image(Image&&);

    /**
     * @brief Saves the image to the given location
     */
    void SaveAs(const std::string& filename) const;
    /**
     * @brief Returns the height in pixels of the image
     */
    int GetHeight() const;
    /**
     * @brief Returns the width in pixels of the image
     */
    int GetWidth() const;

    /**
     * @brief Execute some lambda for each pixel in the image
     * 
     * The lambda will be provided with the (row, col) location of the pixel (PixelLocation) as well as 
     * a mutable reference to the pixel
     */
    void ForEachPixel(std::function<void(PixelLocation, RGBAPixel&)> mutator);
    /**
     * @brief Returns the pixel in the given x, y location
     */
    RGBAPixel GetPixel(int x, int y) const;
    /**
     * @brief Sets the pixel in the given x, y location to the given pixel
     */
    void SetPixel(int x, int y, RGBAPixel pix);

    /**
     * @brief Normalize the image
     */
    void Normalize();

    /**
     * @brief Copy assignment
     */
    Image& operator=(const Image&);

    /**
     * @brief Move assignment
     */
    Image& operator=(Image&&);

    // destructor not needed -- buffer will free itself
};

/**
 * @brief Write the value of an RGBAPixel to a string
 */
std::ostream& operator<<(std::ostream &strm, const RGBAPixel& pixel);

}

#endif // IMAGE_H_
