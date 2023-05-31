#include "taskform.h"
#include "ui_taskform.h"
#include <QDebug>

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
    SingletonClient::getInstance()->send_msg_to_server("check ");
    this->close();
}

void TaskForm::set_task_num(int num)
{
    //this->task_number = num;
    ui->tasknum_lable->setText(QString::number(num));
    this->show();
}
