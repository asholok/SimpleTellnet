#include "comutator.h"

Comutator::Comutator(STelnet* telnet, QObject *parent) :
    QObject(parent){
    source = telnet;
    notifier = new QSocketNotifier(STDIN_FILENO, QSocketNotifier::Read);
    connect(notifier, SIGNAL(activated(int)), this, SLOT(message()));
}

Comutator::~Comutator(){
    delete notifier;
}

void Comutator::message(){
    QString message;

    QTextStream qin(stdin);
    qin >> message;

    if ( message == "quit" ) {
        QCoreApplication::instance()->quit();
    }

    source->sendData(message);

}
