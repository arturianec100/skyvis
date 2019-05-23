#-------------------------------------------------
#
# Project created by QtCreator 2019-05-10T16:10:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skyvis
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
        src/abstract/asyncworker.cpp \
        src/ast/area.cpp \
        src/ast/connection.cpp \
        src/ast/diagram.cpp \
        src/ast/node.cpp \
        src/common.cpp \
        src/gui/mainwindow.cpp \
        src/main.cpp \
        src/models/filelistmodel.cpp \
        src/premainwindowinitialization.cpp \
        src/project/project.cpp \
        src/serialization/diagramserializer.cpp \
        src/storage/diagramstorage.cpp

HEADERS += \
    src/abstract/asyncworker.h \
    src/appinfo.h \
    src/ast/area.h \
    src/ast/connection.h \
    src/ast/diagram.h \
    src/ast/node.h \
    src/common.h \
    src/gui/mainwindow.h \
    src/models/filelistmodel.h \
    src/premainwindowinitialization.h \
    src/project/project.h \
    src/serialization/diagramserializer.h \
    src/storage/diagraminfo.h \
    src/storage/diagramstorage.h

FORMS += \
    src/gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    LICENSE.md \
    README.md \
    src/README.md \
    src/abstract/README.md \
    src/ast/README.md \
    src/gui/README.md \
    src/models/README.md \
    src/project/README.md \
    src/serialization/README.md \
    src/storage/README.md
