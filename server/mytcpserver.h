/*!
\file
\brief Сервер
*/
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QVector>
#include <QMap>

class MyTcpServer : public QObject
{
    Q_OBJECT

public:
    explicit MyTcpServer(QObject *parent = nullptr);
    ~MyTcpServer();

public slots:
    /*!
    \brief Функция создания слота нового подключения
    */
    void slotNewConnection();

    /*!
       \brief Функция откючения клиента
    */
    void slotClientDisconnected();

    /*!
        \brief Функция чтеня строки от пользователя
    */
    void slotServerRead();
    //void slotReadClient();

private:
    QTcpServer * mTcpServer;
    QTcpSocket * mTcpSocket;
    int server_status;

    /*!
        \brief Список подключений
    */
    QList <QTcpSocket*> list;
    QMap <QTcpSocket*, long long> clients;

};
#endif // MYTCPSERVER_H







