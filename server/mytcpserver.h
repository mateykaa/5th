/*!
\file
\brief Файл содержит объявление класса MyTcpServer.

Данный файл представляет собой серверное приложение,
которое обрабатывает подключения клиентов и обменивается данными
по протоколу TCP/IP.
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
#include "func.h"

/*!
\brief Класс сервера TCP.

Данный класс представляет собой серверное приложение,
которое обрабатывает подключения клиентов и обменивается данными
по протоколу TCP/IP.
*/
class MyTcpServer : public QObject
{
    Q_OBJECT

public:
    /*!
    \brief Конструктор класса MyTcpServer.
    \param parent Родительский объект (по умолчанию nullptr).
    */
    explicit MyTcpServer(QObject *parent = nullptr);

    /*!
    \brief Деструктор класса MyTcpServer.
    */
    ~MyTcpServer();

public slots:
    /*!
    \brief Функция для обработки нового подключения.

    Данная функция создает слот для нового подключения клиента.
    */
    void slotNewConnection();

    /*!
    \brief Функция для обработки отключения клиента.

    Данная функция вызывается при отключении клиента
    и выполняет соответствующие действия.
    */
    void slotClientDisconnected();

    /*!
    \brief Функция для чтения строки от клиента.

    Данная функция считывает строку от клиента и
    выполняет необходимые действия с полученными данными.
    */
    void slotServerRead();
    //void slotReadClient();

private:
    QTcpServer * mTcpServer; /*!< Указатель на объект сервера. */
    QTcpSocket * mTcpSocket; /*!< Указатель на объект сокета. */
    int server_status; /*!< Состояние сервера. */
    QList<QTcpSocket*> list; /*!< Список подключенных клиентов. */
    QMap<QTcpSocket*, long long> clients; /*!< Мапа клиентов и их идентификаторов. */
};
#endif // MYTCPSERVER_H







