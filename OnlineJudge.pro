QT += core
QT -= gui

CONFIG += c++11

TARGET = OnlineJudge
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    resolve.cpp

HEADERS += \
    resolve.h
