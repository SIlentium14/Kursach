#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* _____It's work _____
    QPixmap pic(":/new/prefix1/no_image.png");
    QLabel *lab = new QLabel;
    lab->setPixmap(pic.scaled(400,400,Qt::KeepAspectRatio));
    lab->show(); */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    win = new Form(true);
    connect(win,&Form::signal,this,&MainWindow::show);
    win->show();
    hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    win = new Form(false);
    connect(win,&Form::signal,this,&MainWindow::show);
    win->show();
    hide();
}
