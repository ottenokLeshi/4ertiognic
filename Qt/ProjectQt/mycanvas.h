#ifndef MYCANVAS_H
#define MYCANVAS_H

#include "QtWidgets/qgraphicsview.h"
#include <QMouseEvent>
#include "../include/core.h"
#include "../include/Primitives/primitive_type.h"
#include "mainwindow.h"
#include <QLineEdit>


class Core;



class MyCanvas : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyCanvas(QWidget *parent = 0);
    ~MyCanvas();



    void connectCoreCanvas(Core* core)
    {
        mycore = core;
    }



    void NewCanvas();
    void increaseScale();
    void decreaseScale();
    int getScaleSize();


QGraphicsScene* mainscene;




private:
    Core* mycore;
    int scaleSize;

};

#endif // MYCANVAS_H
