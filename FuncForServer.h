#ifndef FUNCFORSERVER_H
#define FUNCFORSERVER_H
#include <QObject>
#include <QByteArray>
#include <QString>
#include <QCoreApplication>

// nameOfFunc+username+password+email
//     0         1         2      3

//QByteArray auth(QString username, QString password){
QByteArray authorization(QString username,QString password){
    return QByteArray("auth");
    qDebug()<<"User= "<<username<<" pass="<<password;
}

//QByteArray reg(QString username, QString password, QString email){
QByteArray reg(QString username,QString password, QString email){
    return QByteArray("reg");
    qDebug()<<"User="<<username<<" pass="<<password<<" email="<<email;
}

QByteArray checktask(){
    return QByteArray("checktask");
}

QByteArray parsing(QString source_str)
{
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

    else if (data[0] == "check")
    {
        return checktask();
//        return QByteArray("checktask");
}
}

#endif // FUNCFORSERVER_H
