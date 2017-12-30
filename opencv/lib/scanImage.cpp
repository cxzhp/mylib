#include "scanImage.h"

//scanImageEfficiet(Mat);
void scanImageEfficiet(cv::Mat image){

    // channels of the image
    int iChannels = image.channels();

    // rows(height) of the image
    int iRows = image.rows;

    // cols(width) of the image
    int iCols = image.cols * iChannels;

    // check if the image data is stored continuous
    if (image.isContinuous()){
        iCols *= iRows;
        iRows = 1;
    }

    uchar* p;
    for (int i=0; i<iRows; i++){
        // get the pointer to the ith row
        p = image.ptr<uchar>(i);
        // operates on each pixel
        for (int j=0; j<iCols; j++){
            // assigns new value
            int imgPixel = (int)p[j]; //change pixcel data to int datatype
            std::cout << i << " " << j  << " "<< imgPixel << std::endl;
        }
    }

}

