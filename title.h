#ifndef TITLE_H
#define TITLE_H
#include <QDialog>
#include <QString>
#include <QPixmap>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "dynamicbutton.h"
#include <QFile>
#include <QTextStream>
class Title
{
public:
    Title(bool is_admin = false);
    ~Title() = default;
    void set_data(QString,QString,QString);
    void create();
    void delete_element();
    void show_one();
    void set_name(QString);
    QGroupBox* get_adding_box();
    void set_layout(QVBoxLayout*);
    QGroupBox *get_box();
    DynamicButton* get_button();
    QString get_name() ;
    QString get_genre() ;
    QString get_descr() ;
    QIcon get_icon();
    bool roots();
    void out_in_file(QFile*,QFile*);
    void set_but_ID(int ID);
    void set_genre(QString);
    void set_descr(QString);
    void set_image(QPixmap);
    QPixmap image_;
signals:

private:
    DynamicButton *button_;

    QString name_;
    QString genre_;
    QString descr_;
    bool is_admin_;
    // здесь файл данных и файл картинок

    void edit();

    QGroupBox *box_;
};

#endif // TITLE_H
