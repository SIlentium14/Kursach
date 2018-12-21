#include "edit_master.h"
#include "ui_edit_master.h"

Edit_Master::Edit_Master(Title* worker,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Master)
{
    ui->setupUi(this);
    if((work_=worker) == NULL)
    {
        work_->set_data(" "," "," ");
    }
    clearing_master();
    ui->name->setText(worker->get_name());
    ui->genre->setText(worker->get_genre());
    ui->descr->setText(worker->get_descr());
    ui->image->setText("");
    ui->image->setFixedSize(QSize(200,200));
    ui->image->setIconSize(QSize(200,200));
    ui->image->setIcon(worker->get_icon());
}

Edit_Master::~Edit_Master()
{
    delete ui;
}

void Edit_Master::on_Ok_clicked()
{
    QFile data("data.txt"), data_picture("pictures");
    data.open(QIODevice::Append | QIODevice::Text);
    data_picture.open(QIODevice::Append);

    QTextStream writeStream(&data);
    QString temp = ui->descr->toPlainText();
    temp.replace('\n',' ');
    writeStream<<temp<<'\n';
    temp = ui->genre->toPlainText();
    temp.replace('\n',' ');
    writeStream<<temp<<'\n';
    temp = ui->name->text();
    temp.replace('\n',' ');
    writeStream<<temp<<'\n';
    QDataStream img_stream(&data_picture);
    img_stream<<work_->image_;
    data_picture.close();
    data.close();

    emit signal();

    emit cancel_signal();

    close();
}

void Edit_Master::on_Cancel_clicked()
{
    close();
    emit signal();
}
void Edit_Master::clearing_master()
{
    if(work_->get_name() == "")
        work_->set_name(" ");
    if(work_->get_genre() == "")
        work_->set_genre(" ");
    if(work_->get_descr() == "")
        work_->set_descr(" ");
}

void Edit_Master::on_image_clicked()
{
    QPixmap img_name = QFileDialog::getOpenFileName(
                this,
                tr("Выбрать картинку"),
                "C://",
                "Images (*.jpg *.png *.bmp)"
                );
    work_->set_image(img_name);
    ui->image->setIcon(work_->get_icon());
    ui->image->setIconSize(QSize(200,200));
}
