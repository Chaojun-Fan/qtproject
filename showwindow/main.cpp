#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;
void onMouse(int event, int x, int y, int flags, void* param);

int main()
{
    Mat image;
    cout <<"This image is " << image.rows<<" x "<<image.cols << endl;
    image = imread("puppy.jpg");
    cout <<"This image is " << image.rows<<" x "<<image.cols << endl;
    if(image.empty())
    {
        printf("image is empty\n" );
    }
    namedWindow("original Image");
    imshow("Original Image",image);

    Mat result;
    cv::flip(image,result,1);
    cout <<"This image is " << result.rows<<" x "<<result.cols << endl;
    namedWindow("Output Image");
    imshow("Output Image",result);

    imwrite("Output.bmp",result);
    result = imread("puppy.jpg",IMREAD_GRAYSCALE);
    namedWindow("Output2 Image");
    imshow("Output2 Image",result);
    imwrite("Output2.bmp",result);

    setMouseCallback("Original Image",onMouse,reinterpret_cast<void*>(&image));

    waitKey(0);

    return 0;
}
void onMouse(int event, int x, int y, int flags, void* param)
{
    Mat *im = reinterpret_cast<Mat*>(param);
    switch (event) {//call event
        case EVENT_LBUTTONDOWN:
            cout << "at(" << x << ","<< y <<") value is:"<<static_cast<int>
                    (im->at<uchar>(Point(x,y)))<<endl;
        break;
    }
}
