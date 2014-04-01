#ifndef STELNET_H
#define STELNET_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>
#include <iostream>

class STelnet : public QObject
{
    Q_OBJECT
public:
    explicit STelnet(QString ipAddress, quint16 port, QObject *parent = 0);
    ~STelnet();
    void sendData(QString data);

public slots:
    void recieveData();

private:
    QTcpSocket *socket;
    
};

#endif // STELNET_H
