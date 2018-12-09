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
//    Title* a = new Title;
//    stand_box = a->get_adding_box();
//    ui->gridLayout->addWidget(stand_box,row_count,column_count++);
//    One_element *send = new One_element;
//    *send = a;
//    connect(a,&One_element::signal,this,&One_element::show);
//    //send->show();
    box_ = new QGroupBox();
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *s = new QLabel;
    s->setText("");
    QPushButton *but = new QPushButton();
    but->setFixedHeight(150);
    but->setFixedWidth(150);
    but->setCursor(Qt::PointingHandCursor);
    QPixmap m(":/new/prefix1/no_image.png");
    but->setIcon(m);
    but->setIconSize(QSize(150,150));
    s->setFixedHeight(40);
    s->setFixedWidth(160);
    vbox->addWidget(but,1);
    vbox->addWidget(s,1);
    box_ = new QGroupBox;
    box_->setFixedHeight(200);
    box_->setFixedWidth(200);
    box_->setLayout(vbox);
    ui->gridLayout->addWidget(box_,row_count,column_count++);
    box_checker();
    connect(but,SIGNAL(clicked()),this,SLOT(element_clicked()));
}
void Form::box_checker()
{
    if(column_count==3)
    {
        column_count=0;
        row_count++;
    }

}

void Form::element_clicked()
{
    Title* temp = (Title*) sender();


}
