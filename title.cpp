#include "title.h"

Title::Title(bool is_admin) : is_admin_(is_admin)
{
    name_ = "";
    genre_ = "";
    descr_ = "";
    image_.load(":/new/prefix1/no_image.png"); // потом заменить
    box_ = new QGroupBox;
    box_->setFixedHeight(200);
    box_->setFixedWidth(200);
    button_ = new DynamicButton(0);
    button_->setFixedHeight(150);
    button_->setFixedWidth(150);
    button_->setCursor(Qt::PointingHandCursor);
    button_->setIcon(image_);
    button_->setIconSize(QSize(150,150));

}
void Title::set_data(QString name,QString genre,QString descr)
{
    name_ = name;
    genre_ = genre;
    descr_ = descr;
}
void Title::create()
{


}

void Title::delete_element()
{
    name_.clear();// = "";
    genre_.clear();
    descr_.clear();
    image_.load(":/new/prefix1/no_image.png");
}
void Title::show_one()
{


}

QGroupBox* Title::get_adding_box()
{
    box_ = new QGroupBox();
    QVBoxLayout *vbox = new QVBoxLayout;
    QLabel *s = new QLabel;
    s->setText(name_);
    QPushButton *but = new QPushButton();
    but->setFixedHeight(150);
    but->setFixedWidth(150);
    but->setCursor(Qt::PointingHandCursor);
    but->setIcon(image_);
    but->setIconSize(QSize(150,150));
    s->setFixedHeight(40);
    s->setFixedWidth(160);
    vbox->addWidget(but,1);
    vbox->addWidget(s,1);
    box_ = new QGroupBox;
    box_->setFixedHeight(200);
    box_->setFixedWidth(200);
    box_->setLayout(vbox);
    box_->setMouseTracking(true);

    return  box_;
}
void Title::set_layout(QVBoxLayout *layout)
{
    box_->setLayout(layout);
}
QGroupBox* Title::get_box()
{
    return box_;
}
DynamicButton* Title::get_button()
{
    return button_;
}
QString Title::get_name()
{
    QLabel *temp = new QLabel();
    temp->setFixedHeight(40);
    temp->setFixedWidth(160);
    temp->setText(name_);
    return temp->text();
}
void Title::set_name(QString send)
{
    name_ = send;
}
QString Title::get_genre()
{
    return genre_;
}
QString Title::get_descr()
{
    return descr_;
}
QIcon Title::get_icon()
{
    return button_->icon();
}
void Title::out_in_file(QFile *text,QFile *image)
{
    QTextStream stream(text);
    stream<<name_<<"\n";
    stream<<genre_<<"\n";
    stream<<descr_<<"\n";
}
void Title::set_but_ID(int ID)
{
    button_->setID(ID);
}
void Title::set_genre(QString gen)
{
    genre_ = gen;
}
void Title::set_descr(QString desc)
{
    descr_ = desc;
}
void Title::set_image(QPixmap image)
{
    image_ = image;
    button_->setIcon(image_);
    button_->setIconSize(QSize(150,150));
}
