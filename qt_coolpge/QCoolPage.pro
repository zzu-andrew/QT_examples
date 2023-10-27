#-------------------------------------------------
#
# Project created by QtCreator 2019-06-16T13:01:16
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QCoolPage
TEMPLATE = app

MOC_DIR = $$OUT_PWD/mocfile
OBJECTS_DIR = $$OUT_PWD/objfile
UI_DIR = $$OUT_PWD/uifile
RCC_DIR = $$OUT_PWD/rcfile


SOURCES += main.cpp\
        mainwindow.cpp \
    titlebar/maintitlebar.cpp \
    titlebar/titlebar.cpp \
    maincontent/controltabwidget.cpp \
    maincontent/controltreewidget.cpp \
    systemtray/systemtray.cpp \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.cpp \
    maincontent/controlwidget/progresscontrol/progresswidget.cpp \
    maincontent/controlwidget/progresscontrol/progresscontrol.cpp \
    maincontent/controlwidget/cylindercontrol/cylindercontrol.cpp \
    flowlayout/flowlayout.cpp \
    maincontent/controlwidget/framecontrol/framecontrol.cpp \
    maincontent/controlwidget/framecontrol/framewidget.cpp \
    maincontent/controlwidget/bannacontrol/bannacontrol.cpp \
    maincontent/controlwidget/bannacontrol/bannawidget.cpp \
    qcustomplot/qcustomplot.cpp \
    maincontent/controlwidget/plotcontrol/plotwidget.cpp \
    maincontent/controlwidget/plotcontrol/plotcontrol.cpp \
    maincontent/controlwidget/movecontrol/movecontrol.cpp \
    maincontent/controlwidget/movecontrol/movewidget.cpp \
    maincontent/controlwidget/tablecontrol/tablecontrol.cpp \
    maincontent/controlwidget/tablecontrol/tablewidget.cpp \
    numberanimation/numberanimation.cpp \
    maincontent/controlwidget/slidercontrol/slidercontrol.cpp \
    maincontent/controlwidget/slidercontrol/sliderwidget.cpp \
    maincontent/controlwidget/openglcontrol/cameralibrary.cpp \
    maincontent/controlwidget/openglcontrol/objectfactory.cpp \
    maincontent/controlwidget/openglcontrol/shaderlibrary.cpp \
    maincontent/controlwidget/openglcontrol/texturelibrary.cpp \
    maincontent/controlwidget/openglcontrol/objectmodel/objectparent.cpp \
    maincontent/controlwidget/openglcontrol/objectmodel/objectcube.cpp \
    maincontent/controlwidget/openglcontrol/openglcontrol.cpp \
    maincontent/controlwidget/openglcontrol/openglwidget.cpp \
    maincontent/controlwidget/processcontrol/processcontrol.cpp \
    maincontent/controlwidget/processcontrol/processwidget.cpp \
    maincontent/controlwidget/listcontrol/listcontrol.cpp \
    maincontent/controlwidget/listcontrol/listwidget.cpp \
    screen/mainobject.cpp \
    screen/splashscreen.cpp


HEADERS  += mainwindow.h \
    globaldef.hpp \
    titlebar/maintitlebar.h \
    titlebar/titlebar.h \
    maincontent/controltabwidget.h \
    maincontent/controltreewidget.h \
    systemtray/systemtray.h \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.h \
    maincontent/controlwidget/progresscontrol/progresswidget.h \
    maincontent/controlwidget/progresscontrol/progresscontrol.h \
    maincontent/controlwidget/cylindercontrol/cylindercontrol.h \
    flowlayout/flowlayout.h \
    maincontent/controlwidget/framecontrol/framecontrol.h \
    maincontent/controlwidget/framecontrol/framewidget.h \
    maincontent/controlwidget/bannacontrol/bannacontrol.h \
    maincontent/controlwidget/bannacontrol/bannawidget.h \
    qcustomplot/qcustomplot.h \
    maincontent/controlwidget/plotcontrol/plotwidget.h \
    maincontent/controlwidget/plotcontrol/plotcontrol.h \
    maincontent/controlwidget/movecontrol/movecontrol.h \
    maincontent/controlwidget/movecontrol/movewidget.h \
    maincontent/controlwidget/tablecontrol/tablecontrol.h \
    maincontent/controlwidget/tablecontrol/tablewidget.h \
    numberanimation/numberanimation.h \
    maincontent/controlwidget/slidercontrol/slidercontrol.h \
    maincontent/controlwidget/slidercontrol/sliderwidget.h \
    maincontent/controlwidget/openglcontrol/cameralibrary.h \
    maincontent/controlwidget/openglcontrol/objectfactory.h \
    maincontent/controlwidget/openglcontrol/opengldef.h \
    maincontent/controlwidget/openglcontrol/shaderlibrary.h \
    maincontent/controlwidget/openglcontrol/texturelibrary.h \
    maincontent/controlwidget/openglcontrol/objectmodel/objectparent.h \
    maincontent/controlwidget/openglcontrol/objectmodel/objectcube.h \
    maincontent/controlwidget/openglcontrol/openglcontrol.h \
    maincontent/controlwidget/openglcontrol/openglwidget.h \
    maincontent/controlwidget/processcontrol/processcontrol.h \
    maincontent/controlwidget/processcontrol/processwidget.h \
    maincontent/controlwidget/listcontrol/listcontrol.h \
    maincontent/controlwidget/listcontrol/listwidget.h \
    screen/mainobject.h \
    screen/splashscreen.h


FORMS    += mainwindow.ui \
    titlebar/maintitlebar.ui \
    maincontent/controltabwidget.ui \
    maincontent/controltreewidget.ui \
    maincontent/controlwidget/cylindercontrol/cylinderwidget.ui \
    maincontent/controlwidget/progresscontrol/progresswidget.ui \
    maincontent/controlwidget/progresscontrol/progresscontrol.ui \
    maincontent/controlwidget/cylindercontrol/cylindercontrol.ui \
    maincontent/controlwidget/framecontrol/framewidget.ui \
    maincontent/controlwidget/bannacontrol/bannacontrol.ui \
    maincontent/controlwidget/bannacontrol/bannawidget.ui \
    maincontent/controlwidget/plotcontrol/plotwidget.ui \
    maincontent/controlwidget/plotcontrol/plotcontrol.ui \
    maincontent/controlwidget/movecontrol/movecontrol.ui \
    maincontent/controlwidget/movecontrol/movewidget.ui \
    maincontent/controlwidget/tablecontrol/tablecontrol.ui \
    maincontent/controlwidget/tablecontrol/tablewidget.ui \
    maincontent/controlwidget/slidercontrol/slidercontrol.ui \
    maincontent/controlwidget/slidercontrol/sliderwidget.ui \
    maincontent/controlwidget/openglcontrol/openglwidget.ui \
    maincontent/controlwidget/processcontrol/processcontrol.ui \
    maincontent/controlwidget/processcontrol/processwidget.ui \
    maincontent/controlwidget/listcontrol/listcontrol.ui \
    maincontent/controlwidget/listcontrol/listwidget.ui

RESOURCES += \
    res.qrc \
    res/shaders.qrc \
    res/textures.qrc

RC_FILE += myapp.rc
