#include "wykres.h"

Wykres::Wykres(QWidget *parent) :
    QWidget(parent),
    ofiary(30),
    drapiezniki(5),
    skut_drap(0.1),
    rozrod_of(0.3),
    przyrost_drap(0.5),
    smiert_drap(0.8)

  void Wykres::rysuj_wykres(QCustomPlot *wykres)
  {


  wykres->legend->setVisible(true);
  QVector<double> x(101), y(101);
  for (int i=0; i<101; ++i)
  {
    x[i] = i/50.0 - 1; // x goes from -1 to 1
    y[i] = x[i]*x[i]; // let's plot a quadratic function
  }
  // create graph and assign data to it:
  wykres->addGraph();
  wykres->graph(0)->setData(x, y);
  // give the axes some labels:
  wykres->xAxis->setLabel("x");
  wykres->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  wykres->xAxis->setRange(-1, 1);
  wykres->yAxis->setRange(0, 1);
  wykres->replot();
  }
{




}

