#include "form.h"
#include "ui_form.h"
#include "dynamicbutton.h"
using namespace std;
Form::Form(bool root,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    is_admin_ = root;
    ui->setupUi(this);
    this->setWindowTitle("List");
    if(!is_admin_)
    {
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        ui->pushButton_4->hide();
    }
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->resize(650,600);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(ui->gridLayoutWidget);
    add_master();
}
void Form::add_master()
{
    Layout_clearer();
    data = new QFile("data.txt");
    data_picture = new QFile("pictures");
    data->open(QIODevice::ReadOnly);
    data_picture->open(QIODevice::ReadOnly);
    if(!(data->isOpen() && data_picture->isOpen() ))
    {
        QMessageBox::warning(this,"Открытие файла","Файл поврежден!");
    }
    all_.clear();
    while(!data->atEnd())
    {

        add_box();
    }

    this->show();
}
Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    add_master();
    data->close();
    data_picture->close();
    data = new QFile("data.txt");
    data_picture = new QFile("pictures");
    data->open(QIODevice::WriteOnly);
    data_picture->open(QIODevice::WriteOnly);
    QTextStream stream(data);
    QDataStream img_stream(data_picture);
    for(auto a: all_)
    {
        if(a.get_name() =="" && a.get_genre() == "" && a.get_descr() =="")
            continue;
        stream<<a.get_descr()
             <<a.get_genre()
            <<a.get_name();
        img_stream<<a.image_;
    }
    data->close();
    data_picture->close();
    emit signal();
    close();
}

void Form::on_pushButton_2_clicked()
{
    data = new QFile("data.txt");
    data_picture = new QFile("pictures");
    data->open(QIODevice::WriteOnly);
    data_picture->open(QIODevice::WriteOnly);
    data->close();
    data_picture->close();
    add_master();
}
void Form::add_box()
{
    Title temp;
    QDataStream img_stream(data_picture);
    temp.set_data(data->readLine(),data->readLine(),data->readLine());
    QPixmap first_image;
    img_stream>>first_image;
    temp.set_image(first_image);
    temp.set_but_ID(all_.size());
    if(temp.get_name().isEmpty() && temp.get_genre().isEmpty() && temp.get_descr().isEmpty())
        return;
    all_.push_back(temp);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(all_.back().get_button(),1);
    QLabel* name_label = new QLabel();
    name_label->setText(all_.back().get_name());
    QScrollArea *name_area = new QScrollArea;
    name_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    name_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    name_area->setWidgetResizable(false);
    name_area->setFixedHeight(43);
    name_area->setFixedWidth(150);
    name_area->setWidget(name_label);

    vbox->addWidget(name_area,1);
    all_.back().set_layout(vbox);
    ui->gridLayout->addWidget(all_.back().get_box(),row_count,column_count++);
    box_checker();
    connect(all_.back().get_button(),SIGNAL(clicked()),this,SLOT(element_clicked()));
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
    DynamicButton* temp = (DynamicButton*) sender();
    Title *tit = new Title(all_[temp->getID()]);
    tit->set_but_ID(temp->getID());
    One_element* wind = new One_element(tit,is_admin_);
    wind->show();
    //hide();
    connect(wind,&One_element::removing_signal,this,&Form::deleting_signal_action);
    connect(wind,&One_element::signal,this,&Form::add_master);
    close();
}
void Form::image_clicked(Title *temp)
{
    One_element* wind = new One_element(temp,is_admin_);
    connect(wind,&One_element::signal,this,&Form::show);
    wind->show();
    hide();
    data->close();
    data_picture->close();
}

void Form::on_pushButton_3_clicked()
{
    Title* temp = new Title();
    temp->set_data(" "," "," ");
    Edit_Master* edt = new Edit_Master(temp);
    connect(edt,&Edit_Master::signal,this,&Form::add_master);
    edt->show();
    hide();
}
void Form::deleting_signal_action()
{
    One_element* receiver = (One_element*) sender();
    all_.erase(all_.begin() + receiver->get_num());
    redrawind();
}
void Form::redrawind()
{
    Layout_clearer();
    data = new QFile("data.txt");
    data_picture = new QFile("pictures");
    data->open(QIODevice::WriteOnly);
    data_picture->open(QIODevice::WriteOnly);
    QTextStream stream(data);
    QDataStream img_stream(data_picture);
    for(auto a: all_)
    {
        if(a.get_name() =="" && a.get_genre() == "" && a.get_descr() =="")
            continue;
        stream<<a.get_descr()
             <<a.get_genre()
            <<a.get_name();
        img_stream<<a.image_;
    }
    data->close();
    data_picture->close();
    add_master();
}
void Form::Layout_clearer()
{
    QLayoutItem *item;
    while((item = ui->gridLayout->takeAt(0)) != 0)
    {
        ui->gridLayout->removeItem(item);
        item->widget()->deleteLater();
        delete item;
    }
    column_count = row_count = 0;
}


void Form::on_pushButton_5_clicked()
{
    qSort(all_.begin(),all_.end(),[]( Title &rhs, Title &lhs){return rhs.get_name() < lhs.get_name();});
    redrawind();
}

void Form::on_pushButton_4_clicked()
{
    adm = new Admin_pass();
    adm->edit_pass();
    connect(adm,&Admin_pass::true_signal,this,&Form::show);
    adm->show();
    hide();
}
