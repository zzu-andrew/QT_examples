#-------------------------------------------------
#
# Project created by QtCreator 2023-09-13T16:16:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt03_uis
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        forms/allwindow.ui \
        forms/common/fontedit.ui \
        forms/completer/completerwindow.ui \
        forms/constraints/columncollatepanel.ui \
        forms/constraints/columndefaultpanel.ui \
        forms/constraints/columnforeignkeypanel.ui \
        forms/constraints/columngeneratedpanel.ui \
        forms/constraints/columnprimarykeypanel.ui \
        forms/constraints/columnuniqueandnotnullpanel.ui \
        forms/constraints/constraintcheckpanel.ui \
        forms/constraints/tableforeignkeypanel.ui \
        forms/constraints/tablepkanduniquepanel.ui \
        forms/constraints/tableprimarykeypanel.ui \
        forms/dbtree/dbtree.ui \
        forms/debugconsole.ui \
        forms/dialogs/aboutdialog.ui \
        forms/dialogs/bindparamsdialog.ui \
        forms/dialogs/columndialog.ui \
        forms/dialogs/configdialog.ui \
        forms/dialogs/constraintdialog.ui \
        forms/dialogs/cssdebugdialog.ui \
        forms/dialogs/dbdialog.ui \
        forms/dialogs/ddlpreviewdialog.ui \
        forms/dialogs/errorsconfirmdialog.ui \
        forms/dialogs/execfromfiledialog.ui \
        forms/dialogs/fileexecerrorsdialog.ui \
        forms/dialogs/importdialog.ui \
        forms/dialogs/indexdialog.ui \
        forms/dialogs/indexexprcolumndialog.ui \
        forms/dialogs/languagedialog.ui \
        forms/dialogs/messagelistdialog.ui \
        forms/dialogs/newconstraintdialog.ui \
        forms/dialogs/newversiondialog.ui \
        forms/dialogs/populateconfigdialog.ui \
        forms/dialogs/populatedialog.ui \
        forms/dialogs/quitconfirmdialog.ui \
        forms/dialogs/searchtextdialog.ui \
        forms/dialogs/sortdialog.ui \
        forms/dialogs/triggercolumnsdialog.ui \
        forms/dialogs/triggerdialog.ui \
        forms/dialogs/versionconvertsummarydialog.ui \
        forms/forms/sqlformatterplugin.ui \
        forms/statusfield.ui \
        forms/windows/codesnippeteditor.ui \
        forms/windows/collationseditor.ui \
        forms/windows/ddlhistorywindow.ui \
        forms/windows/editorwindow.ui \
        forms/windows/functionseditor.ui \
        forms/windows/sqliteextensioneditor.ui \
        forms/windows/tablewindow.ui \
        forms/windows/viewwindow.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
