#ifndef MAINWINDOWKONK_H
#define MAINWINDOWKONK_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QPen>
#include <qmath.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
namespace Ui {
class MainWindowKonk;
}

class MainWindowKonk : public MainWindow
{
    Q_OBJECT

public:
    Ui::MainWindowKonk *ui;
    double konkurencja;
    explicit MainWindowKonk(QWidget *parent = 0);
    ~MainWindowKonk();
    void rysuj_wykres(QCustomPlot* wykres);

public slots:
    void setDouble_konk(int wartosc);
    void rysuj();
    void ClearAll();

signals:

    void konk_zmieniona();

};

#endif // MAINWINDOWKONK_H
