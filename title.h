#ifndef TITLE_H
#define TITLE_H
#include <QDialog>
#include <QString>
#include <QPixmap>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
class Title
{
public:
    Title(bool is_admin = false);
    ~Title() = default;
    void create();
    void delete_element();
    void show_one();
    QGroupBox* get_adding_box();
private:
    QPixmap image_;
    QString name_;
    QString genre_;
    QString descr_;
    bool is_admin_;
    // здесь файл данных и файл картинок

    void edit();

    QGroupBox *box_;
};

#endif // TITLE_H
