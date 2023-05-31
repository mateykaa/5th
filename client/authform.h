#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include <QDebug>
#include "singletonclient.h"

namespace Ui {
class authform;
}

class authform : public QWidget
{
    Q_OBJECT

public:
    explicit authform(QWidget *parent = nullptr);
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

private:
    void change_mode(bool mode);
    Ui::authform *ui;
    void send_signal_reg();
    void send_signal_auth();
signals:
    void onClosed(QString);
};

#endif // AUTHFORM_H
