#include "dynamicbutton.h"

DynamicButton::DynamicButton(int box_id,QWidget *parent) :
    QPushButton (parent)
{
    ButID = box_id;
}
DynamicButton::~DynamicButton()
{

}
int DynamicButton::getID()
{
    return ButID;
}
void DynamicButton::setID(int ID)
{
    ButID = ID;
}
