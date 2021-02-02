#include "tcpclient.h"
#include "message.pb.h"
#include <QTime>
#include <QCoreApplication>
#include <QThread>


using namespace  aonuo;

TcpClient::TcpClient(QObject *parent) : QObject(parent)
{
    tcp_cnt_suc=0;
    //初始化套接字对象
    m_Socket = new QTcpSocket();
    m_timer = new QTimer();

    //m_brtcwebjs = new BRTC_WEBJS();
    serialstm32 = new SerialSTM32();
    //m_brtc = new BRTC();


    Set_Sound_Avoid(8,2,"0");

    m_timer->setInterval(1000);

    m_cmd_sound =0;
    //关联数据信号
    connect(m_Socket,SIGNAL(readyRead()),this,SLOT(read_data()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(TimerOutUpdateSlot()));


    connect(this, SIGNAL(sgl_protbuf_decode(QString)),
            this, SLOT(protbuf_decode(QString)),Qt::QueuedConnection);

//    connect(this, SIGNAL( sgl_callbrtc(QString,QString)) ,
//            m_brtcwebjs, SLOT( BRTC_Webjs(QString,QString) ),Qt::QueuedConnection);


//    connect(this, SIGNAL( sgl_exitbrtc()) ,
//            m_brtc, SLOT( exit_brtc() ),Qt::QueuedConnection);

    connect(this, SIGNAL( sgl_send_data2_stm32(QByteArray)) ,
            serialstm32, SLOT( Send_Data2_STM32(QByteArray) ),Qt::QueuedConnection);

    connect(serialstm32,SIGNAL(sgl_Send_Read_STM32_Data(QByteArray)),
            this,SLOT(get_Read_STM32_Data(QByteArray)));


}

TcpClient::~TcpClient()
{
    delete m_Socket;
}
/* response解码器
* <pre>
* 数据包格式
* +——----——+——-----——+——----——+——----——+——-----——+——-----——+
* | 包头          | 模块号        | 命令号      | 消息类型  |  长度          |   数据       |
* +——----——+——-----——+——----——+——----——+——-----——+——-----——+
* </pre>
* 包头4字节
* 模块号2字节short
* 命令号2字节short
* 消息类型1字节byte
* 长度4字节(描述数据部分字节长度) 连续点击情况如何处理
*/
void TcpClient::read_data()
{
//    QByteArray msg = m_Socket->readAll();
    QByteArray msg = m_Socket->readAll(); //read(qint64 maxlen);
    //qDebug()<<msg;
    //QByteArray msg1 = msg.toUtf8();
    //QString pakg = msg.left(13);
   // quint16 len = msg.size();
   // QString pakgmsg = msg.right(len-13);

    //if(msg.at(0)==0x55 && msg.at(1)==0x55 && msg.at(2)==0xaa && msg.at(3)==0xaa && msg.at(4)==0x0&&msg.at(5)==0)// App message
        sgl_protbuf_decode(msg.right(msg.size()-13));


}

void TcpClient::setPort(QString url,quint16 port){
    m_url = url;
    m_port = port;
}

void TcpClient::on_connectServer_clicked()
{
    //检测链接成功信号关联槽函数
    connect(m_Socket,SIGNAL(connected()),this,SLOT(connect_suc()));
    //检测掉线信号
    connect(m_Socket,SIGNAL(disconnected()),this,SLOT(client_dis()));

    connect(m_Socket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(connect_false(QAbstractSocket::SocketError)));

    //连接服务器，设置ip和端口号
    m_Socket->connectToHost(m_url,m_port);

    //打开串口
    serialstm32->OpenSerial_STM32(1,"/dev/ttySWK0");
}

void TcpClient::on_send_clicked(QByteArray msg)
{
    //取发送信息编辑框内容
    //QString msg = ui->sendEdit->toPlainText();

    m_Socket->write(msg);//

}

#define	Action_null			0
#define Action_distance		1
#define Action_near			2
#define	Action_nothing	3
//lead data 0xFA
//DirectionAvoid[1] = checkdirection(0,0);//left-f
//DirectionAvoid[2] = checkdirection(0,1);//right-f

////Back
//DirectionAvoid[5] = checkdirection(1,0);//right-b
//DirectionAvoid[6] = checkdirection(1,1);//left-b

////Side
//DirectionAvoid[0] = checkdirection(2,0);//side-left-f
//DirectionAvoid[3] = checkdirection(2,1);//side-right-f
//DirectionAvoid[4] = checkdirection(2,2);//side-right-b
//DirectionAvoid[7] = checkdirection(2,3);//side-left-b
quint8 TcpClient::get_SoundSenr_Action(char in){
    if(in==Action_near || in==Action_null)
        return 1;
    else
        return 0;
}

void TcpClient::get_Read_STM32_Data(QByteArray byte){
    if(byte.at(0)==0xFA){
//        cmd_sound_code[0][1]=get_SoundSenr_Action( byte.at(1) );//side-le ft-f
//        cmd_sound_code[1][1]=get_SoundSenr_Action( byte.at(4) );//side-right-f
//        cmd_sound_code[2][1]=get_SoundSenr_Action( byte.at(8) );//side-left-b
//        cmd_sound_code[3][1]=get_SoundSenr_Action( byte.at(5) );//side-right-b
//        cmd_sound_code[4][1]=get_SoundSenr_Action( byte.at(2) );//left-f
//        cmd_sound_code[5][1]=get_SoundSenr_Action( byte.at(7) );//left-b
//        cmd_sound_code[6][1]=get_SoundSenr_Action( byte.at(3) );//right-f
//        cmd_sound_code[7][1]=get_SoundSenr_Action( byte.at(6) );//right-b
        if( get_SoundSenr_Action( byte.at(2) ) || get_SoundSenr_Action( byte.at(3) )  ){//robot-warn-forward
            cmd_sound_code[0][1]="1";
        }else
            cmd_sound_code[0][1]="0";

        if( get_SoundSenr_Action( byte.at(6) ) || get_SoundSenr_Action( byte.at(7) )  ){//robot-warn-back
            cmd_sound_code[1][1]="1";
        }else
            cmd_sound_code[1][1]="0";

        if( get_SoundSenr_Action( byte.at(1) ) || get_SoundSenr_Action( byte.at(8) )  ){//robot-warn-left
            cmd_sound_code[2][1]="1";
        }else
            cmd_sound_code[2][1]="0";


        if( get_SoundSenr_Action( byte.at(4) ) || get_SoundSenr_Action( byte.at(5) )  ){//robot-warn-right
            cmd_sound_code[3][1]="1";
        }else
            cmd_sound_code[3][1]="0";

        if( get_SoundSenr_Action( byte.at(1) ) || get_SoundSenr_Action( byte.at(2) )  ){//robot-warn-leftForward
            cmd_sound_code[4][1]="1";
        }else
            cmd_sound_code[4][1]="0";

        if( get_SoundSenr_Action( byte.at(8) ) || get_SoundSenr_Action( byte.at(7) )  ){//robot-warn-leftBack
            cmd_sound_code[5][1]="1";
        }else
            cmd_sound_code[5][1]="0";

        if( get_SoundSenr_Action( byte.at(4) ) || get_SoundSenr_Action( byte.at(3) )  ){//robot-warn-rightForward
            cmd_sound_code[6][1]="1";
        }else
            cmd_sound_code[6][1]="0";

        if( get_SoundSenr_Action( byte.at(5) ) || get_SoundSenr_Action( byte.at(6) )  ){//robot-warn-rightBack
            cmd_sound_code[7][1]="1";
        }else
            cmd_sound_code[7][1]="0";

        qDebug()<<"STM32 Receive data:"<<cmd_sound_code[0][1]<<" "<<cmd_sound_code[1][1]<<" "<<cmd_sound_code[2][1]<<" "<<cmd_sound_code[3][1]
                <<" "<<cmd_sound_code[4][1]<<" "<<cmd_sound_code[5][1]<<" "<<cmd_sound_code[6][1]<<" "<<cmd_sound_code[7][1];
    }else{

    }

}

void TcpClient::Set_Sound_Avoid(quint8 id,quint8 lop,QString data){
    if(lop>7||id>1){
        cmd_sound_code[0][0]="robot-warn-forward";
        cmd_sound_code[0][1]=data;

        cmd_sound_code[1][0]="robot-warn-back";
        cmd_sound_code[1][1]=data;

        cmd_sound_code[2][0]="robot-warn-left";
        cmd_sound_code[2][1]=data;

        cmd_sound_code[3][0]="robot-warn-right";
        cmd_sound_code[3][1]=data;

        cmd_sound_code[4][0]="robot-warn-leftForward";
        cmd_sound_code[4][1]=data;

        cmd_sound_code[5][0]="robot-warn-leftBack";
        cmd_sound_code[5][1]=data;

        cmd_sound_code[6][0]="robot-warn-rightForward";
        cmd_sound_code[6][1]=data;

        cmd_sound_code[7][0]="robot-warn-rightBack";
        cmd_sound_code[7][1]=data;

    }else{
        cmd_sound_code[id][lop]=data;
    }
}



void TcpClient::TimerOutUpdateSlot(){

    protobuf_encode_SoundSer(cmd_sound_code[m_cmd_sound][0] , cmd_sound_code[m_cmd_sound][1]);

    sendData(1,1,m_output);

    if(m_cmd_sound<7) m_cmd_sound++;
    else{
        m_cmd_sound=0;
    }
}

//检测链接成功
void TcpClient::connect_suc()
{
    tcp_cnt_suc =1;

    //QByteArray data = QByteArray::fromStdString("study hard and make progress every day 123456789");
    protobuf_encode_Init();
    sendData(1,1,m_output);

    QThread::sleep(1);
    protobuf_encode_Active();
    sendData(1,1,m_output);

   // emit sgl_callbrtc("appmabqxm7srvzh","8888");

    //protobuf_encode();
    qDebug()<<"TcpClient::connect_suc()";
    m_timer->start();
}
//检测掉线信号
void TcpClient::client_dis()
{
    tcp_cnt_suc = 0;
    m_Socket->connectToHost(m_url,m_port);
    m_timer->stop();
    //ui->btn_connectServer->setEnabled(true);//如果连接没有成功则连接按钮还可以按下
     qDebug()<<"TcpClient::client_dis()";
}
/*
    enum SocketError {
        ConnectionRefusedError,
        RemoteHostClosedError,
        HostNotFoundError,
        SocketAccessError,
        SocketResourceError,
        SocketTimeoutError,                     // 5 //
        DatagramTooLargeError,
        NetworkError,
        AddressInUseError,
        SocketAddressNotAvailableError,
        UnsupportedSocketOperationError,        // 10 //
        UnfinishedSocketOperationError,
        ProxyAuthenticationRequiredError,
        SslHandshakeFailedError,
        ProxyConnectionRefusedError,
        ProxyConnectionClosedError,             // 15 //
        ProxyConnectionTimeoutError,
        ProxyNotFoundError,
        ProxyProtocolError,
        OperationError,
        SslInternalError,                       // 20 //
        SslInvalidUserDataError,
        TemporaryError,

        UnknownSocketError = -1
    }
        */
void TcpClient::connect_false(QAbstractSocket::SocketError in){
    switch(in){
    case -1: qDebug()<< "UnknownSocketError";break;
    case 0: qDebug()<< "ConnectionRefusedError";break;
    case 1: qDebug()<< "RemoteHostClosedError";break;
    case 2: qDebug()<< "HostNotFoundError";break;
    case 3: qDebug()<< "SocketAccessError";break;
    case 4: qDebug()<< "SocketResourceError";break;
    case 5: qDebug()<< "SocketTimeoutError";break;
    case 6: qDebug()<< "DatagramTooLargeError";break;
    case 7: qDebug()<< "NetworkError";break;
    case 8: qDebug()<< "AddressInUseError";break;
    case 9: qDebug()<< "SocketAddressNotAvailableError";break;
    case 10: qDebug()<< "UnsupportedSocketOperationError";break;
    case 11: qDebug()<< "UnfinishedSocketOperationError";break;
    case 12: qDebug()<< "ProxyAuthenticationRequiredError";break;
    case 13: qDebug()<< "SslHandshakeFailedError";break;
    case 14: qDebug()<< "ProxyConnectionRefusedError";break;
    case 15: qDebug()<< "ProxyConnectionClosedError";break;
    case 16: qDebug()<< "ProxyConnectionTimeoutError";break;
    case 17: qDebug()<< "ProxyNotFoundError";break;
    case 18: qDebug()<< "ProxyProtocolError";break;
    case 19: qDebug()<< "OperationError";break;
    case 20: qDebug()<< "SslInternalError";break;
    case 21: qDebug()<< "SslInvalidUserDataError";break;
    case 22: qDebug()<< "TemporaryError";break;
    default:break;
    }
}

void TcpClient::sendData(quint16 model,quint16 cmd,std::string data){
    m_senddata.set_model(model);
    m_senddata.set_cmd(cmd);
    m_senddata.set_data(data);
    on_send_clicked( m_senddata.get_senddata() );

}

/*


message Message {

 string robotCode = 1;

    ActiveType activeType = 2;

 ResultType resultType = 3;

    DeviceType deviceType = 4;

 string module = 5;

 string cmd = 6;

 bytes body = 7;

}
*/
/*
 * <B>中文类名：</B>请求编码类<BR>
 * <B>概要说明：</B><BR>
 * 请求编码器
 * <pre>
 * 数据包格式
 * +——----——+——-----——+——----——+——----——+——-----——+
 * |  包头       |  模块号      |  命令号    |  长度       |   数据      |
 * +——----——+——-----——+——----——+——----——+——-----——+
 * 包头4字节
 * 模块号2字节short
 * 命令号2字节short
 * 长度4字节(描述数据部分字节长度)
 */
void TcpClient::protobuf_encode_SoundSer(QString modle,QString cmd){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Message msg;

    msg.set_robotcode( "Robot-1");//QString::fromStdString
    msg.set_activetype(ActiveType::ACTIVE);
    msg.set_resulttype(ResultType::SUCCESS);
    msg.set_devicetype(DeviceType::ROBOT);
    msg.set_module(modle.toStdString());
    msg.set_cmd(cmd.toStdString());


    if (!msg.SerializeToString(&m_output)) {
          std::cerr << "Failed to write person." << std::endl;
      }
    google::protobuf::ShutdownProtobufLibrary();

}
void TcpClient::protobuf_encode_Active(){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Message msg;

    msg.set_robotcode( "Robot-1");//QString::fromStdString
    msg.set_activetype(ActiveType::ACTIVE);
    msg.set_resulttype(ResultType::SUCCESS);
    msg.set_devicetype(DeviceType::ROBOT);
    msg.set_module("1");//video-call-close
    msg.set_cmd("1");// robot1robot id
    //msg.set_body(body);

    if (!msg.SerializeToString(&m_output)) {
          std::cerr << "Failed to write person." << std::endl;
      }
    google::protobuf::ShutdownProtobufLibrary();

}

void TcpClient::protobuf_encode_Init(){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Message msg;

    msg.set_robotcode( "Robot-1");//QString::fromStdString
    msg.set_activetype(ActiveType::INIT);
    msg.set_resulttype(ResultType::SUCCESS);
    msg.set_devicetype(DeviceType::ROBOT);
    msg.set_module("1");//video-call-init
    msg.set_cmd("1"); //robot id robot1

    if (!msg.SerializeToString(&m_output)) {
          std::cerr << "Failed to write person." << std::endl;
      }
    google::protobuf::ShutdownProtobufLibrary();

}


#define NeedStop	0   //0->stop
#define NeedForward	1   //1->forward
#define NeedBack	2   //2->back
#define NeedLeft	3   //3->left
#define NeedRight	4   //4->right
#define NeedAuto	5   //5->auto
#define NeedManual	6   //6->manual

QByteArray TcpClient::set_Send_STM32_Data(quint8 in){
    QByteArray byte;
    byte.resize(3);
    byte[0] = 0xF3;
    byte[1] = in;
    byte[2] = in;
    return byte;
}
void TcpClient::protbuf_decode(QString getmsg){
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Message msg;
    QString module,cmd;
    m_input = getmsg.toStdString();
   if (!msg.ParseFromString(m_input)) {
     qDebug()  << "Failed to parse person." << endl;
     return ;
   }
   // qDebug() << "robotCode:" << msg.robotcode() << endl;
    qDebug() << "activeType:" << msg.activetype() << endl;
    qDebug() << "resultType:" << msg.resulttype() << endl;
    qDebug() << "deviceType:" << msg.devicetype() << endl;
    qDebug() << "module:"<< QString::fromStdString( msg.robotcode() ) << endl;
    qDebug() << "cmd:"<< QString::fromStdString( msg.module() ) << endl;
    module = QString::fromStdString(msg.module());
    cmd = QString::fromStdString(msg.cmd());

    google::protobuf::ShutdownProtobufLibrary();

    if(module == "robot-go-forward"){//向前移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedForward) );
    }else if(module == "robot-go-back"){//向后移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedBack) );
    }else if(module == "robot-go-left"){//向左移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedLeft) );
    }else if(module == "robot-go-right"){//向右移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedRight) );
    }else if(module == "robot-go-auto"){//自动移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedAuto) );
    }else if(module == "robot-go-notAuto"){//手动移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedManual) );
    }else if(module == "robot-go-stop"){//停止移动
        emit sgl_send_data2_stm32( set_Send_STM32_Data(NeedStop) );
    }else if(module == "video-call-init"){//初始化通讯
        //emit sgl_callbrtc("appmabqxm7srvzh","8888");
    }else if(module == "video-call-close"){//结束通话
        //emit sgl_exitbrtc();
    }
}


