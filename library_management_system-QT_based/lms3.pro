#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T01:30:18
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lms3
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    usecase.cpp \
    view_info.cpp \
    book_s.cpp \
    hold_b.cpp \
    add_s.cpp \
    u_info.cpp \
    add_i.cpp \
    del_i.cpp \
    c_info.cpp \
    view_info_s.cpp \
    hold_b_s.cpp

HEADERS  += login.h \
    usecase.h \
    view_info.h \
    book_s.h \
    hold_b.h \
    add_s.h \
    u_info.h \
    add_i.h \
    del_i.h \
    c_info.h \
    view_info_s.h \
    hold_b_s.h

FORMS    += login.ui \
    usecase.ui \
    view_info.ui \
    view_info.ui \
    book_s.ui \
    hold_b.ui \
    add_s.ui \
    u_info.ui \
    add_i.ui \
    del_i.ui \
    c_info.ui \
    view_info_s.ui \
    hold_b_s.ui
