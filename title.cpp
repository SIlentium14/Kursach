#include "title.h"

Title::Title()
{
    name_ = "";
    genre_ = "";
    descr_ = "";
    image_.load("no_image.png");
    is_admin_ = false;
}
