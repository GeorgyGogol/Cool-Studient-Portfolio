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
QMAKE_LFLAGS += -static -static-libgcc

#
# Windows, widgets and new files
#

INCLUDEPATH += \
    src/forms \
    src/forms/widgets

HEADERS += \
    src/forms/autofillsettingsform.h \
    src/forms/fieldsettingsform.h \
    src/forms/figurelibrary.h \
    src/forms/mainwindow.h \
    src/forms/widgets/fieldinfobox.h \
    src/forms/widgets/gcell.h \
    src/forms/widgets/mainformstatusbar.h \
    src/forms/widgets/controlledgridscene.h

SOURCES += \
    src/forms/autofillsettingsform.cpp \
    src/forms/fieldsettingsform.cpp \
    src/forms/figurelibrary.cpp \
    src/forms/mainwindow.cpp \
    src/forms/widgets/fieldinfobox.cpp \
    src/forms/widgets/gcell.cpp \
    src/forms/widgets/mainformstatusbar.cpp \
    src/forms/widgets/controlledgridscene.cpp

FORMS += \
    src/forms/autofillsettingsform.ui \
    src/forms/fieldsettingsform.ui \
    src/forms/figurelibrary.ui \
    src/forms/mainwindow.ui \
    src/forms/widgets/fieldinfobox.ui

#
# Window States
#

INCLUDEPATH += \
    src/forms/state \
    src/forms/state/Interfaces \
    src/forms/state/states

HEADERS += \
    src/forms/state/Interfaces/iwinstate.h \
    src/forms/state/statemanager.h \
    src/forms/state/states/stateempty.h \
    src/forms/state/states/staterun.h \
    src/forms/state/states/statewithfield.h \
    src/forms/state/states/stategameover.h

SOURCES += \
    src/forms/state/Interfaces/iwinstate.cpp \
    src/forms/state/statemanager.cpp \
    src/forms/state/states/stateempty.cpp \
    src/forms/state/states/staterun.cpp \
    src/forms/state/states/statewithfield.cpp \
    src/forms/state/states/stategameover.cpp

#
# Automat
#

INCLUDEPATH += \
    src/automat

HEADERS += \
    src/automat/ccell.h \
    src/automat/cfield.h \
    src/automat/cfieldsettings.h \
    src/automat/cfileserver.h \
    src/automat/core.h

SOURCES += \
    src/automat/ccell.cpp \
    src/automat/cfield.cpp \
    src/automat/cfieldsettings.cpp \
    src/automat/cfileserver.cpp

#    
# Recources and other
#

INCLUDEPATH += \
    src \
    src/utilites

HEADERS += \
    src/utilites/windowpointkeeper.h

SOURCES += \
    src/main.cpp

RESOURCES += \
    res/mainresources.qrc \
    versioninfo.rc

#
# Windows app info
#

RC_FILE = versioninfo.rc



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

