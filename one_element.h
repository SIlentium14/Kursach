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
namespace Ui {
class One_element;
}

class One_element : public QDialog
{
    Q_OBJECT
public:
    explicit One_element(QWidget *parent = nullptr);
    ~One_element();
    One_element *operator=(const Title* send);
signals:

    void signal();

private:
    Ui::One_element *ui;
    Title *rec;
};

#endif // ONE_ELEMENT_H
