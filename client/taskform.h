#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include <QDebug>
#include "singletonclient.h"

namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();
    void set_task_num(int num);

private slots:
    void on_pushButton_clicked();

private:
    Ui::TaskForm *ui;

};

#endif // TASKFORM_H
