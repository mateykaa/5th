#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    ui_auth = new authform;
    ui_task = new TaskForm;
    connect(ui_auth, &authform::onClosed, this, &MainWindow::slot_show);
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
}


void MainWindow::on_Exit_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_Task1_pushButton_clicked()
{
    qDebug()<<"task 1";
    ui_task->set_task_num(1);
}

void MainWindow::on_Task2_pushButton_clicked()
{
    qDebug()<<"task 2";
    ui_task->set_task_num(2);
}

void MainWindow::on_Task3_pushButton_clicked()
{
    qDebug()<<"task 3";
    ui_task->set_task_num(3);
}


void MainWindow::on_Task4_pushButton_clicked()
{
    qDebug()<<"task 4";
    ui_task->set_task_num(4);
}


void MainWindow::on_Task5_pushButton_clicked()
{
    qDebug()<<"task 5";
    ui_task->set_task_num(5);
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

