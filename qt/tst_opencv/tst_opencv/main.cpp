#include <QCoreApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cv::VideoCapture capture;

    // Mat 转化为jpg

    capture.open(6);  //打开摄像头，只要一个摄像头，默认是0; 笔记本上有自带的摄像头,再插入usb摄像头应该是1

    if(!capture.isOpened())  //打开摄像头
    {
        std::cout<<"video not open";

    }else{
         std::cout<<"video  open";
    }

    return a.exec();
}
