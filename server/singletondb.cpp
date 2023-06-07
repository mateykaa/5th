#include "singletondb.h"

/*!
\brief Деструктор
*/
SingletonDBDestroyer::~SingletonDBDestroyer()
{
    delete p_instance;
}

/*!
\brief копирует ссылку на объект
\param p
Копирует ссылку на объект класса singleton_db
для последующей работы с ней в классе singleton_db_destroyer
*/
void SingletonDBDestroyer::initialize(SingletonDB * p)
{
    p_instance = p;
}

/*!
\brief Закрытие БД
*/
void SingletonDB::close_db(){
    if (db.open()){
        db.close();
        qDebug() << "closed";
    }
    else{
        qDebug() << "already closed";
    }
}
SingletonDB * SingletonDB::p_instance;
SingletonDBDestroyer SingletonDB::destroyer;
