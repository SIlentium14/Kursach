#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QPushButton>

class DynamicButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DynamicButton(int,QWidget *parent = 0);
    ~DynamicButton();
    int getID();
    void setID(int ID);
public slots:

private:
    int ButID = 0;

};

#endif // DYNAMICBUTTON_H
