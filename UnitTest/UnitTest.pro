QT += testlib network sql
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_unittest.cpp \
    C:/others/code/project/1325/singletondb.cpp \
    C:/others/code/project/1325/mytcpserver.cpp

HEADERS += \
    C:/others/code/project/1325/singletondb.h \
    C:/others/code/project/1325/mytcpserver.h \
    C:/others/code/project/1325/func.h
