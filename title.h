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

private:
    QString name;
    QPixmap image;
    QString genre;
    QString descr;
};

#endif // TITLE_H
