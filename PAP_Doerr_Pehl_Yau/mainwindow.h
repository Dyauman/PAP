#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QWidget>
#include <QMouseEvent>
#include <drag_drop.h>
#include "Symbols.h"

int current_symb_numb = 0;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRect_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
