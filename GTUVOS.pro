TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
    mainwindow.cpp \
    mailserver.cpp \
    gtuvos.cpp \
    copycmd.cpp \
    commandfactory.cpp \
<<<<<<< HEAD \
    helpcmd.cpp \
    lscmd.cpp \
    mailcmd.cpp \
    exitcmd.cpp
    mailcmd.cpp \
    mail.cpp

=======
    mail.cpp \
    mailcmd.cpp \
    helpcmd.cpp \
    exitcmd.cpp \
<<<<<<< HEAD
    lscmd.cpp
>>>>>>> master
=======
    lscmd.cpp \
    mkdircmd.cpp \
    touchcmd.cpp
>>>>>>> master

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mailserver.h \
    mainwindow.h \
    gtuvos.h \
    command.h \
    copycmd.h \
    commandfactory.h \
<<<<<<< HEAD \
    mailcmd.h \
    lscmd.h \
    helpcmd.h \
    gtuexceptions.h \
    rapidxml.hpp \
    rapidxml_utils.hpp
    mailcmd.h \
    mail.h
=======
    mail.h \
    mailcmd.h \
    helpcmd.h \
    exitcmd.h \
<<<<<<< HEAD
    lscmd.h
>>>>>>> master
=======
    lscmd.h \
    gtuexceptions.h \
    mkdircmd.h \
    touchcmd.h
>>>>>>> master

FORMS += \
    mainwindow.ui \
    mailserver.ui
