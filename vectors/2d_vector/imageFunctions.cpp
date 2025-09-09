#include <iostream>
#include <fstream>

#include "imageFunctions.h"

using std::cin, std::cout, std::endl;
using std::ofstream, std::ifstream;
using std::string;
using std::vector;


/*  Function processImage
 *  choice: char representing which type of image processing to perform
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none
 */
// You should not modify this function unless you add another processing option. //
void processImage(char choice, vector<vector<Pixel> >& image)
{
    // get filename, width and height from user
    string originalImageFilename;
    cout << "Image filename: ";
    cin >> originalImageFilename;
  
    // load image
    if(!loadImage(originalImageFilename, image)) {
        cout << "Image did not load, returning." << endl;
        return;
    }
  
    string outputImageFilename;
 
    // modify image
    switch (toupper(choice))
    {
        case 'G':
            grayscaleImage(image);
            outputImageFilename = "grey." + originalImageFilename;
            break;
        case 'S':
            sepiaImage(image);
            outputImageFilename = "sepia." + originalImageFilename;
            break;
        case 'I':
            invertGrayscaleImage(image);
            outputImageFilename = "invert_grey." + originalImageFilename;
            break;
        case 'N':
            invertImage(image);
            outputImageFilename = "invert." + originalImageFilename;
            break;
    }
  
    // output image
    outputImage(outputImageFilename, image);
}


/*  Function loadImage
 *  filename: string which is the ppm file to read
 *  image: 2d-vector of Pixels (structs)
 *  return: true if load successful, false otherwise; but image array should be loaded with values from file
 */
// You should not modify this function. //
bool loadImage(const string filename, vector<vector<Pixel> >& image)
{
    cout << "Loading image..." << endl;
    ifstream ifs(filename); // input file stream opened with filename 
  
    // check if it's open
    if (!ifs.is_open()) {
        cout << "Unable to open file: " + filename << endl;
        return false;
    }
  
    // we were able to open the file
  
    // read in Image type, for us it must be P3
    string type;
    ifs >> type;
  
    // read in width and height
    unsigned int width = 0, height = 0;
    ifs >> width >> height;

    // initalize image Pixels
    image.clear();
    for (unsigned int row=0; row < height; ++row) {
        image.push_back(vector<Pixel>(width, Pixel({0,0,0})));
    }

    // read in maximum color value, for us it must be 255
    unsigned int maxColor = 0;
    ifs >> maxColor;
  
    // read the color values into the 2D vector
    for (unsigned int row=0; row < height; ++row) {
        vector<Pixel> column;
        for (unsigned int col=0; col < width; ++col) {
            ifs >> image.at(row).at(col).r;
            ifs >> image.at(row).at(col).g;
            ifs >> image.at(row).at(col).b;
        }
    }

    return true;
}


/*  Function outputImage
 *  filename: string which is the ppm file to write
 *  image: 2d-vector of Pixels (structs)
 *  Return value: true if output successful, false otherwise; but ppm file should be created
 */
// You should not modify this function. //
bool outputImage(const string filename, const vector<vector<Pixel> >& image)
{
    cout << "Outputting image..." << endl;
  
    // open output file
    ofstream ofs(filename);
  
    if (!ofs.is_open()) {
        cout << "Unable to create output file: " + filename << endl;
        return false;
    }
  
    // output image type, P3 for us
    ofs << "P3" << endl;
  
    // output width and height, don't forget to separate by a space
    ofs << image.at(0).size() << " " << image.size() << endl;
  
    // output max color value, for us 255
    ofs << 255 << endl;
  
    // output into row major PPM file
    for (unsigned int row=0; row < image.size(); ++row) {
        for (unsigned int col=0; col < image.at(row).size(); ++col) {
            ofs << image.at(row).at(col).r << " ";
            ofs << image.at(row).at(col).g << " ";
            ofs << image.at(row).at(col).b << " ";
        }
      ofs << endl;
    }

    return true;
}


/*  Function grayscale
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be grayscale colors
 * 
 *  Note: computing grayscale as the average of the R,G,B chanels for each pixel
 */
void grayscaleImage(vector<vector<Pixel> >& image)
{
    cout << "Making grayscale image... " << endl;
    
    // iterate through 2d image of Pixels and convert them to grayscale
    // use opposite outer loop than load and output just to be different
    for (unsigned int row=0; row < image.size(); ++row) {
        for (unsigned int col=0; col < image.at(row).size() ; ++col) {
            unsigned int newColor = (image.at(row).at(col).r + image.at(row).at(col).g + image.at(row).at(col).b)/3;
            image.at(row).at(col) = {newColor, newColor, newColor};
        }
    }
}


/*  Function sepiaImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be sepia colors
 *
 *  Note: compute sepia as follows for each pixel:
 *        new red =   0.393 * red + 0.768 * green + 0.189 * blue
 *        new green = 0.349 * red + 0.686 * green + 0.168 * blue
 *        new blue =  0.272 * red + 0.534 * green + 0.131 * blue
 *        remember that the max color we allow is 255
 */
// You should write this function. //
void sepiaImage(vector<vector<Pixel> >& image)
{
    cout << "Making sepia image... " << endl;
    cout << "  ... TBD" << endl;
    
}


/*  Function invertGrayscaleImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be invert grayscale
 */
// You should write this function. //
void invertImage(vector<vector<Pixel> >& image)
{
    cout << "Making invert image... " << endl;
    cout << " ... TBD" << endl;
}


/*  Function invertGrayscaleImage
 *  image: 2d-vector of Pixels (structs)
 *  Return value: none, but image should be modified to be invert grayscale
 */
// You should write this function. //
void invertGrayscaleImage(vector<vector<Pixel> >& image)
{
  cout << "Making invert grayscale image... " << endl;
  cout << " ... TBD" << endl;
}
