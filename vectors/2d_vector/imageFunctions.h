#ifndef IMAGE_FUNCTIONS_H
#define IMAGE_FUNCTIONS_H

#include <string>
#include <vector>

// a Pixel struct representing a single red, green, blue pixel value for an image
struct Pixel {
  unsigned int r = 0; // red
  unsigned int g = 0; // green
  unsigned int b = 0; // blue
};

void processImage(char choice, std::vector<std::vector<Pixel> >& image);

bool loadImage(const std::string filename, std::vector<std::vector<Pixel> >& image);

bool outputImage(const std::string filename, const std::vector<std::vector<Pixel> >& image);

void grayscaleImage(std::vector<std::vector<Pixel> >& image);

void sepiaImage(std::vector<std::vector<Pixel> >& image);

void invertImage(std::vector<std::vector<Pixel> >& image);

void invertGrayscaleImage(std::vector<std::vector<Pixel> >& image);

#endif
