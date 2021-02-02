#ifndef SERIALSTM32_H
#define SERIALSTM32_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>

class SerialSTM32 : public QObject
{
    Q_OBJECT
public:
    explicit SerialSTM32(QObject *parent = nullptr);
    QSerialPort *m_serial;
    quint8 m_Is_connectRos;
    QTimer *m_timerRos;

    void OpenSerial_STM32(quint8 act,QString serName);


signals:
    void sgl_Send_Read_STM32_Data(QByteArray);
    void sgl_Send_Beet(QByteArray byte);

public slots:
    void Send_Data2_STM32(QByteArray byte);
    void Read_STM32_Data();
    void TimerConnectRos();

};

#endif // SERIALSTM32_H
