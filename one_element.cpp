#include "one_element.h"
#include "ui_one_element.h"

One_element::One_element(Title *tit,bool root,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::One_element)
{
    ui->setupUi(this);
    ui->scrollArea_2->setWidget(ui->descr);
    ui->scrollArea_3->setWidget(ui->name);
    ui->scrollArea_4->setWidget(ui->genre);
    rec = tit;
    ui->name->setText("Название: "+rec->get_name());
    ui->genre->setText("Жанр: "+rec->get_genre());
    ui->descr->setText("Описание\n" + rec->get_descr());
    ui->image->setText("");
    ui->image->setFixedSize(QSize(200,200));
    ui->image->setIconSize(QSize(200,200));
    ui->image->setIcon(tit->get_icon());
    if(root)
    {
        delete_button = new QPushButton();
        edit_button = new QPushButton();
        delete_button->setText("Удалить");
        edit_button->setText("Изменить");
        ui->Admin_buttons->addWidget(delete_button);
        ui->Admin_buttons->addWidget(edit_button);
        connect(delete_button,SIGNAL(clicked()),this,SLOT(remove_title()));
        connect(edit_button,SIGNAL(clicked()),this,SLOT(edit()));
    }
}

One_element::~One_element()
{
    delete ui;
}
One_element* One_element::operator=(const Title* send)
{
    this->rec = new Title();
    *rec=*send;
    return this;
}

void One_element::on_Ok_clicked()
{
    close();
    emit signal();
}
void One_element::remove_title()
{
    close();
    emit removing_signal();
}
void One_element::edit()
{

    edit_wind = new Edit_Master(rec);
    connect(edit_wind,&Edit_Master::cancel_signal,this,&One_element::remove_title);
    connect(edit_wind,&Edit_Master::signal,this,&One_element::signal);
    edit_wind->show();
    hide();
}
int One_element::get_num()
{
    return rec->get_button()->getID();
}
