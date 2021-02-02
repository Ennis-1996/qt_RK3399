QT += core network serialport
QT -= gui

CONFIG += c++11

TARGET = tst_network
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    dataformat.cpp \
    main.cpp \
    message.pb.cc \
    serialstm32.cpp \
    tcpclient.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += RK3399

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    dataformat.h \
    message.pb.h \
    serialstm32.h \
    tcpclient.h


LIBS += -ldl -lpthread

if(contains(DEFINES,RK3399)) {

LIBS +=/home/robot123/Downloads/protobuf-cpp-3.7.0/protobuf-3.7.0/build/protobuf-c-arm/lib/libprotobuf.a -lpthread
INCLUDEPATH += /home/robot123/Downloads/protobuf-cpp-3.7.0/protobuf-3.7.0/build/protobuf-c-arm/include/

LIBS += -L/usr/local/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/lib/gcc/aarch64-linux-gnu

INCLUDEPATH += /home/robot123/Downloads/opencv-4.0.0/build/install/include/opencv4/

#INCLUDEPATH +=  /home/robot123/Downloads/BRTC_Linux/include/

#LIBS += /home/robot123/Downloads/opencv-4.0.0/build/install/lib/libopencv*

}else{

INCLUDEPATH +=  /home/robot123/Downloads/BRTC/include/

LIBS +=/usr/local/lib/libprotobuf.a

INCLUDEPATH += /usr/local/include/google/protobuf/

LIBS += -L/lib/x86_64-linux-gnu
#INCLUDEPATH +=  /usr/local/include/opencv4/

#LIBS += /usr/local/lib/libopencv*

}


#DISTFILES += \
#    BRTC_Web_SDK.1/baidu.rtc.sdk.js \
#    BRTC_Web_SDK.1/brtc.html
