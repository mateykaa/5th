#ifndef SINGLETONCLIENT_H
#define SINGLETONCLIENT_H

#include <QObject>
#include <QtNetwork>
//#include <QTcpSocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QSslSocket>

class SingletonClient;

class SingletonDestroyer {
    private:
        SingletonClient* instance;
    public:
        ~SingletonDestroyer() { delete instance;}
        void initialize(SingletonClient* p){ instance = p;}
};


class SingletonClient : public QObject
{
    Q_OBJECT
    private:
        static SingletonClient * instance;
        static SingletonDestroyer destroyer;
        QTcpSocket * mTcpSocket;
    protected:
        explicit SingletonClient(QObject *parent = nullptr);
        SingletonClient(const SingletonClient &) = delete;
        SingletonClient& operator = (SingletonClient &) = delete;
        ~SingletonClient();
        friend class SingletonDestroyer;
    public:
        static SingletonClient* getInstance();
        void send_msg_to_server(QString message);
    public slots:
        void slotServerRead();
    signals:
        void log_in();
        void registered();
        void wrong_pass_name();
        void user_exists();
        void teacher();
        void student();
        void get_stat(QString stat);
        void get_statall(QString stat);
};

#endif // SINGLETONCLIENT_H
