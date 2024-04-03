#include "mainwindow.h"
#include "drag_drop.h"
#include "Symbols.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
