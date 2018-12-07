#ifndef ONE_ELEMENT_H
#define ONE_ELEMENT_H

#include <QDialog>

namespace Ui {
class One_element;
}

class One_element : public QDialog
{
    Q_OBJECT

public:
    explicit One_element(QWidget *parent = nullptr);
    ~One_element();

private:
    Ui::One_element *ui;
};

#endif // ONE_ELEMENT_H
