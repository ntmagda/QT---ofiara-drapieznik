#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    ofiary(40),//N 30
    drapiezniki(5),//P 5
    skut_drap(0.1),//a 0.1
    rozrod_of(0.8),//r 0.8
    przyrost_drap(0.3),//b 0.3
    smiert_drap(0.5),//m 0.5


    x(100),
    yo(100),
    yd(100)

{


    setWindowTitle("Zwykła Symulacja");
    ui->setupUi(this);
    ui->lDrap->setReadOnly(true);
    ui->lOfiary->setReadOnly(true);
    ui->lRozrod_of->setReadOnly(true);
    ui->lWsp_przyr_of->setReadOnly(true);
    ui->lSkut_drap->setReadOnly(true);
    ui->lSmier_drap->setReadOnly(true);
    ui->Ofiary->setValue(ofiary);
    ui->Drapiezniki->setValue(drapiezniki);
    ui->Skut_drap->setValue(skut_drap*100);
    ui->Rozrod_of->setValue(rozrod_of*100);
    ui->Wsp_przyr_drap->setValue(przyrost_drap*100);
    ui->Smiert_drap->setValue(smiert_drap*100);
    setDouble_of(ofiary);
    setDouble_drap(drapiezniki);
    setDouble_smiert(smiert_drap*100);
    setDouble_rozrod(rozrod_of*100);
    setDouble_wsp(przyrost_drap*100);
    setDouble_skut(skut_drap*100);
    rysuj_wykres(ui->customPlot);



    connect(ui->Ofiary,SIGNAL(valueChanged(int)),this,SLOT(setDouble_of(int)));
    connect(this,SIGNAL(of_zmienione()),this,SLOT(rysuj()));
    connect(ui->Drapiezniki,SIGNAL(valueChanged(int)),this,SLOT(setDouble_drap(int)));
    connect(this,SIGNAL(drap_zmienione()),this,SLOT(rysuj()));
    connect(ui->Smiert_drap,SIGNAL(valueChanged(int)),this,SLOT(setDouble_smiert(int)));
    connect(this,SIGNAL(smiert_zmieniona()),this,SLOT(rysuj()));
    connect(ui->Rozrod_of,SIGNAL(valueChanged(int)),this,SLOT(setDouble_rozrod(int)));
    connect(this,SIGNAL(rozrod_zmieniona()),this,SLOT(rysuj()));
    connect(ui->Wsp_przyr_drap,SIGNAL(valueChanged(int)),this,SLOT(setDouble_wsp(int)));
    connect(this,SIGNAL(wsp_zmieniony()),this,SLOT(rysuj()));
    connect(ui->Skut_drap,SIGNAL(valueChanged(int)),this,SLOT(setDouble_skut(int)));
    connect(this,SIGNAL(skut_zmieniona()),this,SLOT(rysuj()));
    connect(ui->reset,SIGNAL(clicked()),this,SLOT(ClearAll()));
    connect(ui->zamknij,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::ClearAll()
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
}

void MainWindow::rysuj()
{
    rysuj_wykres(ui->customPlot);
}

void MainWindow::setDouble_of(int wartosc)
{
    ui->Ofiary->setRange(0,100);
    double wartosc1 = wartosc;
    QString wartosc1String = QString::number(wartosc1, 'f', 0);
    ui->lOfiary->setText(wartosc1String);
    ofiary= wartosc1;
    ui->customPlot->clearGraphs();

    emit of_zmienione();


}


void MainWindow::setDouble_drap(int wartosc)
{
    ui->Drapiezniki->setRange(0,100);
    double wartosc1 = wartosc;
    QString wartosc1String = QString::number(wartosc1, 'f', 0);
    ui->lDrap->setText(wartosc1String);

    drapiezniki=wartosc1;
    ui->customPlot->clearGraphs();
    emit drap_zmienione();
}


void MainWindow::setDouble_skut(int wartosc)
{
    ui->Skut_drap->setRange(0,100);
    double wartosc1 = wartosc*0.01;
    QString wartosc1String = QString::number(wartosc1, 'f', 2);
    ui->lSkut_drap->setText(wartosc1String);

    skut_drap=wartosc1;
    ui->customPlot->clearGraphs();

    emit skut_zmieniona();
}


void MainWindow::setDouble_rozrod(int wartosc)
{
    ui->Rozrod_of->setRange(0,100);
    double wartosc1 = wartosc*0.01;
    QString wartosc1String = QString::number(wartosc1, 'f', 2);
    ui->lRozrod_of->setText(wartosc1String);

    rozrod_of=wartosc1;
    ui->customPlot->clearGraphs();

    emit rozrod_zmieniona();

}

void MainWindow::setDouble_smiert(int wartosc)
{
     ui->Smiert_drap->setRange(0,100);
    double wartosc1 = wartosc*0.01;
    QString wartosc1String = QString::number(wartosc1, 'f', 2);
    ui->lSmier_drap->setText(wartosc1String);

    smiert_drap=wartosc1;
    ui->customPlot->clearGraphs();

    emit smiert_zmieniona();
}

void MainWindow::setDouble_wsp(int wartosc)
{
     ui->Wsp_przyr_drap->setRange(0,100);
    double wartosc1 = wartosc*0.01;
    QString wartosc1String = QString::number(wartosc1, 'f', 2);
    ui->lWsp_przyr_of->setText(wartosc1String);

    przyrost_drap=wartosc1;
    ui->customPlot->clearGraphs();

    emit wsp_zmieniony();


}

void MainWindow::rysuj_wykres(QCustomPlot *wykres)
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
