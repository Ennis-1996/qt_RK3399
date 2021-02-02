#ifndef BRTC_WEBJS_H
#define BRTC_WEBJS_H

#include <QObject>

class BRTC_WEBJS : public QObject
{
    Q_OBJECT
public:
    explicit BRTC_WEBJS(QObject *parent = nullptr);

signals:

public slots:
    void BRTC_Webjs(QString,QString);
};

#endif // BRTC_WEBJS_H
