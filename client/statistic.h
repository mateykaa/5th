#ifndef STATISTIC_H
#define STATISTIC_H

#include <QWidget>
#include <QDebug>
#include "singletonclient.h"

namespace Ui {
class Statistic;
}

class Statistic : public QWidget
{
    Q_OBJECT

public:
    explicit Statistic(QWidget *parent = nullptr);
    ~Statistic();

    void slot_show();

private slots:


    void on_getstat_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void show_statall(QString stat);


private:
    Ui::Statistic *ui;
};

#endif // STATISTIC_H
