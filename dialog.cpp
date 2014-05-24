#include "dialog.h"
#include "ui_dialog.h"
#include <QPixmap>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    zw = new MainWindow;
    kryj = new MainWindowKryj;
    konk = new MainWindowKonk;
    connect(ui->zwykla,SIGNAL(clicked()),zw, SLOT(show()));
    connect(ui->konkurencja,SIGNAL(clicked()),konk, SLOT(show()));
    connect(ui->kryjowki, SIGNAL(clicked()),kryj,SLOT(show()));
    setWindowTitle("Wybierz opcje");

}


Dialog::~Dialog()
{
    delete ui;
}
