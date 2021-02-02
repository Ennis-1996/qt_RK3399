QT += core network
QT -= gui

CONFIG += c++11

TARGET = tst_rtc
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    image_base64.cpp


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#DEFINES += RK3399

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    mat2img.h \
    image_base64.h

INCLUDEPATH += /usr/local/include

LIBS += -ldl -lpthread


if(contains(DEFINES,RK3399)) {

LIBS += -L/usr/local/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu/lib/gcc/aarch64-linux-gnu

INCLUDEPATH += /home/robot123/Downloads/opencv-4.0.0/build/install/include/opencv4/
INCLUDEPATH +=  /home/robot123/Downloads/BRTC_Linux/include/
LIBS += /home/robot123/Downloads/opencv-4.0.0/build/install/lib/libopencv*

}else{

LIBS += -L/lib/x86_64-linux-gnu
INCLUDEPATH +=  /usr/local/include/opencv4/
INCLUDEPATH +=  /home/robot123/Downloads/BRTC/include/
LIBS += /usr/local/lib/libopencv*

}
