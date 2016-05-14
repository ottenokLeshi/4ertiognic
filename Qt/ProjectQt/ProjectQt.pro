#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T17:29:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjectQt
TEMPLATE = app


SOURCES += main.cpp\
    mycanvas.cpp \
    ../src/Core/core_add.cpp \
    ../src/Core/core_other.cpp \
    ../src/Core/core_select.cpp \
    mainwindow.cpp \
    ../src/graphPrimitive.cpp \
    ../src/BasicRestriction.cpp \
    ../src/Algorythms/FunctionSrc.cpp \
    ../src/Algorythms/HJSolver.cpp \
    color.cpp

HEADERS  += \
    ../include/Primitives/graphPrimitive.h \
    ../include/Primitives/objects.h \
    ../include/Primitives/primitive_type.h \
    ../include/Containers/List.h \
    ../include/Containers/MArray.h \
    mycanvas.h \
    ../include/Restrictions/BasicRestriction.h \
    ../include/Restrictions/ResrtS2SORTHO.h \
    ../include/Restrictions/restrict_types.h \
    ../include/Restrictions/RestrP2PDIST.h \
    ../include/Restrictions/RestrP2SDIST.h \
    ../include/Restrictions/RestrP2SDISTEX.h \
    ../include/Restrictions/RestrS2SANGLE.h \
    ../include/Restrictions/RestrS2SEQUALS.h \
    ../include/Restrictions/RestrS2SPARAL.h \
    ../include/Output/GUI.h \
    ../include/Output/GUI_types.h \
    mainwindow.h \
    ../include/core.h \
    errorheadler.h \
    ../include/Algorythms/HJSolver.h \
    ../include/Algorythms/Function.h \
    ../include/Algorythms/ISolver.h \
    color.h \
    typestatus.h

FORMS    += gui.ui

DISTFILES += \
    icons/addO.png \
    icons/addOb.png \
    icons/addRestr.png \
    icons/cir.png \
    icons/circle.png \
    icons/cursor.png \
    icons/delete.png \
    icons/fix.png \
    icons/P.png \
    icons/parametrs.png \
    icons/point.png \
    icons/point1.png \
    icons/question-mark.png \
    icons/restr.png \
    icons/search.png \
    icons/seg.png \
    icons/segment.png \
    icons/select.png

RESOURCES += \
    icons/icons.qrc

OTHER_FILES +=

