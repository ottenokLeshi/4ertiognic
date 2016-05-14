#include "mycanvas.h"
#include "mainwindow.h"
#include "ui_gui.h"
#include <QPointF>



MyCanvas::MyCanvas(QWidget *parent) : QGraphicsView(parent)
{
    mainscene = new QGraphicsScene();
    setScene(mainscene);
    scale(2, 2);
    setSceneRect(-5000, -5000, 10000, 10000);
    scaleSize = 2;
    NewCanvas();
}

MyCanvas::~MyCanvas()
{
    delete mainscene;
}

void MyCanvas::increaseScale()
{
    scaleSize += 1;
    scale(scaleSize,scaleSize);
}

void MyCanvas::decreaseScale()
{
    scaleSize = scaleSize - 1;
    scale(scaleSize,scaleSize);
}

void MyCanvas::NewCanvas()
{
    QPen pen(Qt::DotLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    const double r = 0.7;
    pen.setWidthF(r - 0.3);
    for (int x = -5000; x <= 5000; x += 100)
    {
        mainscene->addLine(x, -5000, x, 5000, pen);
        mainscene->addLine(-5000, x, 5000, x, pen);
    }

    QPen pen1;
    pen1.setWidthF(r + 0.4);
    QBrush brush(Qt::SolidPattern);
    for (int x = -5000; x <= 5000; x += 25)
    {
        mainscene->addEllipse(x - r / 2, -r / 2, r, r, pen1, brush);
        mainscene->addEllipse(-r / 2, x - r / 2, r, r, pen1, brush);
    }
}

int MyCanvas::getScaleSize()
{
    return scaleSize;
}








