/*!
\file
\brief Основной файл программы

Основной файл программы из которого
она запускается
*/
#include <QCoreApplication>
#include "mytcpserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
    return a.exec();
}
