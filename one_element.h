#ifndef ONE_ELEMENT_H
#define ONE_ELEMENT_H

#include <QDialog>
#include <QString>
#include <QPixmap>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "title.h"
#include "edit_master.h"
namespace Ui {
class One_element;
}

class One_element : public QDialog
{
    Q_OBJECT
public:
    explicit One_element(Title *,bool root = false,QWidget *parent = nullptr);
    ~One_element();
    One_element *operator=(const Title* send);
    int get_num();
signals:

    void signal();

    void removing_signal();

private slots:
    void remove_title();
    void edit();
    void on_Ok_clicked();

private:
    QPushButton *delete_button;
    QPushButton *edit_button;
    Ui::One_element *ui;
    Title *rec;
    Edit_Master *edit_wind;
};

#endif // ONE_ELEMENT_H
