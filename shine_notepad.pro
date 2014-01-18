#-------------------------------------------------
#
# Project created by QtCreator 2013-11-04T01:01:03
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shine_notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timeline.cpp \
    movable.cpp \
    timeline_motion.cpp \
    central.cpp \
    motions_table.cpp \
    viewport.cpp

HEADERS  += mainwindow.h \
    timeline.h \
    movable.h \
    timeline_motion.h \
    central.h \
    motions_table.h \
    viewport.h

FORMS    += mainwindow.ui \
    timeline.ui \
    central.ui \
    motions_table.ui \
    viewport.ui
