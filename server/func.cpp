#include "func.h"

QString authorization(QString login, QString password, QString socket_id){
    SingletonDB *db = SingletonDB::getInstance();

    QString log_from_db, pass_from_db, role_from_db;
    QSqlQuery query;
    query.prepare("SELECT * FROM User WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    qDebug() << "authentication...";

    QSqlRecord rec = query.record();
    const int loginIndex = rec.indexOf("login");
    const int passwordIndex = rec.indexOf("password");
    const int roleIndex = rec.indexOf("role");

    while(query.next())
        log_from_db = query.value(loginIndex).toString(), pass_from_db = query.value(passwordIndex).toString(),
                role_from_db = query.value(roleIndex).toString();
    QString status = "Wrong username or password! ";

    if (login == log_from_db && password.trimmed() == pass_from_db){
        if (role_from_db == "s")
        {
            status = "Welcome! Student";
        }
        else if (role_from_db == "t")
        {
            status = "Welcome! Teacher";
        }
        else{
            status = "Welcome! Admin";
        }
        query.prepare("UPDATE User SET socket=:socket WHERE login=:login");
        query.bindValue(":socket",socket_id);
        query.bindValue(":login",login);
        query.exec();
    }
//    qDebug()<<socket_id;
    return status;
}

QString reg(QString login,QString password, QString email, QString role, QString surname, QString name){
    SingletonDB *db = SingletonDB::getInstance();

//    qDebug()<<login<<password<<email<<role<<surname<<name;
    QSqlQuery query;
    QString stat = "You are not registered!";
    QString log_from_db, pass_from_db, email_from_db, role_from_db, surname_from_db, name_from_db;
    query.prepare("SELECT * FROM User "
                  "WHERE login == :login");
    query.bindValue(":login",login);
    query.exec();

    QSqlRecord rec = query.record();
    while(query.next())
        log_from_db = query.value(rec.indexOf("login")).toString();
//    qDebug()<<log_from_db;
    if (login == log_from_db){
        stat = "This username is already used!";
    }
    else{
        query.prepare("INSERT INTO User(login, password, email, role, surname, name) "
                           "VALUES (:login, :password, :email, :role, :surname, :name)");
        query.bindValue(":password",password);
        query.bindValue(":login",login);
        query.bindValue(":email",email);
        query.bindValue(":role",role);
        query.bindValue(":surname",surname);
        query.bindValue(":name",name);
        query.exec();

        query.prepare("SELECT * FROM User "
                    "WHERE login == :login");
        query.bindValue(":login",login);
        query.exec();

        QSqlRecord rec = query.record();
        const int loginIndex = rec.indexOf("login");
        const int passwordIndex = rec.indexOf("password");
        const int emailIndex = rec.indexOf("email");
        const int roleIndex = rec.indexOf("role");
        const int surnameIndex = rec.indexOf("surname");
        const int nameIndex = rec.indexOf("name");

        while(query.next()){
            log_from_db = query.value(loginIndex).toString();
//            qDebug()<<log_from_db<<"log_from_db";
            pass_from_db = query.value(passwordIndex).toString();
            email_from_db = query.value(emailIndex).toString();
            role_from_db = query.value(roleIndex).toString();
            surname_from_db = query.value(surnameIndex).toString();
            name_from_db = query.value(nameIndex).toString();
//            qDebug()<<"over";
//            qDebug()<<log_from_db <<"\t"<<pass_from_db<<"\t" << email_from_db << "\n"<<role_from_db<<"\t"<<surname_from_db<<"\t"<<name_from_db<<"\t"   ;
        }
        if (login == log_from_db && password == pass_from_db && email == email_from_db)
        {
            stat = "You have been successfully registered!";
        }
     }

    return stat;
}

QString upd_stat(QString login, QString task_num, QString YN_t){
    SingletonDB *db = SingletonDB::getInstance();

    QSqlQuery query;
    int taskValues = task_num.toInt();
    QString YN = YN_t.trimmed();
    switch(taskValues)
    {
        case 1:
            if (YN == "y"){
                query.prepare("UPDATE User SET task1 = task1 + 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1+";
            }
            else {
                query.prepare("UPDATE User SET task1 = task1 - 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1-";
            }
            break;
        case 2:
            if (YN == "y"){
                query.prepare("UPDATE User SET task2 = task2 + 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1+";
            }
            else {
                query.prepare("UPDATE User SET task2 = task2 - 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1-";
            }
            break;
        case 3:
            if (YN == "y"){
                query.prepare("UPDATE User SET task3 = task3 + 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1+";
            }
            else {
                query.prepare("UPDATE User SET task3 = task3 - 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1-";
            }
            break;
        case 4:
            if (YN == "y"){
                query.prepare("UPDATE User SET task4 = task4 + 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1+";
            }
            else {
                query.prepare("UPDATE User SET task4 = task4 - 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1-";
            }
            break;
        case 5:
            if (YN == "y"){
                query.prepare("UPDATE User SET task5 = task5 + 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1+";
            }
            else {
                query.prepare("UPDATE User SET task5 = task5 - 1 WHERE login == :login");
                query.bindValue(":login",login);
                query.exec();
                return "1-";
            }
            break;

        return "Status updated";
    }
}


// Функция для построения карты Карно
QString buildKarnaughMap(QString variant) {
    int numVars = 4;  // Определяем количество переменных в функции М1
    int numRows = 4;    // Определяем количество строк в таблице
    int numCols = 4; // Определяем количество столбцов в таблице

    QVector<QVector<QString>> karnaughMap(numRows, QVector<QString>(numCols, 0)); // Создаем и инициализируем карту Карно

    // Заполняем значениями карту Карно
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            karnaughMap[i][j] = variant[i * numCols + (numCols - 1 - j)];
        }
    }

    // Выводим карту Карно
    QString stattt = "";
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            stattt +=karnaughMap[i][j];
        }
        stattt+="|";
    }
    qDebug()<<stattt;

    return stattt;
}

bool checkTask1(QString variant_for_task, QString task_ans_t){
    bool res= buildKarnaughMap(variant_for_task)== task_ans_t;

    return res;
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
//        qDebug()<<name_from_db <<"\t"<<task1_from_db<<task2_from_db<<task3_from_db<<task4_from_db<<task5_from_db << "\n";
    }
    QString stat =name_from_db+" 1."+task1_from_db+" 2."+task2_from_db+" 3."+task3_from_db+" 4."+task4_from_db+" 5."+task5_from_db;
    return stat;
}

QString get_stat_all(){
    SingletonDB *db = SingletonDB::getInstance();

    QSqlQuery query;
    QString name_from_db, task1_from_db, task2_from_db, task3_from_db, task4_from_db, task5_from_db;
    query.prepare("Select * from User;");
    query.exec();

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf("login");
    const int task1Index = rec.indexOf("task1");
    const int task2Index = rec.indexOf("task2");
    const int task3Index = rec.indexOf("task3");
    const int task4Index = rec.indexOf("task4");
    const int task5Index = rec.indexOf("task5");
    QString res = "";

    while(query.next()){
        name_from_db = query.value(nameIndex).toString(), task1_from_db = query.value(task1Index).toString(),
                task2_from_db = query.value(task2Index).toString(), task3_from_db = query.value(task3Index).toString(),
                    task4_from_db = query.value(task4Index).toString(), task5_from_db = query.value(task5Index).toString();
//        qDebug()<<name_from_db <<"\t"<<task1_from_db<<task2_from_db<<task3_from_db<<task4_from_db<<task5_from_db << "\n";
        QString stat = name_from_db+" 1."+task1_from_db+" 2."+task2_from_db+" 3."+task3_from_db+" 4."+task4_from_db+" 5."+task5_from_db + "\n";
        res+=stat;
    }
    return res;
}


QString Task1(){
//построить карту карно по М1
    QString res = "Построить карту карно по М1";
//    qDebug()<<"task1";
    return res;
}

QString get_task(QString task_num){
    if (task_num == "1")
        return Task1();
    return "no task";
}

QString check_task_answer(QString login, QString task_num, QString variant_for_task, QString task_ans_t){
    QString task_ans = task_ans_t.trimmed();
    int taskValues = task_num.toInt();
    QString res = "n";
    switch(taskValues){
        case 1:
            if(checkTask1(variant_for_task,task_ans_t))
                res = "y";
            break;
        case 2:
//            checkTask2();
            break;
        case 3:
//            checkTask3();
            break;
        case 4:
//            checkTask4();
            break;
        case 5:
//            checkTask5();
            break;


    }
    upd_stat(login,task_num,res);
    return "abc";
}

QString exit(QString login){
    QString res = "exit ok";
    SingletonDB::getInstance()->unlogin(login);
    return res;
}

/*!
\brief Сбор и структуризация данных ???
\param source_str

Данный класс позволяет передать
информацию???
*/
QString parsing(QString source_str, QString socket_id){
    QStringList data = source_str.split(' ', Qt::SkipEmptyParts);
//    qDebug()<< data << socket_id;
    if (data[0] == "auth" and data.count() == 3)
    {
            return authorization(data[1],data[2],socket_id);
    }

    else if (data[0] == "reg")
    {
        return reg(data[1],data[2],data[3],data[4],data[5],data[6]);
    }

    else if (data[0] == "getstat")
    {
        return get_stat(data[1]);
    }

    else if (data[0] == "updstat")
    {
        return upd_stat(data[1],data[2],data[3]);
    }

    else if (data[0] == "gettask")
    {
        QString data1 = data[1].trimmed();
        return get_task(data1);
    }

    else if (data[0] == "getstatall")
    {
        return get_stat_all();
    }

    else if (data[0] == "checktaskans")
    {
        return check_task_answer(data[1],data[2],data[3],data[4]);
    }

    else if (data[0] == "exit")
    {
        return exit(data[1]);
    }
    else return "error parsing/n";
}
