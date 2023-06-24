#include "singletonclient.h"
#include "authform.h"
#include <QSslConfiguration>
#include <QSslCertificate>

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
        QByteArray array = mTcpSocket->readAll();
        QString statistic1 = array.left(array.indexOf(" "));
        QString statistic2 = array.left(array.indexOf("&"));
        if (statistic1=="stat") {
        emit get_stat(array);
        }
        if (statistic2=="statall") {
        emit get_statall(array);
        }

    qDebug()<< "get: " << array;    
    if (array=="Welcome! Teacher") {
        emit log_in();
        emit teacher();
    }
    if (array=="Welcome! Student") {
        emit log_in();
        emit student();
    }
    if (array=="Welcome! Admin") {
        emit log_in();

    }
    if (array=="Wrong username or password! ") {
        emit wrong_pass_name();
    }
    if (array=="This username is already used!") {
        emit user_exists();
    }
    if (array=="You have been successfully registered!") {
        emit registered();
    }
    if (array=="You are not registered! " or array=="error parsing/n") {
        emit wrong_pass_name();
    }


}

SingletonClient::~SingletonClient() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    mTcpSocket->close();
}

SingletonClient * SingletonClient::instance;
SingletonDestroyer SingletonClient::destroyer;

