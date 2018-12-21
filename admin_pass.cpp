#include "admin_pass.h"
#include "ui_admin_pass.h"

Admin_pass::Admin_pass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_pass)
{
    ui->setupUi(this);
    this->setWindowTitle("Авторизация");
    QFile pass("not_password.not_txt");
    pass.open(QIODevice::ReadOnly);
    QDataStream pass_stream(&pass);
    pass_stream >> private_information;
    if(private_information == "")
        ui->label->setText("Задайте новый пароль:");
    pass.close();
}

Admin_pass::~Admin_pass()
{
    delete ui;
}
void Admin_pass::on_pushButton_clicked()
{
    QString user_input = ui->lineEdit->text();
    if(user_input == private_information && private_information!="")
        emit true_signal();
    else
        if(private_information!="")
            QMessageBox::warning(this,"Авторизация","Неверный пароль!");
        else
        {
            QFile pass("not_password.not_txt");
            pass.open(QIODevice::WriteOnly);
            QDataStream stream(&pass);
            stream<<user_input;
            pass.close();
            close();
            emit true_signal();
        }

}

void Admin_pass::on_pushButton_2_clicked()
{
    close();
}
void Admin_pass::edit_pass()
{
    QFile pass("not_password.not_txt");
    pass.open(QIODevice::WriteOnly);
    pass.close();
    private_information = "";
    ui->label->setText("Задайте новый пароль: ");
}
