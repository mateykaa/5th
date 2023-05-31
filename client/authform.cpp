#include "authform.h"
#include "ui_authform.h"


authform::authform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::authform)
{

    ui->setupUi(this);
    this->change_mode(false); //true == reg

}

authform::~authform()
{
    delete ui;
}

void authform::change_mode(bool mode) { //true == reg
    ui->email_label->setVisible(mode);
    ui->email_lineEdit->setVisible(mode);
    ui->exit_pushButton->setVisible(mode);
    ui->sign_up_pushButton->setVisible(!mode);
    ui->reg_label->setVisible(mode);
    ui->auth_label->setVisible(!mode);
    ui->sign_in_pushButton->setVisible(!mode);
    ui->sign_up2_pushButton->setVisible(mode);
    ui->error_label->setVisible(false);
    ui->error_reg_label->setVisible(false);
}

void authform::on_sign_up_pushButton_clicked()
{
    this->change_mode(true);
}


void authform::on_exit_pushButton_clicked()
{
    this->change_mode(false);

}


void authform::on_sign_in_pushButton_clicked()
{
    //emit onClosed(ui->log_lineEdit->text());
    QString message = "auth "+ui->log_lineEdit->text()+" "+ui->pas_lineEdit->text()+" ";
    SingletonClient::getInstance()->send_msg_to_server(message);
    send_signal_auth();
    //this->close();
}


void authform::on_sign_up2_pushButton_clicked()
{
    //emit onClosed(ui->log_lineEdit->text());
    QString message ="reg "+ui->log_lineEdit->text()+" "+ui->pas_lineEdit->text()+" "+ui->email_lineEdit->text();
    SingletonClient::getInstance()->send_msg_to_server(message);
    send_signal_reg();
    //this->close();
}

void authform::send_signal_reg() {
    connect(SingletonClient::getInstance(),&SingletonClient::registered,this,&authform::success_registration);
    connect(SingletonClient::getInstance(),&SingletonClient::user_exists,this,&authform::error_reg);
}

void authform::send_signal_auth() {
    connect(SingletonClient::getInstance(),&SingletonClient::log_in,this,&authform::success_log_in);
    connect(SingletonClient::getInstance(),&SingletonClient::wrong_pass_name,this,&authform::error_auth);
}

void authform::success_registration() {
    this->close();
    emit onClosed(ui->log_lineEdit->text());
}

void authform::success_log_in() {
    this->close();
    emit onClosed(ui->log_lineEdit->text());
}

void authform::error_reg() {
    qDebug() <<"ERROR!";
   ui->error_reg_label->setVisible(true);
}

void authform::error_auth() {
    qDebug() << "ERROR!";
    ui->error_label->setVisible(true);
}
