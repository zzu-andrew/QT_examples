#-------------------------------------------------
#
# Project created by QtCreator 2021-05-20T14:15:42
#
#-------------------------------------------------

QT       += core gui
QT       += webenginewidgets webchannel
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += warn_off

TARGET = WeComCopy
TEMPLATE = app
DESTDIR = bin

unix:UI_DIR = ../tmp/ui
win32:UI_DIR = tmp/ui

INCLUDEPATH += include

SOURCES += source/main.cpp\
        source/wecomwnd.cpp \
    source/navpane.cpp \
    source/pushbuttonex.cpp \
    source/iconhelper.cpp \
    source/appinit.cpp \
    source/userdetaildlg.cpp \
    source/basedlg.cpp \
    source/logindlg.cpp \
    source/friendslist.cpp \
    source/msgpane.cpp \
    source/chattoptoolbar.cpp \
    source/msgqueue.cpp \
    source/contactspane.cpp \
    source/weatherpane.cpp \
    source/clockpane.cpp \
    source/incofontpane.cpp \
    source/tipwidget.cpp \
    source/catpane.cpp \
    source/navigationbar.cpp \
    source/notificationpane.cpp \
    source/component.cpp \
    source/popconfirm.cpp \
    source/slider.cpp \
    source/dynamiccard.cpp \
    source/datamgrpane.cpp \
    source/userpane.cpp \
    source/boderpane.cpp \
    source/userprofiles.cpp \
    source/appreciatedlg.cpp \
    source/carouselpane.cpp

HEADERS  += include/wecomwnd.h \
    include/navpane.h \
    include/pushbuttonex.h \
    include/iconhelper.h \
    include/appinit.h \
    include/userdetaildlg.h \
    include/public.h \
    include/basedlg.h \
    include/logindlg.h \
    include/friendslist.h \
    include/msgpane.h \
    include/chattoptoolbar.h \
    include/msgqueue.h \
    include/contactspane.h \
    include/weatherpane.h \
    include/clockpane.h \
    include/incofontpane.h \
    include/tipwidget.h \
    include/catpane.h \
    include/navigationbar.h \
    include/notificationpane.h \
    include/component.h \
    include/popconfirm.h \
    include/slider.h \
    include/dynamiccard.h \
    include/datamgrpane.h \
    include/userpane.h \
    include/boderpane.h \
    include/userprofiles.h \
    include/appreciatedlg.h \
    include/carouselpane.h

FORMS    += ui/wecomwnd.ui \
    ui/userprofiles.ui \
    ui/appreciatedlg.ui

RESOURCES += \
    res/wecomcopy.qrc

RC_FILE +=  \
    res/WeComCopy.rc
