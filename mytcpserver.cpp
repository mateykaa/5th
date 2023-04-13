#include <QDebug>
#include <QCoreApplication>
#include "mytcpserver.h"
#include <FuncForServer.h>

MyTcpServer::~MyTcpServer()
{
    //mTcpSocket->close();
    mTcpServer->close();
    server_status=0;
}

MyTcpServer::MyTcpServer(QObject *parent) : QObject(parent){
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection,
            this, &MyTcpServer::slotNewConnection);

    if(!mTcpServer->listen(QHostAddress::Any, 33335)){
        qDebug() << "server is not started";
    } else {
        server_status=1;
        qDebug() << "server is started";
    }
}

void MyTcpServer::slotNewConnection(){
    if(server_status==1){
        mTcpSocket = new QTcpSocket;
        mTcpSocket = mTcpServer ->nextPendingConnection();
        list.push_back(mTcpSocket);
        qDebug() << "NewConnection";
        mTcpSocket->write("Client connected!!!\r\n");
        connect(mTcpSocket, &QTcpSocket::readyRead,
                this,&MyTcpServer::slotServerRead);
        connect(mTcpSocket,&QTcpSocket::disconnected,
                this,&MyTcpServer::slotClientDisconnected);
    }
}

void MyTcpServer::slotServerRead(){
    QTcpSocket *mTcpSocket = (QTcpSocket*)sender();
    QString str;
    while(mTcpSocket->bytesAvailable()>0){
        str +=mTcpSocket->readAll();
    }
    if (str.trimmed().isEmpty()){
        return;
    }
    if (str.trimmed()[0] > 'z'){
        return;
    }

    mTcpSocket->write(parsing(str.toUtf8()));
}

void MyTcpServer::slotClientDisconnected(){
    QTcpSocket* mTcpSocket = (QTcpSocket*)sender();
    list.removeAt(list.indexOf(mTcpSocket));
    mTcpSocket->close();
    qDebug() << list.size();
}
