#include "statistic.h"
#include "ui_statistic.h"

Statistic::Statistic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Statistic)
{
    ui->setupUi(this);
    connect(SingletonClient::getInstance(),&SingletonClient::get_statall,this, &Statistic::show_statall);
}

Statistic::~Statistic()
{
    delete ui;
}

void Statistic::slot_show() {
    this->show();
}

void Statistic::show_statall(QString stat) {
    QStringList statList = stat.split("&");
    QString students = "";
    QString num1 = "";
    QString num2 = "";
    QString num3 = "";
    QString num4 = "";
    QString num5 = "";
    for (int i = 1; i < statList.size(); i++) {
        QStringList studList = statList[i].split(" ");
        students+=studList[0]+"\n\n";
        QStringList item1 = studList[1].split(".");
        num1 += item1[1]+"\n\n";
        QStringList item2 = studList[2].split(".");
        num2 += item2[1]+"\n\n";
        QStringList item3 = studList[3].split(".");
        num3 += item3[1]+"\n\n";
        QStringList item4 = studList[4].split(".");
        num4 += item4[1]+"\n\n";
        QStringList item5 = studList[5].split(".");
        num5 += item5[1]+"\n";
    }
    ui->student_label->setText(students);
    ui->num1_label->setText(num1);
    ui->num2_label->setText(num2);
    ui->num3_label->setText(num3);
    ui->num4_label->setText(num4);
    ui->num5_label->setText(num5);


    /*for (int i = 2; i < statList.size(); i++) {
        QStringList item = statList[i].split(".");
        output+="Задача:\t"+item[0]+ "\tБалл:\t"+item[1]+"\n";
        qDebug()<<"number: "<<item[0]<< " ball: " <<item[1];
        //qDebug()<<output;
   }*/
}


/*void MainWindow::showstat(QString stat) {
    QStringList statList = stat.split(" ");
    QString output = "";
    for (int i = 2; i < statList.size(); i++) {
        QStringList item = statList[i].split(".");
        output+="Задача:\t"+item[0]+ "\tБалл:\t"+item[1]+"\n";
        //qDebug()<<"number: "<<item[0]<< " ball: " <<item[1];
        //qDebug()<<output;
    }
    ui->Stat_label->setText(output);
}*/



void Statistic::on_getstat_pushButton_clicked()
{
    QString query = "getstatall";
    SingletonClient::getInstance()->send_msg_to_server(query);
}


void Statistic::on_exit_pushButton_clicked()
{
    this->close();
}

