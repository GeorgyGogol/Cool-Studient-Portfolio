#-------------------------------------------------
#
# Project created by QtCreator 2023-01-21T14:18:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cellular-Automaton-1
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
        src/automat/ccell.cpp \
        src/automat/cfield.cpp \
        src/automat/cfieldsettings.cpp \
        src/automat/cfileserver.cpp \
        src/forms/fieldsettingsform.cpp \
        src/forms/mainwindow.cpp \
        src/forms/widgets/gcell.cpp \
        src/forms/widgets/mainformstatusbar.cpp \
        src/main.cpp
		
HEADERS += \
    src/automat/ccell.h \
    src/automat/cfield.h \
    src/automat/cfieldsettings.h \
    src/automat/cfileserver.h \
    src/automat/core.h \
    src/forms/fieldsettingsform.h \
    src/forms/mainwindow.h \
    src/forms/widgets/gcell.h \
    src/forms/widgets/mainformstatusbar.h
	
FORMS += \
    src/forms/fieldsettingsform.ui \
    src/forms/mainwindow.ui

RESOURCES += \
    res/mainresources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

