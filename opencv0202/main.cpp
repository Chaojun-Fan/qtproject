#include <iostream>
#include <random>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void colorReduce(Mat image, int div);

int main()
{
    Mat image = imread("puppy.jpg");
    colorReduce(image,64);

    namedWindow("Image");
    imshow("Image",image);

    waitKey(0);

    return 0;
}
void colorReduce(Mat image, int div=64)
{
    int nl = image.rows;
    //element number per row
    int nc = image.cols * image.channels();
    for(int j=0;j<nl;j++)
    {
        //gain j's address
        uchar* data=image.ptr<uchar>(j);

        for(int i=0; i<nc; i++)
        {
            //handle per element
            data[i] = data[i]/div*div +div/2;

            //handled element
        }//finished a cloumn
    }
}
