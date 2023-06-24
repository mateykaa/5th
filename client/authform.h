#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QDebug>
#include "singletonclient.h"
//#include "mainwindow.h"

namespace Ui {
class authform;
}

/**
 * @brief Класс формы авторизации.
 *
 * Данный класс представляет форму авторизации.
 * Он наследуется от QWidget и предоставляет функциональность для
 * регистрации и входа пользователя.
 */
class authform : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса authform.
     * @param parent Родительский виджет (по умолчанию равен nullptr).
     */
    explicit authform(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса authform.
     */
    ~authform();

private slots:
    void on_sign_up_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_sign_in_pushButton_clicked();

    void on_sign_up2_pushButton_clicked();

    void success_log_in();

    void success_registration();

    void error_reg();

    void error_auth();

    //void show_stat(QString statistic);

    void on_teacher_check_stateChanged(int arg1);

private:
    /**
      * @brief Изменяет режим формы.
      * @param mode Режим формы (true - режим регистрации, false - режим входа).
      */
    void change_mode(bool mode);
    Ui::authform *ui;
    void send_signal_reg();
    void send_signal_auth();
signals:
    /**
     * @brief Сигнал о закрытии формы авторизации.
     * @param Строка с информацией.
     */
    void onClosed(QString);

    /**
     * @brief Сигнал для указания, что пользователь - преподаватель.
     */
    void teacher();

    /**
      * @brief Сигнал для указания, что пользователь - студент.
    */
    void student();
};

#endif // AUTHFORM_H
