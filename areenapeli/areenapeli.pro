TEMPLATE = app

QT += qml quick widgets quickwidgets
CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    fightingscene.cpp \
    areenateam.cpp \
    areenamember.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    fightingscene.h \
    areenateam.h \
    areenamember.h

FORMS += \
    mainwindow.ui \
    fightingscene.ui

