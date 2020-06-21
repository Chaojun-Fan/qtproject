#include <iostream>
#include <random>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void salt(Mat image, int n);

int main()
{
    Mat image = imread("puppy.jpg");
    salt(image,1000);

    namedWindow("Image");
    imshow("Image",image);

    waitKey(0);

    return 0;
}
void salt(Mat image, int n)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> randomRow(0,image.rows-1);
    std::uniform_int_distribution<int> randomCol(0,image.cols-1);
    int i, j;
    for (int k=0;k<n;k++)
    {
        //random generator image's location
        i = randomCol(generator);
        j = randomRow(generator);
        if(image.type() == CV_8UC1)//gray image
        {
            //singl channel 8 bitmap
            image.at<uchar>(j,i) = 255;
        }
        else if (image.type()==CV_8UC3)//color image
        {
            //three channel image
            image.at<Vec3b>(j,i)[0] = 255;
            image.at<Vec3b>(j,i)[1] = 255;
            image.at<Vec3b>(j,i)[2] = 255;
        }
    }
}
