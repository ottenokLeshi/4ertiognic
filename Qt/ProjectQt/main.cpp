#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Core maincore;
    MainWindow maingui;
    maingui.ConnectCore(&maincore);
    maingui.show();

    return a.exec();
}
