#ifndef FUNC_H
#define FUNC_H
#include <QObject>
#include <QByteArray>
#include <QString>
#include <QCoreApplication>
#include <QDebug>
#include <singletondb.h>
#include <tasks.h>

QString authorization(QString login,QString password){
    qDebug()<<"login="<<login<<"pass="<<password.trimmed();
    SingletonDB *db = SingletonDB::getInstance();

    QString log_from_db, pass_from_db;
    qDebug() << "authentication...";
    QSqlQuery query;

    query.prepare("SELECT * FROM User WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");

    while(query.next())
        log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString();
    QString status = "Wrong username or password! ";

    if (login == log_from_db && password.trimmed() == pass_from_db){
         status = "Welcome! student or teacher";
    }
    return status;
}

QString reg(QString login,QString password, QString email){
    qDebug()<<"login="<<login<<"pass="<<password<<"email="<<email;
    SingletonDB *db = SingletonDB::getInstance();

    QSqlQuery query;
    QString stat = "You are not registered! ";

    QString log_from_db, pass_from_db, email_from_db;
    query.prepare("SELECT * FROM User "
               "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
        log_from_db = query.value(rec.indexOf("login")).toString();

     if (login == log_from_db){
         stat = "This username is already used!";
     }
     else{
         query.prepare("INSERT INTO User(login, password, email) "
                           "VALUES (:login, :password, :email)");
         query.bindValue(":password",password);
         query.bindValue(":login",login);
         query.bindValue(":email",email);
         query.exec();

         query.prepare("SELECT * FROM User "
                    "WHERE login == :login");
         query.bindValue(":login",login);
         query.exec();

         QSqlRecord rec = query.record();
         const int loginIndex = rec.indexOf("login");
         const int passwordIndex = rec.indexOf("password");
         const int emailIndex = rec.indexOf("email");

         while(query.next()){
             log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(), email_from_db = query.value(emailIndex).toString();
             qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\t" << email_from_db << "\n";
        }
         if (login == log_from_db && password == pass_from_db && email == email_from_db)
         {
              stat = "You have been successfully registered! ";
         }
     }

    return stat;
}

QString get_stat(QString login){
    SingletonDB *db = SingletonDB::getInstance();
    QSqlQuery query;

    QString name_from_db, task1_from_db, task2_from_db, task3_from_db, task4_from_db, task5_from_db;
    query.prepare("SELECT * FROM user WHERE login == :login");
    query.bindValue(":login",login.trimmed());
    query.exec();

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf("login");
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");
    const int task5Index = rec.indexOf("task5");

    while(query.next()){
        name_from_db = query.value(nameIndex).toString(), task1_from_db = query.value(task1Index).toString(),
                task2_from_db = query.value(task2Index).toString(), task3_from_db = query.value(task3Index).toString(),
                    task4_from_db = query.value(task4Index).toString(), task5_from_db = query.value(task5Index).toString();
        qDebug()<<name_from_db <<"\t"<<task1_from_db<<task2_from_db<<task3_from_db<<task4_from_db<<task5_from_db << "\n";
    }
    QString stat = "getstat = "+name_from_db+" 1."+task1_from_db+" 2."+task2_from_db+" 3."+task3_from_db+" 4."+task4_from_db+" 5."+task5_from_db;
    return stat;
}

QString upd_stat(QString login, QString task_num, QString task_status_t){
    SingletonDB *db = SingletonDB::getInstance();
    QSqlQuery query;
    QString task_status = task_status_t.trimmed();
    int taskValues = task_num.toInt();
    qDebug() << login << task_num << task_status;
    QString log = login.toUtf8();

    switch(taskValues){
    case 1:
        query.prepare("UPDATE User "
                      "SET task1 = :task1 "
                      "WHERE login == :login");
        query.bindValue(":login",log);
        query.bindValue(":task1",task_status);
        query.exec();
        break;
    case 2:
        query.prepare("UPDATE User "
                      "SET task2 = :task2 "
                      "WHERE login == :login");
        query.bindValue(":login",log);
        query.bindValue(":task2",task_status);
        query.exec();
        break;
    case 3:
        query.prepare("UPDATE User "
                      "SET task3 = :task3 "
                      "WHERE login == :login");
        query.bindValue(":login",log);
        query.bindValue(":task3",task_status);
        query.exec();
        break;
    case 4:
        query.prepare("UPDATE User "
                      "SET task4 = :task3 "
                      "WHERE login == :login");
        query.bindValue(":login",log);
        query.bindValue(":task4",task_status);
        query.exec();
        break;
    case 5:
        query.prepare("UPDATE User "
                      "SET task5 = :task5 "
                      "WHERE login == :login");
        query.bindValue(":login",log);
        query.bindValue(":task5",task_status);
        query.exec();
        break;
    }
    return "Status probably has been updated";
}

QString get_task(QString task_num){
    int task = task_num.toInt();
    switch (task) {
    case 1: {Task1(); break;}
    case 2: {Task2(); break;}
    case 3: {Task3(); break;}
    case 4: {Task4(); break;}
    case 5: {Task5(); break;}
    default: {Task5(); break;}
    }
}

QString get_stat_all(QString getstatall){

    return "";
}

QString check_task_answer(){

    return "";
}


QString parsing(QString source_str){
    QStringList data = source_str.split(' ', Qt::SkipEmptyParts);

    if (data[0] == "auth"){
        if (data.count() !=3){
            QByteArray res;
            res.append("Error auth");
            return res;
        }
        else {
            return authorization(data[1],data[2]);
        }
    }

    else if (data[0] == "reg"){
        if (data.count() !=4){
            QByteArray res;
            res.append("Error reg");
            return res;
        }
        else {
        return reg(data[1],data[2],data[3]);
        }
    }

    else if (data[0] == "getstat"){
        return get_stat(data[1]);
    }

    else if (data[0] == "updstat"){
        return upd_stat(data[1],data[2],data[3]);
    }

    else if (data[0] == "gettask"){
        return get_task(data[1]);
    }

    else if (data[0] == "getstatall"){
        return get_stat_all(data[0]);
    }

    else if (data[0] == "checktaskans"){
        return check_task_answer();
    }

    else return "error parsing/n";
}

#endif // FUNC_H
