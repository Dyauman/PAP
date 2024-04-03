#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnRect, SIGNAL(clicked()), this, SLOT(on_btnRect_clicked()));

    //connect(ui->PAP_widget, &QWidget::mousePressEvent, [=](QMouseEvent *event));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnRect_clicked()
{
    ui->current_Sym_text->setText("Rectangle selected");
    Symbols test(Symbols::Symb::rectangle, true, current_symb_numb);
    //if(ui->PAP_widget->)
}

/*// Annahme: widget und label sind bereits im Designer erstellt und entsprechend benannt

connect(widget, &QWidget::mousePressEvent, [=](QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        label->setText("Mausklick erkannt");
    }
});*/
