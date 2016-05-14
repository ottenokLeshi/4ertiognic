#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../include/core.h"
#include "QtWidgets/qmainwindow.h"
#include "QtWidgets/qgraphicsscene.h"
#include "mycanvas.h"
#include "QtWidgets/qbuttongroup.h"
#include "QtWidgets/qaction.h"
#include "qregexp.h"
#include "qvalidator.h"
#include "qresource.h"
#include <QCheckBox>
#include <QMainWindow>
#include "../include/Restrictions/restrict_types.h"
#include "../include/Primitives/primitive_type.h"
#include "errorheadler.h"
#include "color.h"
#include "typestatus.h"
#include <QModelIndex>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

void ConnectCore(Core* core);

bool getRestrType();

bool getObjType();

bool addObj();

bool addRestr();

void drawPoint(double x,double y);
void drawSegment(double x1, double y1, double x2, double y2);
void drawCircle(double x1, double y1, double rad);
void refresh();
void addObjList(int id, Primitive_Type typeObj);
void addRestrList(int id, RestrictType typeRestr);
void deleteObj();
void deleteRestr();
int getID(QString str);
private slots:
void on_addOButton_clicked();

void on_addRestrPushButton_clicked();

void on_zoomButton_clicked();

void on_decreaseButton_clicked();

void on_addPointButton_clicked();

void on_addCircleButton_clicked();

void on_addSegmentButton_clicked();

void on_SelectButton_clicked();





void on_deleteRestrButton_clicked();

void on_deleteObjButton_clicked();

private:
    Ui::MainWindow *ui;
    QCheckBox _choice;
    Primitive_Type _currentObj; // текущий выбранный тип объекта
    RestrictType _currentRestr; // текущий тип ограничения
    Core *mycore;
    ErrorHeadler _error;
    bool _typeSolver;
    unsigned selectObjID;
    unsigned selectRestrID;
    TypeStatus workstatus;
    };

#endif //
