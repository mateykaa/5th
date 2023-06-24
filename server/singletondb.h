#ifndef SINGLETONDB_H
#define SINGLETONDB_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
#include <QString>
#include <vector>

class SingletonDB;
/*!
\brief Класс-уничтожитель SingletonDB.

Данный класс является вспомогательным и используется для
корректного удаления экземпляра класса SingletonDB.
*/
class SingletonDBDestroyer
{
    private:
        SingletonDB * p_instance; /*!< Указатель на экземпляр класса SingletonDB. */

    public:

        /*!
        \brief Деструктор класса SingletonDBDestroyer.
        */

        ~SingletonDBDestroyer();
        /*!
        \brief Инициализация класса SingletonDBDestroyer.

        \param p Указатель на экземпляр класса SingletonDB.
        */
        void initialize(SingletonDB * p);
};

/*!
\brief Класс SingletonDB для работы с базой данных.

Данный класс представляет собой Singleton-класс, который
используется для работы с базой данных.
*/
class SingletonDB
{
    private:
        static SingletonDB * p_instance; /*!< Указатель на экземпляр класса SingletonDB. */
        static SingletonDBDestroyer destroyer; /*!< Объект класса SingletonDBDestroyer. */
        QSqlDatabase db; /*!< Объект базы данных. */

    protected:
        /*!
        \brief Конструктор класса SingletonDB.

        Данный конструктор создает и инициализирует объект базы данных.
        */
        SingletonDB(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("C:/others/code/project/1325/Users.db"); //"C:\others\code\project\1325\Users.db"
            if (!db.open())
                qDebug()<<"not connecting to the database"<<db.lastError().text();
            else {
                qDebug()<< "ok / db started";
            }
        }

        /*!
        \brief Деструктор класса SingletonDB.

        Данный деструктор закрывает соединение с базой данных.
        */
        SingletonDB(const SingletonDB&);
        SingletonDB& operator = (SingletonDB &);
        ~SingletonDB(){db.close();}
        friend class SingletonDBDestroyer;

    public:
        /*!
        \brief Получение экземпляра класса SingletonDB.

        \return Указатель на экземпляр класса SingletonDB.
        */
        static SingletonDB* getInstance(){
            if (!p_instance)
            {
                p_instance = new SingletonDB();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        /*!
        \brief Закрытие соединения с базой данных.
        */
        void close_db();

        /*!
        \brief Функция отмены авторизации пользователя.

        \param login Логин пользователя.

        Данная функция удаляет информацию о сокете пользователя,
        отменяя его авторизацию.
        */
        void unlogin(QString login){
            QSqlQuery query;
            query.prepare("UPDATE User SET socket=NULL WHERE login=:login");
            query.bindValue(":login",login);
            query.exec();
        }
};

#endif // SINGLETONDB_H
