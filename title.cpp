#include "title.h"

Title::Title(bool is_admin) : is_admin_(is_admin)
{
    name_ = "";
    genre_ = "";
    descr_ = "";
    image_.load("no_image.png");
}

void Title::create()
{


}

void Title::delete_element()
{


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
    but->setFixedHeight(140);
    but->setFixedWidth(160);
    QPixmap folderbut("qrc:/new/prefix1/no_image.png");
    but->setIcon(folderbut);
    s->setFixedHeight(40);
    s->setFixedWidth(160);
    vbox->addWidget(but,1);
    vbox->addWidget(s,1);
    box_ = new QGroupBox;
    box_->setFixedHeight(200);
    box_->setFixedWidth(200);
    box_->setLayout(vbox);
    // stand_box->setTitle("Title");
    box_->setMouseTracking(true);


    return  box_;
}
