#ifndef BRTC_H
#define BRTC_H

#include <QObject>

class BRTC : public QObject
{
    Q_OBJECT
public:
    explicit BRTC(QObject *parent = nullptr);
    ~BRTC();
    void* handle= NULL;



signals:

public slots:
    void call_brtc(QString id, QString room);
    void exit_brtc();
};

#endif // BRTC_H
