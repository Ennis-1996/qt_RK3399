#ifndef DATAFORMAT_H
#define DATAFORMAT_H

#include <QObject>
/*
 * <B>中文类名：</B>请求编码类<BR>
 * <B>概要说明：</B><BR>
 * 请求编码器
 * <pre>
 * 数据包格式
 * +——----——+——-----——+——----——+——----——+——-----——+
 * |  包头       |  模块号      |  命令号    |  长度       |   数据      |
 * +——----——+——-----——+——----——+——----——+——-----——+
 * 包头4字节 0x5555AAAA
 * 模块号2字节short
 * 命令号2字节short
 * 长度4字节(描述数据部分字节长度)
 */
/*
#include <QMetaType>

struct DataFormat{
    quint8 m_head[4] ;
    quint8 m_model[2] ;
    quint8 m_cmd[2] ;
    quint8 m_len[4];
    std::string m_data;
};
Q_DECLARE_METATYPE(DataFormat);             //要调用Q_DECLARE_METATYPE，向QT声明这个结构体
*/
class DataFormat : public QObject
{
    Q_OBJECT
public:
    explicit DataFormat(QObject *parent = nullptr);
    //quint32 m_head = 0x5555AAAA;
    quint16 m_model ;
    quint16 m_cmd ;
    std::string m_data;

    void set_model(quint16 in){
        m_model = in;
    }
    void set_cmd(quint16 in){
        m_cmd = in;
    }
    void set_data(std::string data){
        m_data = data;
    }
    QByteArray get_senddata(){
        quint32 len = m_data.size();

        quint8 tmpdata[12];
        tmpdata[0]= tmpdata[1] = 0x55;
        tmpdata[2]= tmpdata[3] = 0xAA;

        tmpdata[4] = m_model>>8;
        tmpdata[5] = m_model;
        tmpdata[6] = m_cmd>>8;
        tmpdata[7] = m_cmd;

        tmpdata[8] = len>>24;
        tmpdata[9] = (len>>16)&0xFF;
        tmpdata[10] = (len>>8)&0xFF;
        tmpdata[11] = len&0xFF;

        QByteArray data = QByteArray::fromRawData((char*)tmpdata,12);
        data += QByteArray::fromStdString( m_data );

        return data;
    }
signals:

public slots:
};

#endif // DATAFORMAT_H
