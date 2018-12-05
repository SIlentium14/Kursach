#include "form.h"
#include "ui_form.h"
using namespace std;
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->resize(400,300);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(ui->gridLayoutWidget);

}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    emit signal();
    close();
}

void Form::on_pushButton_2_clicked()
{
   add_box();
}
void Form::add_box()
{
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *s = new QLabel;
    s->setText("kaka");
    vbox->addWidget(s,1);
    stand_box = new QGroupBox;
    stand_box->setFixedHeight(100);
    stand_box->setFixedWidth(100);
    stand_box->setLayout(vbox);
    stand_box->setTitle("Title");
    ui->gridLayout->addWidget(stand_box,row_count,column_count++);
    box_checker();
}
void Form::box_checker()
{
    if(column_count==3)
    {
        column_count=0;
        row_count++;
    }

}
