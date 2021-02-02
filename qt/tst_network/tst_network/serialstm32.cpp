#include "serialstm32.h"
#include <QDebug>

SerialSTM32::SerialSTM32(QObject *parent) : QObject(parent)
{
    //查找可用的串口
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            //ui->PortBox->addItem(serial.portName());
            qDebug()<<serial.portName();
            serial.close();
        }
    }
    m_Is_connectRos = 0;
    m_timerRos = new QTimer();
    m_timerRos->setInterval(200);

    connect(m_timerRos, SIGNAL(timeout()), this, SLOT(TimerConnectRos()));
    connect(this, SIGNAL(sgl_Send_Beet(QByteArray)), this, SLOT(Send_Data2_STM32(QByteArray)));

    //设置波特率下拉菜单默认显示第0项
    //ui->BaudBox->setCurrentIndex(0);
    m_serial = new QSerialPort();
    m_timerRos->start();
}


void SerialSTM32::OpenSerial_STM32(quint8 act,QString serName)
{
    if(act==1)
    {
        //设置串口名
        m_serial->setPortName(serName);
        //打开串口
        m_serial->open(QIODevice::ReadWrite);
        //设置波特率
        m_serial->setBaudRate(QSerialPort::Baud115200);//设置波特率为115200
        //设置数据位数
        m_serial->setDataBits(QSerialPort::Data8);//设置数据位8
        //设置校验位
        m_serial->setParity(QSerialPort::NoParity);
        //设置停止位
//        switch (ui->BitBox->currentIndex())
//        {
//        case 1:
            m_serial->setStopBits(QSerialPort::OneStop);//停止位设置为1
//            break;
//        case 2:
//            m_serial->setStopBits(QSerialPort::TwoStop);
//        default:
//            break;
//        }

        //设置流控制
        m_serial->setFlowControl(QSerialPort::NoFlowControl);//设置为无流控制

        //连接信号槽
        QObject::connect(m_serial,SIGNAL( readyRead()) ,this,SLOT( Read_STM32_Data() )); //&QSerialPort::readyRead  &MainWindow::ReadData
    }
    else
    {
        //关闭串口
        m_serial->clear();
        m_serial->close();
        m_serial->deleteLater();

    }

}
//读取接收到的信息
void SerialSTM32::Read_STM32_Data()
{
    QByteArray buf;
    buf = m_serial->readAll();
    if(!buf.isEmpty())
    {
//        QString str = ui->textEdit->toPlainText();
//        str+=tr(buf);
//        ui->textEdit->clear();
//        ui->textEdit->append(str);
    }
    //buf.clear();  //-------------------------------------?????????????????????????
    //Send_Read_STM32_Data
    sgl_Send_Read_STM32_Data(buf);
}

//发送按钮槽函数 lead by 0XF3 All datalen 3
void SerialSTM32::Send_Data2_STM32(QByteArray byte)
{
    m_serial->write( byte );
    m_Is_connectRos=0;
}

void SerialSTM32::TimerConnectRos(){
    if(m_Is_connectRos==1){
        QByteArray byte;
        byte.resize(3);
        byte[0] = 0xF3;
        byte[1] = byte[2] = 10;
        emit sgl_Send_Beet(byte);
    }
    if(m_Is_connectRos==0)
        m_Is_connectRos = 1;
}
