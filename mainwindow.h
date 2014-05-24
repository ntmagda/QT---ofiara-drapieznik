#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QPen>
#include <qmath.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    double ofiary;
    double drapiezniki;
    double skut_drap;
    double rozrod_of;
    double przyrost_drap;
    double smiert_drap;
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
    virtual void rysuj_wykres(QCustomPlot* wykres);
     QVector<double> x,yo,yd;

public slots:
    void setDouble_of(int wartosc);
    void setDouble_drap(int wartosc);
    void setDouble_skut(int wartosc);
    void setDouble_rozrod(int wartosc);
    void setDouble_smiert(int wartosc);
    void setDouble_wsp(int wartosc);
    virtual void rysuj();
    virtual void ClearAll();

signals:

    void of_zmienione();
    void drap_zmienione();
    void skut_zmieniona();
    void rozrod_zmieniona();
    void smiert_zmieniona();
    void wsp_zmieniony();

};

#endif // MAINWINDOW_H
