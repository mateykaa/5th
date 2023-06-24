#include <QCoreApplication>
#include "mytcpserver.h"

/*!
\brief Точка входа в программу.

\param argc Количество аргументов командной строки.
\param argv Массив аргументов командной строки.
\return Код возврата.

Данная функция является точкой входа в программу.
Она создает объект MyTcpServer и запускает основной цикл
обработки событий приложения.
*/
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyTcpServer server;
    return a.exec();
}
