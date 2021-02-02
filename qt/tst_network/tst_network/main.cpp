#include <QCoreApplication>
#include "tcpclient.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TcpClient tcpclt;
    tcpclt.setPort("192.168.3.230", 8765);
    tcpclt.on_connectServer_clicked();
    //tcpclt.protobuf_encode();


    return a.exec();
}
