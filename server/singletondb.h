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
class SingletonDBDestroyer
{
    private:
        SingletonDB * p_instance;
    public:
        ~SingletonDBDestroyer();
        void initialize(SingletonDB * p);
};


class SingletonDB
{
    private:
        static SingletonDB * p_instance;
        static SingletonDBDestroyer destroyer;
        QSqlDatabase db;

    protected:
        SingletonDB(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("Users.db"); //
            if (!db.open())
                qDebug()<<"not connecting to the database"<<db.lastError().text();
            else {
                qDebug()<< "ok / db started";
            }
        }

        SingletonDB(const SingletonDB&);
        SingletonDB& operator = (SingletonDB &);

        ~SingletonDB(){db.close();}
        friend class SingletonDBDestroyer;

    public:
        static SingletonDB* getInstance(){
            if (!p_instance)
            {
                p_instance = new SingletonDB();
                destroyer.initialize(p_instance);
            }
            return p_instance;
        }
        void close_db();

        void unlogin(QString login){
            QSqlQuery query;
            query.prepare("UPDATE User SET socket=NULL WHERE login=:login");
            query.bindValue(":login",login);
            query.exec();
        }
};

#endif // SINGLETONDB_H
