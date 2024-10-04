QT += core gui
QT += sql
QT += network
QT += widgets

CONFIG += c++11

SOURCES += \
    gram.cpp \
    main.cpp \
    maintool.cpp \
    memorizewords.cpp \
    news.cpp \
    reading.cpp \
    repeatword.cpp \
    tran.cpp \
    widget.cpp

HEADERS += \
    gram.h \
    maintool.h \
    memorizewords.h \
    news.h \
    reading.h \
    repeatword.h \
    tran.h \
    widget.h

FORMS += \
    gram.ui \
    maintool.ui \
    memorizewords.ui \
    news.ui \
    reading.ui \
    repeatword.ui \
    tran.ui \
    widget.ui

RESOURCES += \
    image.qrc


QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
CONFIG += sdk_no_version_check
