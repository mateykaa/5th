#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QObject>
#include <QByteArray>
#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <singletondb.h>

QByteArray authorization(QString login,QString password){
    qDebug()<<"login="<<login<<"pass="<<password;


    return QByteArray("auth");
}

QByteArray reg(QString login,QString password, QString email){
    qDebug()<<"login="<<login<<"pass="<<password<<"email="<<email;

    SingletonDB::getInstance()->add_user(login,password,email);


    return QByteArray("reg");
}

QByteArray parsing(QString source_str){
    QStringList data;
    data = source_str.split(' ');

    if (data[0] == "auth")
    {
        return authorization(data[1],data[2]);
}

    else if (data[0] == "reg")
    {
        return reg(data[1],data[2],data[3]);
}

    else return "error parsing/n";
}

#endif // FUNCFORSERVER_H
