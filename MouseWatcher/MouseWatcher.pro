#-------------------------------------------------
#
# Project created by QtCreator 2023-02-12T10:47:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MouseWatcher
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

INCLUDEPATH += src/forms/widgets

SOURCES += \
    src/forms/mainwindow.cpp \
    src/forms/widgets/graphicswatcharea.cpp \
    src/forms/widgets/groupboxinfo.cpp \
    src/forms/widgets/mousepoint.cpp \
    src/main.cpp \
    src/watcher/exceptions/wexception.cpp \
    src/watcher/exceptions/wioexception.cpp \
    src/watcher/wiomanager.cpp \
    src/watcher/wpoint.cpp \
    src/watcher/wwatcher.cpp

HEADERS += \
    src/forms/mainwindow.h \
    src/forms/widgets/graphicswatcharea.h \
    src/forms/widgets/groupboxinfo.h \
    src/forms/widgets/mousepoint.h \
    src/watcher.h \
    src/watcher/exceptions/wexception.h \
    src/watcher/exceptions/wioexception.h \
    src/watcher/wiomanager.h \
    src/watcher/wpoint.h \
    src/watcher/wwatcher.h

FORMS += \
    src/forms/mainwindow.ui \
    src/forms/widgets/groupboxinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
