#-------------------------------------------------
#
# Project created by QtCreator 2017-07-17T16:56:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    HashTable.cpp \
    TrieTree.cpp \
    WordEntry.cpp \
    imput.cpp \
    phrasetable.cpp \
    showtext.cpp \
    lists.cpp \
    stopwords.cpp

HEADERS += \
        mainwindow.h \
    HashTable.h \
    TrieTree.h \
    WordEntry.h \
    imput.h \
    phrasetable.h \
    showtext.h \
    lists.h \
    stopwords.h

FORMS += \
        mainwindow.ui \
    showtext.ui

DISTFILES += \
    stopwords_en.txt
