#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменения
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //some comment

    return a.exec();
}
