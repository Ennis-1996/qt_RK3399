#include <QCoreApplication>

#include <dlfcn.h>
#include <stdio.h>
#include <thread>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <inttypes.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



#include "BaiduRtcInterface.h"

#include "mat2img.h"
#include "image_base64.h"

using namespace cv;
using namespace std;

const char* Help =
"\
push_demo\n\
Copyright 2020 Baidu.com, Inc. All Rights Reserved.\n\
\n\
Usage:\n\
    ./push_demo $(APPID_GET_FROM_BAIDU)\n\
\n\
";

baidurtc::BaiduRtcRoomClient *g_BrtcClient = nullptr;
volatile bool g_StopFlag = false;


class myListener:public IRtcMessageListener
 {
    void OnRtcMessage(RtcMessage &msg) override
    {
        printf("========================myListener got Message: %d.==========================\n", msg.msgType);
        switch (msg.msgType)
        {
        case RtcMessageType::RTC_MESSAGE_ROOM_EVENT_REMOTE_COMING:
            {
                printf("Feed Coming %" PRId64 ", Name: %s.\n",msg.data.feedId,msg.extra_info);
            }
            break;
        case RtcMessageType::RTC_MESSAGE_ROOM_EVENT_REMOTE_LEAVING:
            {
                printf("Feed Leaving %" PRId64 ".\n",msg.data.feedId);
            }
            break;
        case RtcMessageType::RTC_MESSAGE_STATE_STREAM_UP:
            {
                printf("stream up, send video/audio now.\n");

                g_StopFlag = false;
/*
                std::thread([]()
                {
                    cv::VideoCapture capture;
                    // Mat 转化为jpg
                    std::vector<unsigned char> buff_jpg;
                    cv::Mat img; //定义一个矩阵接受帧
                    Mat image2;
                    capture.open(4);  //打开摄像头，只要一个摄像头，默认是0; 笔记本上有自带的摄像头,再插入usb摄像头应该是1

                    if(!capture.isOpened())  //打开摄像头
                    {
                        std::cout<<"video not open";

                    }
                    while(true){

                        capture>>img; //取出一帧

                        double scale=0.8;
                        Size dsize = Size(img.cols*scale,img.rows*scale);
                        image2 = Mat(dsize,CV_32S);
                        resize(img, image2,dsize);

                        int ret = Mat2Img::MatToByteArray(image2, buff_jpg);
                    // jpg 转化为Base64
                        std::string str = ImageBase64::encode(buff_jpg.data(), buff_jpg.size());
                    // Base64 字符串转化为jpg 的string
                        int outLen = 0;
                        std::string str1 = ImageBase64::decode(str.c_str(), str.size(), outLen);

    //                    cv::Mat MatFromBase;
    //                    std::vector<uchar> baseJpgVec;
    //                    // jpg string 拷贝到jpg 数组buffer
    //                    baseJpgVec.assign(&str1.data()[0], &str1.data()[outLen]);
    //                    //jpg buffer 转化为Mat
    //                    Mat2Img::JPEGToMat(MatFromBase, baseJpgVec);

                        if (g_StopFlag) break;

                        if (!image2.empty()){
                            //std::cout << "str.str().length(): "<< str1.size() << std::endl;
                                g_BrtcClient->sendImage(str1.c_str(),str1.size());
                        }
                    }
                }).detach();
*/
                std::thread([]()
                {
                    std::fstream  fs("./mypcm.raw");
                    std::stringstream  ss;

                    ss << fs.rdbuf();
                    std::cout << "pcm.length(): "<< ss.str().length() << std::endl;
                    int t_len = ss.str().length();
                    int packet_len = (16000/100) *2*4;
                    int j = 0;

                    auto pre_send_time = std::chrono::system_clock::now();
                    for (int i=0;i <200000;i++) { //need streaming control.

                        g_BrtcClient->sendAudio(&ss.str()[j],packet_len);
                        std::this_thread::sleep_until(pre_send_time + ((i+1) * std::chrono::milliseconds(40)));
                        if (g_StopFlag) break;

                        j += packet_len;
                        if (j + packet_len > t_len) j = 0;
                    }
                }).detach();
            }
            break;
        default:
            break;
        }
    }
} g_myListener;

void setListener(baidurtc::BaiduRtcRoomClient *c,myListener &l)
{
    c->registerRtcMessageListener(&l);
}

typedef baidurtc::BaiduRtcRoomClient* f_createBaiduRtcRoomClient();
typedef const char* f_getVersion();

int main_push(int argc, char* argv[])
{

    void* handle = dlopen("libbaidurtc.so", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "Could not open sdk: %s\n", dlerror());
        return 1;
    }
    f_createBaiduRtcRoomClient* createClient = (f_createBaiduRtcRoomClient *)dlsym(handle, "_ZN8baidurtc24createBaiduRtcRoomClientEv");
    if (createClient == NULL) {
        fprintf(stderr, "Could not find sdk_func: %s\n", dlerror());
        return 1;
    }
    f_getVersion *version = (f_getVersion*)dlsym(handle, "getBaiduRtcSdkVersion");

    printf("BRTC.Linux.SDK Version is: %s\n",version());

    printf("Calling API\n");

    RtcParameterSettings s;

    g_BrtcClient = createClient();
    setListener(g_BrtcClient, g_myListener);

    s.HasData = false;
    s.HasVideo = true;
    s.HasAudio = true;
    s.AudioINChannel = 1;
    s.AudioINFrequency = 16000;
    s.ImageINType = RTC_IMAGE_TYPE_JPEG;
    s.AsPublisher = true;
    s.AsListener = false;
    s.AutoPublish = true;

    g_BrtcClient->setParamSettings(&s,s.RTC_PARAM_SETTINGS_ALL);
    g_BrtcClient->setAppID("appmabqxm7srvzh" );// argv[1]$(APPID_GET_FROM_BAIDU)
    g_BrtcClient->setMediaServerURL("wss://rtc.exp.bcelive.com/janus");
    g_BrtcClient->setCER("../bin/a.cer");

    std::string uid = std::to_string(1234500000+random()/100000);
    g_BrtcClient->loginRoom("8888",uid.c_str(),"BRTC Linux SDK push demo","token");

    while (!g_StopFlag) {

    }

    g_StopFlag = true;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    g_BrtcClient->logoutRoom();
    printf("logoutRoom OK.\n");
    g_BrtcClient->Destory();
    g_BrtcClient = nullptr;
    printf("Destory OK.\n");

    printf("API returned %d\n", 123);
    if (dlclose(handle) != 0) {
        fprintf(stderr, "Could not close plugin: %s\n", dlerror());
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    main_push(argc, argv);

    return a.exec();
}
