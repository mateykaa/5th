/*!
\file
\brief Файл для сервера

Файл с действиями сервера
*/
#include <QDebug>
#include <QCoreApplication>
#include "mytcpserver.h"
#include "C:/others/code/project/1325/func.h"

/*!
\brief Деструктор

Деструктор закрывает соединение
*/
MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}

/*!
\brief Конструктор

Конструктор для запуска сервера
*/
MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33335)){
        qDebug() << "Server is not started";
    } else {
        server_status=1;
        qDebug() << "Server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = new QTcpSocket;
        mTcpSocket = mTcpServer ->nextPendingConnection();
        list.push_back(mTcpSocket);
        qDebug() << "New Connection";
        mTcpSocket->write("Client connected! \r\n");
        long long socket_id = mTcpSocket->socketDescriptor();
//        qDebug()<< list;
        clients.insert(mTcpSocket,socket_id);
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

/*!
\brief Чтение строки от пользователя
*/
void MyTcpServer::slotServerRead(){
    QTcpSocket *mTcpSocket = (QTcpSocket*)sender();
    QString socket_id = QString::number(mTcpSocket->socketDescriptor());
//    qDebug() << socket_id;
    QString str = "";
    while(mTcpSocket->bytesAvailable()>0){
        str +=mTcpSocket->readAll().trimmed();
    }
    if (str.trimmed().isEmpty()){
        return;
    }
    if (str.trimmed()[0] > 'z'){
        return;
    }
    mTcpSocket->write(parsing(str,socket_id).toUtf8());
}

/*!
\brief Возможность подключения нескольких клиентов
*/
void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();
//    qDebug() << list.size() << list;
}
