#ifndef SCAN_IMAGE_H
#define SCAN_IMAGE_H


#include <opencv2/opencv.hpp>
#include <iostream>


void scanImageEfficiet(cv::Mat image);
void scanImageEfficiet32S(cv::Mat image);
void scanImageEfficiet8U(cv::Mat image);
std::string ThreeDigits(int val);


#endif
