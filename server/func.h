/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе опредления основных
классов, используемых в программе
*/
#ifndef FUNC_H
#define FUNC_H
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QVector>
#include "singletondb.h"
#include <QTextStream>
#include <QtMath>

/*!
\brief Авторизация пользователя в программе
\param login Логин пользователя
\param password Пароль пользователя
\return Ответ системы(успешно или нет)

Данный класс позволяет пользователям
авторизироваться в программе и выдает
ответ системы на входные данные
*/
QString authorization(QString login, QString password, QString socket_id);

/*!
\brief Регистрация пользователя в программе
\param login Логин пользователя
\param password Пароль пользователя
\param email Эл. почта пользователя
\return Ответ системы

Данный класс позволяет новым пользователям
зарегистрироваться. Программа выдает сообщение
о том, что пользователь не зарегистрирован.
После этого идёт процедура регитсрации.
Если пользоваель задаёт логин, который уже
есть в системе, то система сообщает,
что такой логин уже используется.
Иначе происзодит добавление новых сведений.
Выдаётся сообщение о том, что пользователь
успешно зарегистрирован.
*/
QString reg(QString login,QString password, QString email, QString role, QString surname, QString name);

/*!
\brief Статистика ???
\param login Логин пользователя
\param task Задание
\param stat Статистика

Данный класс позволяет обновлять статистику ???
*/
QString upd_stat(QString login, QString task_num, QString YN_t);

QString buildKarnaughMap(QString variant);

bool checkTask1(QString variant_for_task, QString task_ans_t);

/*!
\brief Основная страница
\param login Логин пользователя

Данный класс выводит статистику заданий по Логину пользователя
*/
QString get_stat(QString login);
QString get_stat_all();
QString Task1();
QString get_task(QString task_num);
QString check_task_answer(QString login, QString task_num, QString variant_for_task, QString task_ans_t);
QString exit(QString login);

/*!
\brief Сбор и структуризация данных ???
\param source_str

Данный класс позволяет передать
информацию???
*/
QString parsing(QString source_str, QString socket_id);
#endif // FUNC_H
