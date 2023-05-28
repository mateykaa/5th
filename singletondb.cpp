#include "singletondb.h"

SingletonDBDestroyer::~SingletonDBDestroyer()
{
    delete p_instance;
}

void SingletonDBDestroyer::initialize(SingletonDB * p)
{
    p_instance = p;
}

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
