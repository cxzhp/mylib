#include "scanImage.h"
#include "formatConvert.h"


//CV_8U = 0, 8-bit unsigned integer (uchar)
//CV_8S = 1, 8-bit   signed integer (schar)
//CV_16U = 2, 16-bit   unsigned integer (ushort)
//CV_16S = 3, 16-bit     signed integer (short)
//CV_32S = 4, 32-bit     signed integer (int)
//CV_32F = 5, 32-bit   floating-point number(float)
//CV_64F = 6, 64-bit   floating-point number(double)


//scanImageEfficiet(Mat);
void scanImageEfficiet(cv::Mat I){

    if(I.depth() == CV_32S){
        return scanImageEfficiet32S(I);
    }

    if(I.depth() == CV_8U){
        return scanImageEfficiet8U(I);
    }

    
    std::cout << "bad CvType." << std::endl;

}



void scanImageEfficiet8U(cv::Mat I){

    // accept only uchar type matrices
    CV_Assert(I.depth() == CV_8U);

    std::cout << "==== in scanImageEfficiet8U." << std::endl;

    // channels of the image
    int channels = I.channels();

    // rows(height) of the image
    int nRows = I.rows;
    // cols(width) of the image
    int nCols = I.cols * channels;
    int nInitCols = nCols;


    std::cout << "==== channels:" << channels << std::endl;
    std::cout << "==== nInitCols:" << nInitCols << std::endl;


    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;

            int i,j;
            uchar* p;
            int offset = 0;

            for( i = 0; i < nRows; ++i)
            {
                    p = I.ptr<uchar>(i);
                    for ( j = 0; j < nCols; ++j)
                    {
                            int virtualRow = floor(offset / nInitCols);
                            int virtualCol = offset % nInitCols;

                            if(offset % nInitCols == 0){
                                //std::cout <<   "==== next Row."  << std::endl;
                                std::cout << "|";
                                std::cout << std::endl;
                            }
                            //std::cout << "==== row:" << virtualRow << "  col:" << virtualCol  << "  " << (int)p[j] << std::endl;
                            std::cout << "|"<< ThreeDigits((int)p[j]);


                            offset++;
                    }
            }


    }else{

            int i,j;
            uchar* p;
            for( i = 0; i < nRows; ++i)
            {
                    p = I.ptr<uchar>(i);
                    for ( j = 0; j < nCols; ++j)
                    {
                            //std::cout << "==== row:" << i << "  col:" << j  << "  " << (int)p[j] << std::endl;
                            std::cout << "|"<< ThreeDigits((int)p[j]);
                    }
                    //std::cout <<   "==== next Row."  << std::endl;
                    std::cout << "|";
                    std::cout << std::endl;
            }

    }
}




void scanImageEfficiet32S(cv::Mat I){

    // accept only int type matrices
    CV_Assert(I.depth() == CV_32S);


    std::cout << "==== in scanImageEfficiet32S." << std::endl;
    std::cout << "==== I.depth:" << I.depth() << std::endl;


    // channels of the image
    int channels = I.channels();

    // rows(height) of the image
    int nRows = I.rows;
    // cols(width) of the image
    int nCols = I.cols * channels;
    int nInitCols = nCols;


    std::cout << "==== channels:" << channels << std::endl;
    std::cout << "==== nInitCols:" << nInitCols << std::endl;


    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;

            int i,j;
            int* p;
            int offset = 0;

            for( i = 0; i < nRows; ++i)
            {
                    p = I.ptr<int>(i);
                    for ( j = 0; j < nCols; ++j)
                    {
                            int virtualRow = floor(offset / nInitCols);
                            int virtualCol = offset % nInitCols;

                            if(offset % nInitCols == 0){
                                //std::cout <<   "==== next Row."  << std::endl;
                                std::cout << "|";
                                std::cout << std::endl;
                            }
                            //std::cout << "==== row:" << virtualRow << "  col:" << virtualCol  << "  " << (int)p[j] << std::endl;
                            std::cout << "|"<< ThreeDigits((int)p[j]);


                            offset++;
                    }
            }


    }else{

            int i,j;
            int* p;
            for( i = 0; i < nRows; ++i)
            {
                    p = I.ptr<int>(i);
                    for ( j = 0; j < nCols; ++j)
                    {
                            //std::cout << "==== row:" << i << "  col:" << j  << "  " << (int)p[j] << std::endl;
                            std::cout << "|"<< ThreeDigits((int)p[j]);
                    }
                    //std::cout <<   "==== next Row."  << std::endl;
                    std::cout << "|";
                    std::cout << std::endl;
            }

    }
}



std::string ThreeDigits(int val){

    if(val < 0){
        return " " + intToString(val);
    }

    if(val < 10){
        return "00" + intToString(val);
    }

    if(val < 100){
        return "0" + intToString(val);
    }

    return intToString(val);
}
