#include "predator_prey.h"

predator_prey::predator_prey(QWidget *parent) :
    QMainWindow(parent)
{

}

predator_prey::~predator_prey()
{
}

QSize predator_prey::sizeHint() const
{
    return QSize(2000,2000);
}
