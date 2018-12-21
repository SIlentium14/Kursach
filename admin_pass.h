#ifndef ADMIN_PASS_H
#define ADMIN_PASS_H
#include <QMessageBox>
#include <QDialog>
#include <QFile>
namespace Ui {
class Admin_pass;
}

class Admin_pass : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_pass(QWidget *parent = nullptr);
    ~Admin_pass();
    void edit_pass();
signals:
    void true_signal();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Admin_pass *ui;
    QString private_information;
};

#endif // ADMIN_PASS_H
