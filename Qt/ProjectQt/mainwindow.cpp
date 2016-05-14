#include "mainwindow.h"
#include "QtWidgets/qgraphicssceneevent.h"
#include "mycanvas.h"
#include "QtWidgets/qmessagebox.h"
#include <QString>
#include "ui_gui.h"
#include "QtWidgets/qfiledialog.h"
#include "QtWidgets/qlistview.h"
#include "qlist.h"
#include <QList>
#include "QtWidgets/qscrollbar.h"
#include "QtWidgets/qmainwindow.h"
#include "qresource.h"
#include "errorheadler.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include "color.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mycore = 0;
    workstatus = SELECT;
    ui->myCanvas->connectCoreCanvas(mycore);

}



void MainWindow::ConnectCore(Core* core)
{
    mycore = core;
    ui->myCanvas->connectCoreCanvas(core);
}

bool MainWindow::getRestrType()
{
    RestrictType type;
    int flag = 0;
    if (ui->EQUALSCheckBox->isChecked())
    {
        type = RT_S2SEQUALS; flag++;
    }
    if (ui->P2PDISTCheckBox->isChecked())
    {
        type = RT_P2PDIST; flag++;
    }
    if (ui->PARALCheckBox->isChecked())
    {
        type = RT_S2SPARAL; flag++;
    }
    if (ui->P2SDISTCheckBox->isChecked())
    {
        type =  RT_P2SDIST; flag++;
    }
    if (ui->ORTHOCheckBox->isChecked())
    {
        type =  RT_S2SORTHO; flag++;
    }
    if (ui->P2SDISTCheckBox->isChecked())
    {
        type = RT_P2SDIST; flag++;
    }

if (flag == 1)
{
    _currentRestr = type;
    return 1;
}
else
{
    ui->message->setText(_error.errorMessage(CHOICE_RESTR));
    return 0;
}
}


bool MainWindow::getObjType()
{
    Primitive_Type type; int flag =0;
    if (ui->PointCheckBox->isChecked())
    {
        type = IsPoint; flag ++;
    }
    if (ui->SegmentCheckBox->isChecked())
    {
        type = IsSegment; flag ++;
    }
    if (ui->CircleCheckBox->isChecked())
    {
        type = IsCircle; flag ++;
    }
    if (flag == 1)
    {
        _currentObj = type;
        return 1;
    }
    else
    {
        ui->message->setText(_error.errorMessage(CHOICE_OBJ));
        return 0;
    }
}


bool MainWindow::addObj()
{
    bool ok = false;
    double x1=1,x2=1,y1=3,y2=5,rad=1;
    ui->x1LineEdit->text().toDouble(&ok);
    if (ok)
        x1 = ui->x1LineEdit->text().toDouble();
        else ui->message->setText(_error.errorMessage(FATAL_ADD_OBJ));

    ui->x2LineEdit->text().toDouble(&ok);
    if (ok)
        x2 = ui->x2LineEdit->text().toDouble();
    else   ui->message->setText(_error.errorMessage(FATAL_ADD_OBJ));

    ui->y1LineEdit->text().toDouble(&ok);
    if (ok)
        y1 = ui->y1LineEdit->text().toDouble();
    ui->y2LineEdit->text().toDouble(&ok);
    if (ok)
        y2 = ui->y2LineEdit->text().toDouble();
    ui->radLineEdit->text().toDouble(&ok);
    if (_currentObj == IsCircle)
      {
        if (ok)
            rad = ui->radLineEdit->text().toDouble();
    else
    {
        ui->message->setText(_error.errorMessage(UNCORRECT_OBJ));
        return 0;
    }}


    Array<double> param;
    param.push_back(x1);
    param.push_back(y1);
    switch(_currentObj)
    {
    case IsPoint:
        mycore->addObject(param,IsPoint);
        drawPoint(x1,y1);
        break;

    case IsSegment:
        param.push_back(x2); param.push_back(y2);
        mycore->addObject(param,IsSegment);
        drawSegment(x1,y1,x2,y2);
        break;
    case IsCircle:
        param.push_back(rad);
        mycore->addObject(param,IsCircle);
        drawCircle(x1,y1,rad);
        break;
    }
    ui->Leftmessage->setText(_error.errorMessage(ADD_OBJ));

    return 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::addRestr()
{
    bool ok = false,ok1 =false, ok2 = false;
    int id1,id2;
    ui->id1LineEdit->text().toInt(&ok);
    ui->id2LineEdit->text().toInt(&ok1);
    ui->restrLineEdit->text().toDouble(&ok2);

    if (!(ok1 && ok ))
    {
        ui->message->setText(_error.errorMessage(UNCORRECT_RESTR));
        return 0;
    }

    if (ui->restrLineEdit->text() == "" && (_currentRestr == RT_P2PDIST || _currentRestr == RT_P2SDIST
            || _currentRestr == RT_S2SANGLE))
    {
        ui->message->setText(_error.errorMessage(UNCORRECT_RESTR));
        return 0;
    }
double par = ui->restrLineEdit->text().toDouble(&ok);
    List<unsigned>* id = new List<unsigned>;
    id->push_back(ui->id1LineEdit->text().toInt(&ok));
    id->push_back(ui->id2LineEdit->text().toInt(&ok));
    if (mycore->addRestriction(id, &par,_currentRestr))
    {
            ui->message->setText(_error.errorMessage(ADD_RESTR));
            delete id;
            return true;
}
    else
    {
            ui->message->setText(_error.errorMessage(FATAL_ADD_RESTR));
            delete id;
            return false;
}
}

void MainWindow::addObjList(int id, Primitive_Type typeObj)
{
    QString idS = QString::number(id);
    QString type;
    switch(typeObj)
    {
    case IsPoint: type = "ТОЧКА"; break;
    case IsSegment: type = "ОТРЕЗОК"; break;
    case IsCircle: type = "ОКРУЖНОСТЬ"; break;
    }

    QListWidgetItem* item = new QListWidgetItem;
    item->setText("id№" + idS + " " + type);
    ui->ObjListWidget->addItem(item);

}

void MainWindow::addRestrList(int id, RestrictType typeRestr)
{
    QString idS = QString::number(id);
    QString type;
    switch(typeRestr)
    {
    case RT_P2PDIST: type = "Расстояние от точки до точки"; break;
    case RT_P2SDIST: type = "Расстояние от точки до отрезка"; break;
    case RT_S2SANGLE: type = "Угол между отрезками"; break;
    case RT_S2SEQUALS: type = "Равенство отрезков"; break;
    case RT_S2SPARAL: type = "Параллельность отрезков"; break;
    case RT_S2SORTHO: type = "Ортогональность отрезков"; break;
    }

    QListWidgetItem* item = new QListWidgetItem;
    item->setText("id№" + idS + " " + type);
    ui->RestrListWidget->addItem(item);
    delete item;
}


void MainWindow::on_addOButton_clicked()
{
    if (getObjType())
         if (addObj())
            addObjList(mycore->objects.lastElem()->showId(),_currentObj);

}

void MainWindow::on_addRestrPushButton_clicked()
{
    if (getRestrType())
          {
        if (addRestr())
            addRestrList(mycore->restrictions.lastElem()->showId(),_currentRestr);
        refresh();
    }
}


void MainWindow::drawPoint(double x,double y)
{
    QPen p; p.setColor(Qt::blue);
    QBrush b; b.setColor(Qt::blue);
    p.setWidthF(2/ui->myCanvas->getScaleSize());
    ui->myCanvas->mainscene->addEllipse(x-0.5,-y-0.5,1,1,p,b);
}

void MainWindow::drawSegment(double x1, double y1, double x2, double y2)
{
    QPen p; p.setColor(Qt::blue);
    QBrush b; b.setColor(Qt::blue);
    p.setWidthF(2/ui->myCanvas->getScaleSize());
   ui->myCanvas->mainscene->addLine(x1,-y1,x2,-y2,p);
}

void MainWindow::drawCircle(double x1, double y1, double rad)
{
    QPen p; p.setColor(Qt::blue);
    QBrush b; b.setColor(Qt::blue);
    p.setWidthF(2/ui->myCanvas->getScaleSize());
  ui->myCanvas->mainscene->addEllipse(x1-rad,-y1-rad,2*rad,2*rad,p,b);
}

void MainWindow::on_zoomButton_clicked()
{
    ui->myCanvas->increaseScale();
}

void MainWindow::on_decreaseButton_clicked()
{
    ui->myCanvas->decreaseScale();
}

void MainWindow::refresh()
{
    ui->myCanvas->mainscene->clear();
    ui->ObjListWidget->clear();
    ui->myCanvas->NewCanvas();
    List<GraphPrimitive*>::Marker mar(mycore->objects);
    Point *newp; Segment *news; Circle *newc;
    for (int i =0; i < mycore->objects.sizeList();i++)
    {
        switch(mar.get_current()->object_type())
        {
        case IsPoint:
            newp = dynamic_cast<Point*> (mar.get_current());
            drawPoint(newp->getX(),newp->getY());
            break;
        case IsSegment:
            news = dynamic_cast<Segment*> (mar.get_current());
            drawSegment(news->getP1()->getX(),news->getP1()->getY(),news->getP2()->getX(),news->getP2()->getY());
            break;
        case IsCircle:
            newc = dynamic_cast<Circle*>(mar.get_current());
            drawCircle(newc->getCenter().getX(),newc->getCenter().getY(),newc->getRadius());
            break;
        }
        addObjList(mar.get_current()->showId(),mar.get_current()->object_type());
        mar.move_next();
        delete newp,news,newc;
    }
}



void MainWindow::on_addPointButton_clicked()
{
    /*workstatus = ADD_POINT;
    QMouseEvent pe;
    ui->myCanvas->mouseMoveEvent(&pe);
    QPoint pos;
    pos = pe->pos();
    curX = pos.x();curY = pos.y();
    Array<double>* par = new Array<double>;

    par->push_back(curX);
    par->push_back(curY);
    mycore->addObject(*par,IsPoint);
    addObjList(mycore->objects.lastElem()->showId(),IsPoint);*/

}

void MainWindow::on_addCircleButton_clicked()
{
    workstatus = ADD_CIRCLE;
}

void MainWindow::on_addSegmentButton_clicked()
{
    workstatus = ADD_SEGMENT;
}

void MainWindow::on_SelectButton_clicked()
{
    workstatus = SELECT;
}

void MainWindow::deleteObj()
{  // QModelIndex index;
   // QWidgetItem item;
   // ui->ObjListWidget->isItemSelected(&item);
    int objList =1;
    int id = getID(ui->ObjListWidget->item(objList)->text());
   GraphPrimitive *p =  mycore->searchID(id);
   delete p;
   ui->ObjListWidget->takeItem(objList);
   refresh();
}

void MainWindow::deleteRestr()
{
    QModelIndex index;
    ui->RestrListWidget->clicked(index);
    int restrList = index.row();
    int id = getID(ui->ObjListWidget->item(restrList)->text());
   BasicRestriction *p =  mycore->searchIDRestr(id);
   delete p;
   ui->RestrListWidget->takeItem(restrList);
   refresh();
}

int MainWindow::getID(QString str)
{   int k = 3;bool ok;
    for (int i = 0; i < str.size();i++)
    {
        if (str.at(i) == ' ') k=i;
    }
    QString id;
for (int i = 3; i< k;i++)
    id = id + str.at(i);
return id.toInt(&ok);
}





void MainWindow::on_deleteRestrButton_clicked()
{
    deleteRestr();
}

void MainWindow::on_deleteObjButton_clicked()
{
    deleteObj();
}
