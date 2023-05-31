#include "singletonclient.h"

SingletonClient::SingletonClient(QObject *parent) : QObject(parent) {
    mTcpSocket = new QTcpSocket(this);
    mTcpSocket->connectToHost("127.0.0.1", 33335);

    connect(mTcpSocket, SIGNAL(readyRead()),
            this, SLOT(slotServerRead()));
    if (mTcpSocket->isOpen()) {qDebug() << "Connected";}

}

SingletonClient* SingletonClient::getInstance() {
    if (!instance) {
        instance = new SingletonClient();
        destroyer.initialize(instance);
    }
    return instance;
}

void SingletonClient::send_msg_to_server(QString message) {
    mTcpSocket->write(message.toUtf8());
    qDebug() << "Send: " << message;
}

void SingletonClient::slotServerRead() {
    QString message;
    //while(mTcpSocket->bytesAvailable()>0) {
        QByteArray array = mTcpSocket->readAll();
       // message.append(array);
    //}
    //qDebug()<<message;
    qDebug()<< "get: " << array;
    if (array=="Welcome! student or teacher") {
        emit log_in();
    }
    if (array=="Wrong username or password! ") {
        emit wrong_pass_name();
    }
    if (array=="This username is already used!") {
        emit user_exists();
    }
    if (array=="You have been successfully registered! ") {
        emit registered();
    }
    if (array=="You are not registered! " or array=="Error auth") {
        emit wrong_pass_name();
    }
    //return array;
}

SingletonClient::~SingletonClient() {
    mTcpSocket->close();
}

SingletonClient * SingletonClient::instance;
SingletonDestroyer SingletonClient::destroyer;

