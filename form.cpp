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
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *s = new QLabel;
    s->setText("kaka");
    vbox->addWidget(s,1);
    ss = new QGroupBox;
    ss->setFixedHeight(100);
    ss->setFixedWidth(100);
    ss->setLayout(vbox);
    ss->setTitle("Title");
    ui->gridLayout->addWidget(ss,row_count,column_count++);
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
