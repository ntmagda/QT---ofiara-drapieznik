#ifndef MAINWINDOWKRYJ_H
#define MAINWINDOWKRYJ_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QPen>
#include <qmath.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindowKryj;
}

class MainWindowKryj : public MainWindow
{
    Q_OBJECT

public:
    Ui::MainWindowKryj *ui;
    int kryjowki;
    explicit MainWindowKryj(QWidget *parent = 0);
    ~MainWindowKryj();
    void rysuj_wykres(QCustomPlot* wykres);

public slots:
    void setInt_kryj(int wartosc);
    void rysuj();
    void ClearAll();

signals:
    void kryj_zmienione();

};

#endif // MAINWINDOWKRYJ_H
