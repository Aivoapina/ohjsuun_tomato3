TARGET = abstractitemmodel
TEMPLATE = app

QT += qml quick widgets quickwidgets
CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    fightingscene.cpp \
    arenamember.cpp \
    arenateam.cpp \
    controller.cpp \
    map.cpp \
    tile.cpp \
    kiltahuone.cpp \
    kiltamodel.cpp \
    plebruutu.cpp \
    lintulawindow.cpp \
    myqframe.cpp \
    shopscene.cpp \
    shop.cpp

RESOURCES += qml.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/models/abstractitemmodel
target.path = $$[QT_INSTALL_EXAMPLES]/corelib/tools/customcompleter

INSTALLS += target
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    fightingscene.h \
    arenamember.h \
    arenateam.h \
    controller.h \
    map.h \
    tile.h \
    kiltahuone.h \
    kiltamodel.h \
    plebruutu.h \
    lintulawindow.h \
    myqframe.h \
    shopscene.h \
    shop.h

FORMS += \
    mainwindow.ui \
    fightingscene.ui \
    kiltahuone.ui \
    plebruutu.ui \
    lintulawindow.ui \
    shopscene.ui \
    myqframe.ui

OTHER_FILES += \
    objectlist.txt

