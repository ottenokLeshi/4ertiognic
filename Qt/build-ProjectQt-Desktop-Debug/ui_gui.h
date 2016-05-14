/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <mycanvas.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_14;
    QSplitter *splitter_21;
    QLabel *label;
    QListWidget *ObjListWidget;
    QLabel *label_2;
    QListWidget *RestrListWidget;
    QLabel *label_3;
    QListWidget *SelectListWidget;
    QPushButton *addSelectButton;
    QLabel *Leftmessage;
    QSplitter *splitter_12;
    QLabel *label_10;
    QSplitter *splitter_7;
    QCheckBox *CircleCheckBox;
    QCheckBox *PointCheckBox;
    QCheckBox *SegmentCheckBox;
    QSplitter *splitter_9;
    QLabel *label_4;
    QLineEdit *x1LineEdit;
    QLabel *label_6;
    QLineEdit *x2LineEdit;
    QSplitter *splitter_10;
    QLabel *label_5;
    QLineEdit *y1LineEdit;
    QLabel *label_7;
    QLineEdit *y2LineEdit;
    QSplitter *splitter_11;
    QLabel *label_8;
    QLineEdit *radLineEdit;
    QPushButton *deleteObjButton;
    QPushButton *changeButton;
    QPushButton *addOButton;
    QSplitter *splitter_6;
    QPushButton *addPointButton;
    QPushButton *addCircleButton;
    QPushButton *addSegmentButton;
    QPushButton *SelectButton;
    QPushButton *fixButton;
    QPushButton *zoomButton;
    QPushButton *decreaseButton;
    QSplitter *splitter;
    QLabel *label_9;
    QSplitter *splitter_16;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QCheckBox *P2PDISTCheckBox;
    QCheckBox *EQUALSCheckBox;
    QCheckBox *P2SDISTCheckBox;
    QCheckBox *ANGLECheckBox;
    QCheckBox *PARALCheckBox;
    QCheckBox *ORTHOCheckBox;
    QSplitter *splitter_4;
    QLabel *label_12;
    QLineEdit *id2LineEdit;
    QLabel *label_11;
    QLineEdit *id1LineEdit;
    QSplitter *splitter_5;
    QLabel *label_13;
    QLineEdit *restrLineEdit;
    QPushButton *addRestrPushButton;
    QPushButton *deleteRestrButton;
    QSplitter *splitter_2;
    QSplitter *splitter_3;
    QLabel *label_15;
    QLabel *label_16;
    MyCanvas *myCanvas;
    QLabel *message;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(842, 693);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 450, 0, 0));
        splitter_21 = new QSplitter(centralWidget);
        splitter_21->setObjectName(QStringLiteral("splitter_21"));
        splitter_21->setGeometry(QRect(30, 10, 241, 611));
        splitter_21->setOrientation(Qt::Vertical);
        label = new QLabel(splitter_21);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Verdana"));
        font.setPointSize(11);
        label->setFont(font);
        splitter_21->addWidget(label);
        ObjListWidget = new QListWidget(splitter_21);
        ObjListWidget->setObjectName(QStringLiteral("ObjListWidget"));
        splitter_21->addWidget(ObjListWidget);
        label_2 = new QLabel(splitter_21);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        splitter_21->addWidget(label_2);
        RestrListWidget = new QListWidget(splitter_21);
        RestrListWidget->setObjectName(QStringLiteral("RestrListWidget"));
        splitter_21->addWidget(RestrListWidget);
        label_3 = new QLabel(splitter_21);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        splitter_21->addWidget(label_3);
        SelectListWidget = new QListWidget(splitter_21);
        SelectListWidget->setObjectName(QStringLiteral("SelectListWidget"));
        splitter_21->addWidget(SelectListWidget);
        addSelectButton = new QPushButton(splitter_21);
        addSelectButton->setObjectName(QStringLiteral("addSelectButton"));
        addSelectButton->setFont(font);
        splitter_21->addWidget(addSelectButton);
        Leftmessage = new QLabel(splitter_21);
        Leftmessage->setObjectName(QStringLiteral("Leftmessage"));
        Leftmessage->setFont(font);
        splitter_21->addWidget(Leftmessage);
        splitter_12 = new QSplitter(centralWidget);
        splitter_12->setObjectName(QStringLiteral("splitter_12"));
        splitter_12->setGeometry(QRect(560, 450, 271, 171));
        splitter_12->setOrientation(Qt::Vertical);
        label_10 = new QLabel(splitter_12);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        splitter_12->addWidget(label_10);
        splitter_7 = new QSplitter(splitter_12);
        splitter_7->setObjectName(QStringLiteral("splitter_7"));
        splitter_7->setOrientation(Qt::Horizontal);
        CircleCheckBox = new QCheckBox(splitter_7);
        CircleCheckBox->setObjectName(QStringLiteral("CircleCheckBox"));
        QFont font1;
        font1.setPointSize(9);
        CircleCheckBox->setFont(font1);
        splitter_7->addWidget(CircleCheckBox);
        PointCheckBox = new QCheckBox(splitter_7);
        PointCheckBox->setObjectName(QStringLiteral("PointCheckBox"));
        PointCheckBox->setFont(font1);
        splitter_7->addWidget(PointCheckBox);
        SegmentCheckBox = new QCheckBox(splitter_7);
        SegmentCheckBox->setObjectName(QStringLiteral("SegmentCheckBox"));
        SegmentCheckBox->setFont(font1);
        splitter_7->addWidget(SegmentCheckBox);
        splitter_12->addWidget(splitter_7);
        splitter_9 = new QSplitter(splitter_12);
        splitter_9->setObjectName(QStringLiteral("splitter_9"));
        splitter_9->setOrientation(Qt::Horizontal);
        label_4 = new QLabel(splitter_9);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        splitter_9->addWidget(label_4);
        x1LineEdit = new QLineEdit(splitter_9);
        x1LineEdit->setObjectName(QStringLiteral("x1LineEdit"));
        splitter_9->addWidget(x1LineEdit);
        label_6 = new QLabel(splitter_9);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);
        splitter_9->addWidget(label_6);
        x2LineEdit = new QLineEdit(splitter_9);
        x2LineEdit->setObjectName(QStringLiteral("x2LineEdit"));
        splitter_9->addWidget(x2LineEdit);
        splitter_12->addWidget(splitter_9);
        splitter_10 = new QSplitter(splitter_12);
        splitter_10->setObjectName(QStringLiteral("splitter_10"));
        splitter_10->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(splitter_10);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        splitter_10->addWidget(label_5);
        y1LineEdit = new QLineEdit(splitter_10);
        y1LineEdit->setObjectName(QStringLiteral("y1LineEdit"));
        splitter_10->addWidget(y1LineEdit);
        label_7 = new QLabel(splitter_10);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        splitter_10->addWidget(label_7);
        y2LineEdit = new QLineEdit(splitter_10);
        y2LineEdit->setObjectName(QStringLiteral("y2LineEdit"));
        splitter_10->addWidget(y2LineEdit);
        splitter_12->addWidget(splitter_10);
        splitter_11 = new QSplitter(splitter_12);
        splitter_11->setObjectName(QStringLiteral("splitter_11"));
        splitter_11->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter_11);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        splitter_11->addWidget(label_8);
        radLineEdit = new QLineEdit(splitter_11);
        radLineEdit->setObjectName(QStringLiteral("radLineEdit"));
        splitter_11->addWidget(radLineEdit);
        deleteObjButton = new QPushButton(splitter_11);
        deleteObjButton->setObjectName(QStringLiteral("deleteObjButton"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/delete.png"), QSize(), QIcon::Normal, QIcon::On);
        deleteObjButton->setIcon(icon);
        deleteObjButton->setIconSize(QSize(25, 25));
        splitter_11->addWidget(deleteObjButton);
        changeButton = new QPushButton(splitter_11);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/addRestr.png"), QSize(), QIcon::Normal, QIcon::On);
        changeButton->setIcon(icon1);
        changeButton->setIconSize(QSize(25, 25));
        splitter_11->addWidget(changeButton);
        addOButton = new QPushButton(splitter_11);
        addOButton->setObjectName(QStringLiteral("addOButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/parametrs.png"), QSize(), QIcon::Normal, QIcon::On);
        addOButton->setIcon(icon2);
        addOButton->setIconSize(QSize(25, 25));
        splitter_11->addWidget(addOButton);
        splitter_12->addWidget(splitter_11);
        splitter_6 = new QSplitter(centralWidget);
        splitter_6->setObjectName(QStringLiteral("splitter_6"));
        splitter_6->setGeometry(QRect(490, 380, 341, 51));
        splitter_6->setOrientation(Qt::Horizontal);
        addPointButton = new QPushButton(splitter_6);
        addPointButton->setObjectName(QStringLiteral("addPointButton"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/P.png"), QSize(), QIcon::Normal, QIcon::On);
        addPointButton->setIcon(icon3);
        addPointButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(addPointButton);
        addCircleButton = new QPushButton(splitter_6);
        addCircleButton->setObjectName(QStringLiteral("addCircleButton"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/cir.png"), QSize(), QIcon::Normal, QIcon::On);
        addCircleButton->setIcon(icon4);
        addCircleButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(addCircleButton);
        addSegmentButton = new QPushButton(splitter_6);
        addSegmentButton->setObjectName(QStringLiteral("addSegmentButton"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/seg.png"), QSize(), QIcon::Normal, QIcon::On);
        addSegmentButton->setIcon(icon5);
        addSegmentButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(addSegmentButton);
        SelectButton = new QPushButton(splitter_6);
        SelectButton->setObjectName(QStringLiteral("SelectButton"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/select.png"), QSize(), QIcon::Normal, QIcon::On);
        SelectButton->setIcon(icon6);
        SelectButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(SelectButton);
        fixButton = new QPushButton(splitter_6);
        fixButton->setObjectName(QStringLiteral("fixButton"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/fix.png"), QSize(), QIcon::Normal, QIcon::On);
        fixButton->setIcon(icon7);
        fixButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(fixButton);
        zoomButton = new QPushButton(splitter_6);
        zoomButton->setObjectName(QStringLiteral("zoomButton"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/search.png"), QSize(), QIcon::Normal, QIcon::On);
        zoomButton->setIcon(icon8);
        zoomButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(zoomButton);
        decreaseButton = new QPushButton(splitter_6);
        decreaseButton->setObjectName(QStringLiteral("decreaseButton"));
        decreaseButton->setIcon(icon8);
        decreaseButton->setIconSize(QSize(25, 25));
        splitter_6->addWidget(decreaseButton);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(280, 400, 275, 221));
        splitter->setOrientation(Qt::Vertical);
        label_9 = new QLabel(splitter);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMaximumSize(QSize(227, 16777215));
        label_9->setFont(font);
        splitter->addWidget(label_9);
        splitter_16 = new QSplitter(splitter);
        splitter_16->setObjectName(QStringLiteral("splitter_16"));
        splitter_16->setOrientation(Qt::Horizontal);
        splitter->addWidget(splitter_16);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        P2PDISTCheckBox = new QCheckBox(layoutWidget);
        P2PDISTCheckBox->setObjectName(QStringLiteral("P2PDISTCheckBox"));
        QFont font2;
        font2.setFamily(QStringLiteral("Sans"));
        font2.setPointSize(9);
        P2PDISTCheckBox->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, P2PDISTCheckBox);

        EQUALSCheckBox = new QCheckBox(layoutWidget);
        EQUALSCheckBox->setObjectName(QStringLiteral("EQUALSCheckBox"));
        EQUALSCheckBox->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, EQUALSCheckBox);

        P2SDISTCheckBox = new QCheckBox(layoutWidget);
        P2SDISTCheckBox->setObjectName(QStringLiteral("P2SDISTCheckBox"));
        P2SDISTCheckBox->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, P2SDISTCheckBox);

        ANGLECheckBox = new QCheckBox(layoutWidget);
        ANGLECheckBox->setObjectName(QStringLiteral("ANGLECheckBox"));
        ANGLECheckBox->setFont(font1);

        formLayout->setWidget(1, QFormLayout::FieldRole, ANGLECheckBox);

        PARALCheckBox = new QCheckBox(layoutWidget);
        PARALCheckBox->setObjectName(QStringLiteral("PARALCheckBox"));
        PARALCheckBox->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, PARALCheckBox);

        ORTHOCheckBox = new QCheckBox(layoutWidget);
        ORTHOCheckBox->setObjectName(QStringLiteral("ORTHOCheckBox"));
        ORTHOCheckBox->setFont(font1);

        formLayout->setWidget(2, QFormLayout::FieldRole, ORTHOCheckBox);

        splitter->addWidget(layoutWidget);
        splitter_4 = new QSplitter(splitter);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(splitter_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        splitter_4->addWidget(label_12);
        id2LineEdit = new QLineEdit(splitter_4);
        id2LineEdit->setObjectName(QStringLiteral("id2LineEdit"));
        splitter_4->addWidget(id2LineEdit);
        label_11 = new QLabel(splitter_4);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);
        splitter_4->addWidget(label_11);
        id1LineEdit = new QLineEdit(splitter_4);
        id1LineEdit->setObjectName(QStringLiteral("id1LineEdit"));
        splitter_4->addWidget(id1LineEdit);
        splitter->addWidget(splitter_4);
        splitter_5 = new QSplitter(splitter);
        splitter_5->setObjectName(QStringLiteral("splitter_5"));
        splitter_5->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(splitter_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        splitter_5->addWidget(label_13);
        restrLineEdit = new QLineEdit(splitter_5);
        restrLineEdit->setObjectName(QStringLiteral("restrLineEdit"));
        splitter_5->addWidget(restrLineEdit);
        addRestrPushButton = new QPushButton(splitter_5);
        addRestrPushButton->setObjectName(QStringLiteral("addRestrPushButton"));
        addRestrPushButton->setIcon(icon2);
        addRestrPushButton->setIconSize(QSize(25, 25));
        splitter_5->addWidget(addRestrPushButton);
        deleteRestrButton = new QPushButton(splitter_5);
        deleteRestrButton->setObjectName(QStringLiteral("deleteRestrButton"));
        deleteRestrButton->setIcon(icon);
        deleteRestrButton->setIconSize(QSize(29, 25));
        splitter_5->addWidget(deleteRestrButton);
        splitter->addWidget(splitter_5);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setGeometry(QRect(720, 10, 111, 21));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(splitter_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        splitter_3->addWidget(label_15);
        label_16 = new QLabel(splitter_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        splitter_3->addWidget(label_16);
        splitter_2->addWidget(splitter_3);
        myCanvas = new MyCanvas(centralWidget);
        myCanvas->setObjectName(QStringLiteral("myCanvas"));
        myCanvas->setGeometry(QRect(280, 36, 551, 341));
        message = new QLabel(centralWidget);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(280, 10, 431, 17));
        QFont font3;
        font3.setFamily(QStringLiteral("Verdana"));
        font3.setPointSize(10);
        font3.setItalic(true);
        message->setFont(font3);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 842, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GUI", 0));
        label_14->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\272\321\202\321\213", 0));
        label_2->setText(QApplication::translate("MainWindow", "\320\236\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\321\217", 0));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265 \320\276\320\261\321\212\320\265\320\272\321\202\321\213", 0));
        addSelectButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214\n"
"\320\262\321\213\320\264\320\265\320\273\320\265\320\275\320\270\320\265", 0));
        Leftmessage->setText(QApplication::translate("MainWindow", "...", 0));
        label_10->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214/\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214  \320\276\320\261\321\212\320\265\320\272\321\202", 0));
        CircleCheckBox->setText(QApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", 0));
        PointCheckBox->setText(QApplication::translate("MainWindow", " \320\242\320\276\321\207\320\272\320\260", 0));
        SegmentCheckBox->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\200\320\265\320\267\320\276\320\272", 0));
        label_4->setText(QApplication::translate("MainWindow", "x1", 0));
        label_6->setText(QApplication::translate("MainWindow", "x2", 0));
        label_5->setText(QApplication::translate("MainWindow", "y1", 0));
        label_7->setText(QApplication::translate("MainWindow", "y2", 0));
        label_8->setText(QApplication::translate("MainWindow", "rad", 0));
        changeButton->setText(QString());
        addOButton->setText(QString());
        addPointButton->setText(QString());
        addCircleButton->setText(QString());
        addSegmentButton->setText(QString());
        SelectButton->setText(QString());
        fixButton->setText(QString());
        zoomButton->setText(QString());
        decreaseButton->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\320\263\321\200\320\260\320\275\320\270\321\207\320\265\320\275\320\270\320\265", 0));
        P2PDISTCheckBox->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265\n"
"\320\274\320\265\320\266\320\264\321\203 \321\202\320\276\321\207\320\272\320\260\320\274\320\270", 0));
        EQUALSCheckBox->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\262\320\265\320\275\321\201\321\202\320\262\320\276\n"
"\320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262", 0));
        P2SDISTCheckBox->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\274\320\265\320\266\320\264\321\203\n"
"\321\202\320\276\321\207\320\272\320\276\320\271 \320\270 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\274", 0));
        ANGLECheckBox->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273 \320\274\320\265\320\266\320\264\321\203\n"
"\320\276\321\202\321\200\320\265\320\267\320\272\320\260\320\274\320\270", 0));
        PARALCheckBox->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\273\320\273\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0));
        ORTHOCheckBox->setText(QApplication::translate("MainWindow", "\320\236\321\200\321\202\320\276\320\263\320\276\320\275\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", 0));
        label_12->setText(QApplication::translate("MainWindow", "ID\342\204\2261", 0));
        label_11->setText(QApplication::translate("MainWindow", "ID\342\204\2262", 0));
        label_13->setText(QApplication::translate("MainWindow", "restr", 0));
        addRestrPushButton->setText(QString());
        deleteRestrButton->setText(QString());
        label_15->setText(QApplication::translate("MainWindow", "x:", 0));
        label_16->setText(QApplication::translate("MainWindow", "y:", 0));
        message->setText(QApplication::translate("MainWindow", "...", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
