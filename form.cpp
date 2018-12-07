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
    scrollArea->resize(650,600);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(ui->gridLayoutWidget);
    // заполнение вектора
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
//    QVBoxLayout *vbox = new QVBoxLayout;
//    QLabel *s = new QLabel;
//    s->setText("kaka");

//    QPushButton *but = new QPushButton(this);
//    but->setFixedHeight(140);
//    but->setFixedWidth(160);
//    s->setFixedHeight(40);
//    s->setFixedWidth(160);
//    vbox->addWidget(but,1);
//    vbox->addWidget(s,1);
//    stand_box = new QGroupBox;
//    stand_box->setFixedHeight(200);
//    stand_box->setFixedWidth(200);
//    stand_box->setLayout(vbox);
//   // stand_box->setTitle("Title");
//    stand_box->setMouseTracking(true);
//    stand_box->setFocusPolicy(Qt::ClickFocus);
    Title a(1);
    stand_box = a.get_adding_box();
    ui->gridLayout->addWidget(stand_box,row_count,column_count++);
   // connect(stand_box,SIGNAL(clicked()),this,SLOT(box_click()));
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
