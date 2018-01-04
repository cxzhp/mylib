/**
 * @function Watershed_and_Distance_Transform.cpp
 * @brief Sample code showing how to segment overlapping objects using Laplacian filtering, in addition to Watershed and Distance Transformation
 * @author OpenCV Team
 */


//g++ -o test imageSegmentation.cpp -I /usr/local/include/opencv -L /usr/local/lib/ -lopencv_highgui -lopencv_core -lopencv_imgcodecs -lopencv_imgproc
//./test ../../data/cards.png


#include <opencv2/opencv.hpp>
#include <iostream>

#include "../lib/scanImage.h"

using namespace std;
using namespace cv;

int main(int, char** argv)
{
//! [load_image]
    // Load the image
    Mat src = imread(argv[1]);

    // Check if everything was fine
    if (!src.data)
        return -1;

    // Show source image
    imshow("Source Image", src);
    //scanImageEfficiet(src);


//! [load_image]

//! [bin]
    // Create binary image from source image
    Mat bw;
    cvtColor(src, bw, CV_BGR2GRAY);
    threshold(bw, bw, 40, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    imshow("Binary Image", bw);

    //scanImageEfficiet(bw);
//! [bin]

//! [dist]
    // Perform the distance transform algorithm
    Mat dist;
    Mat distN;
    distanceTransform(bw, dist, CV_DIST_L2, 3);
    scanImageEfficiet(dist);
    imshow("Distance Transform Image_0", dist);

    // Normalize the distance image for range = {0.0, 1.0}
    // so we can visualize and threshold it
    normalize(dist, distN, 0, 1., NORM_MINMAX);
    imshow("Distance Transform Image", distN);
    scanImageEfficiet(distN);
//! [dist]


    waitKey(0);
    return 0;
}
