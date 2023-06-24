#include "taskform.h"
#include "ui_taskform.h"
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <QCoreApplication>
#include <QDateTime>

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
}

TaskForm::~TaskForm()
{
    delete ui;
}


void TaskForm::on_pushButton_clicked()
{
    QString message = "checktaskans "+name+" " + QString::number(numb)+" "+string + " " + ui->answer_lineEdit->text();
    SingletonClient::getInstance()->send_msg_to_server(message);
    ui->answer_lineEdit->setText("");
    this->close();
}

void TaskForm::set_task_num(int num, QString namest)
{
    QString secondHalf;
    QString firstHalf;
    QString str;
    name = namest;
    numb = num;

    switch (num) {
    case 1:
        str = create_array_M(num);
        string = str;
        ui->label->setText("№1: построить карту карно по М1:");
        ui->tasknum_lable->setText("массив: {"+ str+"}");
        break;
    case 2:
        ui->label->setText("№2: проверить систему функций (заданных векторами значений) на полноту");
        str = create_array_M(num);
        string = str;
        firstHalf = str.left(8);
        secondHalf = str.right(8);
        ui->tasknum_lable->setText("первый массив: {"+ firstHalf+"} второй массив: {"+secondHalf+"}");
        break;
    case 3:
        str = create_array_M(num);
        string = str;
        ui->label->setText("№3: проверить функцию на линейность");
        ui->tasknum_lable->setText("массив: {"+ str+"}");
        break;
    case 4:
        str = create_array_M(num);
        string = str;
        ui->label->setText("№4: по м1 проверить функцию на монотонность");
        ui->tasknum_lable->setText("массив: {"+ str+"}");
        break;
    case 5:
        str = create_array_M(num);
        string = str;
        ui->label->setText(+ "№5: по вектору значений  построить двойственную функцию (при результате INFINITY обозначать i)");
        ui->tasknum_lable->setText("массив: {"+ str+"}");
        break;

    }

    //ui->tasknum_lable->setText("{ "+create_array_M(num)+"}");
    this->show();
}

std::random_device rd;
std::mt19937 gen(rd());




QString TaskForm::create_array_M(int tasknum) {

    QString array_M;

    if (tasknum==2) {
        int *arr= new int[16];
        for (int i=0; i<16; i++) {
            int numb;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, 1);
            numb = distr(gen);
            arr[i] = numb;
            array_M.append(QString::number(numb));
            //array_M.append(" ");
        }

        return array_M;
    }
    else {
        int *arr= new int[8];
        for (int i=0; i<8; i++) {
            int numb;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(0, 1);
            numb = distr(gen);
            arr[i] = numb;
            array_M.append(QString::number(numb));
        }

        return array_M;
    }
}



