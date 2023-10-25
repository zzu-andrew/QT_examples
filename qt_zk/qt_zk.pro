#-------------------------------------------------
#
# Project created by QtCreator 2023-09-20T16:34:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_zk
TEMPLATE = app



INCLUDEPATH += $$PWD/zookeeper/include

LIBS += -lws2_32 -L$$PWD/zookeeper/lib/Debug -lzookeeper  -L$$PWD/zookeeper/lib/Debug -lhashtable

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_CXXFLAGS += -std=c++11

#CONFIG += THREADED=1

DEFINES += THREADED

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        CreateChildNodeDialog.cpp \
        EditValueDialog.cpp        \
        ZKNodeTreeModel.cpp \
        ZKConnectionWorker.cpp \
        DeleteNodeDialog.cpp    \
        Language.cpp             \
        ZKDataViewWidget.cpp    \
        ZKClientGUI.cpp       \
        EditConnectionsModel.cpp \
        ZKNodeTreeItem.cpp


HEADERS += \
        mainwindow.h \
        ZKNodeTreeItem.h \
        CreateChildNodeDialog.h \
        EditValueDialog.h    \
        ZKConnection.h    \
        ZKNodeTreeModel.h  \
        ZKConnectionWorker.h \
        DeleteNodeDialog.h    \
        Language.h \
        ZKDataViewWidget.h \
        EditConnectionsModel.h  \
        ZKClientGUI.h



FORMS += \
        mainwindow.ui \
        ZKClientGUI.ui \
        CreateChildNodeDialog.ui \
        EditValueDialog.ui \
        DeleteNodeDialog.ui \
        ZKDataViewWidget.ui



RESOURCES += ZKClientGUI.qrc

TRANSLATIONS += zkclientgui_zh-cn.ts


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
