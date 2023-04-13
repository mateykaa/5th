#include "singletondb.h"


SingletonDBDestroyer::~SingletonDBDestroyer()
{
    delete p_instance;
}

void SingletonDBDestroyer::initialize(SingletonDB * p)
{
    p_instance = p;
}

QString SingletonDB::send_query(QString query)
{
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(query))
    {
        qDebug() << "Failed to execute query: " << sqlQuery.lastError().text();
        return "";
    }

    QString login = "";
    QString password = "";
    QString id = "";
    QString name = "";
    QString email = "";
    while (sqlQuery.next())
    {
//        result = sqlQuery.value(0).toString();
        id = sqlQuery.value("id").toString();
        login = sqlQuery.value("login").toString();
        password = sqlQuery.value("password").toString();
        name = sqlQuery.value("name").toString();
        email = sqlQuery.value("email").toString();
    }
    qDebug()<< id << login << password << name << email;
    return "";
}

void SingletonDB::add_user(QString login, QString password, QString email){
    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("INSERT INTO User(login, password, email) VALUES (:login, :password, :email)");
    sqlQuery.bindValue(":login", login);
    sqlQuery.bindValue(":password", password);
    sqlQuery.bindValue(":email", email);
    sqlQuery.exec();

}

void SingletonDB::login_user(QString login, QString password){
    QSqlQuery query(db);
    query.prepare("SELECT * FROM User WHERE login = :login AND pass = :pass;");
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    query.exec();
}

SingletonDB * SingletonDB::p_instance;
SingletonDBDestroyer SingletonDB::destroyer;
