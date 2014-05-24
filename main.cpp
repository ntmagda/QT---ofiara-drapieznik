#include <QApplication>
#include "dialog.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog okno;
    okno.show();

    return a.exec();
}
