#include "stelnet.h"

STelnet::STelnet(QString ipAddress, quint16 port, QObject *parent) :
    QObject(parent) {
    QHostAddress address(ipAddress);

    qDebug() << "connecting to " << ipAddress << "...";

    socket = new QTcpSocket(this);

    socket->connectToHost(address, port);
    if ( socket->waitForConnected(3000) ) {
        qDebug() << "connected to " << ipAddress << "!!!";
        socket->write("Client: established conection! \r\n");
        qDebug() << "Reading" << socket->bytesAvailable();
        connect(socket, SIGNAL(readyRead()), this, SLOT(recieveData()));
    } else {
        qDebug() << "augoops!!!";
        socket->close();
    }
}

STelnet::~STelnet() {
    socket->close();
}

void STelnet::sendData(QString data) {
    QByteArray msg;
    if ( !data.isEmpty() ) {
        data += "\n";
        msg.append(data);
        socket->write(msg);
        socket->waitForBytesWritten(1000);
    }
}

void STelnet::recieveData() {
    QString message(socket->readAll());

    qDebug() << message;
}


