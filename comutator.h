#ifndef COMUTATOR_H
#define COMUTATOR_H

#include <QObject>
#include "stelnet.h"
#include <unistd.h>
#include <QTextStream>
#include <QSocketNotifier>
#include <QCoreApplication>
#include <QDebug>

class Comutator : public QObject
{
    Q_OBJECT
public:
    Comutator(STelnet *telnet, QObject *parent = 0);
    ~Comutator();
    
public slots:
    void message();
private:
    STelnet* source;
    QSocketNotifier* notifier;

};

#endif // COMUTATOR_H
