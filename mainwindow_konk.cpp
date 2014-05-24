#include "mainwindow_konk.h"
#include "ui_mainwindow_konk.h"

MainWindowKonk::MainWindowKonk(QWidget *parent) :
    MainWindow(parent),
    ui(new Ui::MainWindowKonk),
    konkurencja(1.3)

{

    setWindowTitle("Symulacja z Konkurencja");
    ui->setupUi(this);
    ui->lKonkurencja->setReadOnly(true);
    ui->Konkurencja->setValue(konkurencja*100);
    setDouble_konk(konkurencja*100);
    rysuj_wykres(ui->customPlot);



    connect(this,SIGNAL(of_zmienione()),this,SLOT(rysuj()));
    connect(this,SIGNAL(drap_zmienione()),this,SLOT(rysuj()));
    connect(this,SIGNAL(smiert_zmieniona()),this,SLOT(rysuj()));
    connect(this,SIGNAL(rozrod_zmieniona()),this,SLOT(rysuj()));
    connect(this,SIGNAL(wsp_zmieniony()),this,SLOT(rysuj()));
    connect(this,SIGNAL(skut_zmieniona()),this,SLOT(rysuj()));
    connect(ui->Konkurencja,SIGNAL(valueChanged(int)),this,SLOT(setDouble_konk(int)));
    connect(this,SIGNAL(konk_zmieniona()),this,SLOT(rysuj()));
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(ClearAll()));

}

MainWindowKonk::~MainWindowKonk()
{
    delete ui;
}



void MainWindowKonk::ClearAll()
{
 ui->lOfiary->clear();
 ui->lDrap->clear();
 ui->lRozrod_of->clear();
 ui->lSkut_drap->clear();
 ui->lSmier_drap->clear();
 ui->lWsp_przyr_of->clear();
 ui->Ofiary->setValue(0);
 ui->Drapiezniki->setValue(0);
 ui->Rozrod_of->setValue(0);
 ui->Skut_drap->setValue(0);
 ui->Wsp_przyr_drap->setValue(0);
 ui->Smiert_drap->setValue(0);
 ui->Konkurencja->setValue(0);
}

void MainWindowKonk::rysuj()
{
    rysuj_wykres(ui->customPlot);
}


void MainWindowKonk::setDouble_konk(int wartosc)
{
    ui->Konkurencja->setRange(0,300);
    double wartosc1 = wartosc*0.01;
    QString wartosc1String = QString::number(wartosc1, 'f', 2);
    ui->lKonkurencja->setText(wartosc1String);
    konkurencja= wartosc1;
    ui->customPlot->clearGraphs();

    emit konk_zmieniona();


}

void MainWindowKonk::rysuj_wykres(QCustomPlot *wykres)
  {


  wykres->legend->setVisible(true);
  int drapieznikitymcz = drapiezniki;
  int ofiarytymcz = ofiary;
  for (int i=0; i<100; i++)
  {

    double stareDrapiezniki=drapieznikitymcz;
    double stareOfiary = ofiarytymcz;
    x[i] = i;
    yo[i] = qRound(qExp(rozrod_of-skut_drap*stareDrapiezniki)*stareOfiary);
    ofiarytymcz = yo[i];
    yd[i]=qRound(qExp(przyrost_drap*skut_drap*stareOfiary - smiert_drap)*stareDrapiezniki);
    drapieznikitymcz = yd[i];


  }
  wykres->addGraph();
  wykres->graph(0)->setData(x, yo);
  wykres->addGraph();
  wykres->graph(1)->setPen(QPen(Qt::red));
  wykres->graph(1)->setData(x, yd);
  wykres->graph(0)->setName("Ofiary");
  wykres->graph(1)->setName("Drapieznicy");
  wykres->xAxis->setLabel("x");
  wykres->yAxis->setLabel("y");
  wykres->xAxis->setRange(0, 50);
  wykres->yAxis->setRange(0, 250);
  wykres->replot();
  }
