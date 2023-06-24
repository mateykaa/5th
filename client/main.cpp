#include "mainwindow.h"
//#include "singletonclient.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //SingletonClient::getInstance();
    MainWindow w;

    return a.exec();
}

//    SingletonClient::getInstance()->
//send_msg_to_server(QString::fromStdString("reg a b c"));
//return a.exec();
