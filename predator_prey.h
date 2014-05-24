#ifndef PREDATOR_PREY_H
#define PREDATOR_PREY_H

#include <QMainWindow>
#include <QSize>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "qcustomplot.h"

class predator_prey : public QMainWindow
{
    Q_OBJECT

public:
    predator_prey(QWidget *parent = 0);
    ~predator_prey();
    QSize sizeHint() const;


};

#endif // PREDATOR_PREY_H
