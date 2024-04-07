#include "symbwidget.h"

//Pfad fuer die Bilder in der sie gespeichert sind
QDir directory ("C:/Users/Dicks/Desktop/PAP_Doerr_Pehl_Yau/Symbols_pic/");

//Dynamische Variablen fuer die Button Dimensionen
int btnWidth = 75;
int btnHeight = 30;

symbWidget::symbWidget(QWidget *parent)
    : QScrollArea{parent}
{
    //Widget Dimensionen Setup
    setMinimumSize(130,500);
    setMaximumSize(130,1000);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

    QVBoxLayout *btnLayout = new QVBoxLayout();
    btnLayout->setSpacing(20);

    //Rectangle Button Setup
    QLabel *btnRect = new QLabel(this);
    btnRect->setPixmap(QPixmap(directory.absoluteFilePath("rect.png")));
    btnRect->setScaledContents(true);
    btnRect->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnRect);

    //Diamond Button Setup
    QLabel *btnDiamond = new QLabel(this);
    btnDiamond->setPixmap(QPixmap(directory.absoluteFilePath("diamond.png")));
    btnDiamond->setScaledContents(true);
    btnDiamond->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnDiamond);

    //Begin Button Setup
    QLabel *btnBegin = new QLabel(this);
    btnBegin->setPixmap(QPixmap(directory.absoluteFilePath("begin.png")));
    btnBegin->setScaledContents(true);
    btnBegin->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnBegin);

    //End Button Setup
    QLabel *btnEnd = new QLabel(this);
    btnEnd->setPixmap(QPixmap(directory.absoluteFilePath("end.png")));
    btnEnd->setScaledContents(true);
    btnEnd->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnEnd);

    //Input Button Setup
    QLabel *btnInput = new QLabel(this);
    btnInput->setPixmap(QPixmap(directory.absoluteFilePath("input.png")));
    btnInput->setScaledContents(true);
    btnInput->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnInput);

    //Output Button Setup
    QLabel *btnOutput = new QLabel(this);
    btnOutput->setPixmap(QPixmap(directory.absoluteFilePath("output.png")));
    btnOutput->setScaledContents(true);
    btnOutput->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnOutput);

    //Start Button Setup
    QLabel *btnStart = new QLabel(this);
    btnStart->setPixmap(QPixmap(directory.absoluteFilePath("start.png")));
    btnStart->setScaledContents(true);
    btnStart->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnStart);

    //End Oval Button Setup
    QLabel *btnEndOval = new QLabel(this);
    btnEndOval->setPixmap(QPixmap(directory.absoluteFilePath("end_round.png")));
    btnEndOval->setScaledContents(true);
    btnEndOval->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnEndOval);

    //Arrow Up Button Setup
    QLabel *btnArrowUp = new QLabel(this);
    btnArrowUp->setPixmap(QPixmap(directory.absoluteFilePath("arrowUp.png")));
    btnArrowUp->setScaledContents(true);
    btnArrowUp->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowUp);

    //Arrow Down Button Setup
    QLabel *btnArrowDown = new QLabel(this);
    btnArrowDown->setPixmap(QPixmap(directory.absoluteFilePath("arrowDown.png")));
    btnArrowDown->setScaledContents(true);
    btnArrowDown->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowDown);

    //Arrow Left Button Setup
    QLabel *btnArrowLeft = new QLabel(this);
    btnArrowLeft->setPixmap(QPixmap(directory.absoluteFilePath("arrowLeft.png")));
    btnArrowLeft->setScaledContents(true);
    btnArrowLeft->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowLeft);

    //Arrow Right Button Setup
    QLabel *btnArrowRight = new QLabel(this);
    btnArrowRight->setPixmap(QPixmap(directory.absoluteFilePath("arrowRight.png")));
    btnArrowRight->setScaledContents(true);
    btnArrowRight->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowRight);

    //Arrow Left AngleButton Setup
    QLabel *btnArrowLeftAngle = new QLabel(this);
    btnArrowLeftAngle->setPixmap(QPixmap(directory.absoluteFilePath("arrowLeftAngle.png")));
    btnArrowLeftAngle->setScaledContents(true);
    btnArrowLeftAngle->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowLeftAngle);

    //Arrow Right Angle Button Setup
    QLabel *btnArrowRightAngle = new QLabel(this);
    btnArrowRightAngle->setPixmap(QPixmap(directory.absoluteFilePath("arrowRightAngle.png")));
    btnArrowRightAngle->setScaledContents(true);
    btnArrowRightAngle->setFixedSize(btnWidth,btnHeight);
    btnLayout->addWidget(btnArrowRightAngle);

    //Button Widget Setup
    QWidget *btnWidget = new QWidget();
    btnWidget->setLayout(btnLayout);
    btnWidget->setAttribute(Qt::WA_DeleteOnClose);
    setWidget(btnWidget);
}

//Drag und Drop Methoden (von Qt Dokumentation & an Applikation angepasst)

void symbWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void symbWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void symbWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap);
        newIcon->move(event->position().toPoint() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this)
        {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->acceptProposedAction();
        }
    }
    else
    {
        event->ignore();
    }
}

void symbWidget::mousePressEvent(QMouseEvent *event)
{
    // Konvertiere globale Koordinaten in lokale Koordinaten des symbWidget
    QPoint localPos = event->pos();

    // Finde das Kind-Widget an der Position
    QWidget *childWidget = childAt(localPos);

    // Ueberpruefe, ob das Kind-Widget ein QLabel ist
    QLabel *childLabel = qobject_cast<QLabel*>(childWidget);

    if (!childLabel)
    {
        return;
    }

    QPixmap pixmap = childLabel->pixmap();
    pixmap = pixmap.scaled(150,60);
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(localPos - childLabel->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(localPos - childLabel->pos());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
    {
        childLabel->close();
    }
    else
    {
        childLabel->show();
    }
}
