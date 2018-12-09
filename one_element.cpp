#include "one_element.h"
#include "ui_one_element.h"

One_element::One_element(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::One_element)
{
    ui->setupUi(this);

}

One_element::~One_element()
{
    delete ui;
}
One_element* One_element::operator=(const Title* send)
{
    this->rec = new Title(send);
   *(this->rec)=*send;
    return this;
}
