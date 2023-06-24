#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "statistic.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    ui_auth = new authform;
    ui_task = new TaskForm;
    ui_stat = new Statistic;
    connect(ui_auth, &authform::onClosed, this, &MainWindow::slot_show);
    connect(ui_auth, &authform::student, this, &MainWindow::signal_student);
    connect(SingletonClient::getInstance(),&SingletonClient::get_stat,this, &MainWindow::showstat);
    connect(ui_auth, &authform::teacher, this, &MainWindow::signal_teacher);
    connect(SingletonClient::getInstance(),&SingletonClient::teacher,this,&MainWindow::signal_teacher);
    connect(SingletonClient::getInstance(),&SingletonClient::student,this,&MainWindow::signal_student);


    ui_auth->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_show(QString login) {
    this->show();
    ui->setupUi(this);
    ui->log_label->setText(login);
    if (role=="t") {
        ui->teacher_button->setVisible(true);
    }

    //QString message ="getstat "+login;
    //SingletonClient::getInstance()->send_msg_to_server(message);

}

void MainWindow::showstat(QString stat) {
    QStringList statList = stat.split(" ");
    QString output = "";
    for (int i = 2; i < statList.size(); i++) {
        QStringList item = statList[i].split(".");
        output+="Задача:\t"+item[0]+ "\tБалл:\t"+item[1]+"\n";
        //qDebug()<<"number: "<<item[0]<< " ball: " <<item[1];
        //qDebug()<<output;
    }
    ui->Stat_label->setText(output);
}



void MainWindow::signal_teacher() {
    ui->teacher_button->setVisible(true);
    ui->role_label->setText("Преподаватель");
}

void MainWindow::signal_student() {
    ui->teacher_button->setVisible(false);
    ui->role_label->setText("Студент");
}




void MainWindow::on_Exit_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_Task1_pushButton_clicked()
{
    qDebug()<<"task 1";
    ui_task->set_task_num(1, ui->log_label->text());
}

void MainWindow::on_Task2_pushButton_clicked()
{
    qDebug()<<"task 2";
    ui_task->set_task_num(2, ui->log_label->text());
}

void MainWindow::on_Task3_pushButton_clicked()
{
    qDebug()<<"task 3";
    ui_task->set_task_num(3, ui->log_label->text());
}


void MainWindow::on_Task4_pushButton_clicked()
{
    qDebug()<<"task 4";
    ui_task->set_task_num(4, ui->log_label->text());

}


void MainWindow::on_Task5_pushButton_clicked()
{
    qDebug()<<"task 5";
    ui_task->set_task_num(5, ui->log_label->text());
}

void MainWindow::on_Exit_action_triggered()
{
    this->on_Exit_pushButton_clicked();
}

void MainWindow::on_Task1_action_triggered()
{
    this->on_Task1_pushButton_clicked();
}


void MainWindow::on_Task2_action_triggered()
{
    this->on_Task2_pushButton_clicked();
}


void MainWindow::on_Task3_action_triggered()
{
    this->on_Task3_pushButton_clicked();
}


void MainWindow::on_Task4_action_triggered()
{
    this->on_Task4_pushButton_clicked();
}


void MainWindow::on_Task5_action_triggered()
{
    this->on_Task5_pushButton_clicked();
}


void MainWindow::on_teacher_button_clicked()
{
    qDebug()<<"STATISTIC";
    //SingletonClient::getInstance()->send_msg_to_server("getstatall");
    ui_stat->slot_show();
}


void MainWindow::on_getstat_pushbutton_clicked()
{
    ui->log_label->text();
    QString query = "getstat "+ui->log_label->text();
    SingletonClient::getInstance()->send_msg_to_server(query);

}


