#ifndef __bmp_image
#define __bmp_image

class PcxImage;

class BmpImage{
public:
    BmpImage();
    ~BmpImage();
    void readBmpFile(char *filename);  // Load image from a BMP file
    void writeBmpFile(char *filename); // Save image to a BMP file
    void allocMemory();                // Create memory for the image
    void resetData();
    void copyFromPcx(PcxImage *pcx);
    unsigned char *data;               // Image data
    int width;                         // Image width
    int height;                        // Image height
private:
    int memCreated;
};

#endif

