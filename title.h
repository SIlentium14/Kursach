#ifndef TITLE_H
#define TITLE_H
#include <QString>
#include <QPixmap>

class Title
{
public:
    Title();
    Title(QString,QString,QString,QPixmap);
    ~Title() = default;
    void create();
    void delete_element();
    void show_all();
    void show_one();
private:
    QPixmap image_;
    QString name_;
    QString genre_;
    QString descr_;
    bool is_admin_;

    void edit();
};

#endif // TITLE_H
