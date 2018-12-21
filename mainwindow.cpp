#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    adm = new Admin_pass();
    connect(adm,&Admin_pass::true_signal,this,&MainWindow::next);
    adm->show();
    hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    win = new Form(false);
    connect(win,&Form::signal,this,&MainWindow::show);
    win->show();
    hide();
}
void MainWindow::next()
{
    adm->close();
    win = new Form(true);
    connect(win,&Form::signal,this,&MainWindow::show);
    win->show();
}
