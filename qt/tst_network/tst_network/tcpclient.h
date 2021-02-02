#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <fstream>


//enum MessageType {
// REQUEST = 0,
// RESPONSE = 1
//};

//enum ResultType {
// SUCCESS = 0,
// FAILURE = 1,
// SYS_ERROR = 2
//};

//enum DeviceType {
//    APP = 0,
//    ROBOT = 1
//};

//enum ActiveType {
//    INIT = 0,
//    ACTIVE = 1,
//    CLOSE = 2
//};

#include "dataformat.h"
#include <QTimer>
//#include "brtc.h"
#include "serialstm32.h"
//#include <brtc_webjs.h>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr);
    ~TcpClient();
    QTcpSocket *m_Socket ;
    //BRTC_WEBJS *m_brtcwebjs;
    //BRTC *m_brtc;
    QString m_url;
    QString cmd_sound_code[8][2];
    quint8 cmd_control_code;
    quint16 m_port;
    QTimer *m_timer;

    SerialSTM32 *serialstm32;

    quint8 m_cmd_sound;


    std::string m_output ;
    std::string m_input ;
    quint8 tcp_cnt_suc;

    DataFormat m_senddata;
    DataFormat m_rcvdata;

    QByteArray set_Send_STM32_Data(quint8 in);

    void on_connectServer_clicked();
    void on_send_clicked(QByteArray msg);
    void setPort(QString url,quint16 port);

    void protobuf_encode_Init();
    void protobuf_encode_Active();
    void protobuf_encode_SoundSer(QString modle,QString cmd);


    void sendData(quint16 model,quint16 cmd,std::string data);

    quint8 get_SoundSenr_Action(char in);

   // bool sleep(unsigned int msec);

signals:
    void sgl_protbuf_decode(QString);
    void sgl_callbrtc(QString,QString);
    void sgl_exitbrtc();
    void sgl_send_data2_stm32(QByteArray);

public slots:
    void read_data();
    void connect_suc();
    void client_dis();
    void TimerOutUpdateSlot();

    void connect_false(QAbstractSocket::SocketError);
    void Set_Sound_Avoid(quint8 id,quint8 lop,QString data);

    void protbuf_decode(QString);

    void get_Read_STM32_Data(QByteArray);

};

#endif // TCPCLIENT_H
