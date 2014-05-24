#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "mainwindow_konk.h"
#include "mainwindow_kryj.h"
#include "ui_mainwindow.h"
#include "ui_mainwindow_kryj.h"
#include "ui_mainwindow_konk.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    MainWindow *zw;
    MainWindowKryj *kryj;
    MainWindowKonk *konk;


private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
