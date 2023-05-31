#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qDebug>
#include "authform.h"
#include "taskform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Exit_pushButton_clicked();

    void on_Exit_action_triggered();

    void on_Task1_pushButton_clicked();

    void slot_show(QString login);
    void on_Task2_pushButton_clicked();

    void on_Task3_pushButton_clicked();

    void on_Task4_pushButton_clicked();

    void on_Task5_pushButton_clicked();

    void on_Task1_action_triggered();

    void on_Task2_action_triggered();

    void on_Task3_action_triggered();

    void on_Task4_action_triggered();

    void on_Task5_action_triggered();

private:
    Ui::MainWindow *ui;
    authform *ui_auth;
    TaskForm *ui_task;
};
#endif // MAINWINDOW_H
