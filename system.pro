TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    user.c \
    report.c \
    resource.c \
    file.c \
    activity.c

HEADERS += \
    user.h \
    report.h \
    resource.h \
    file.h \
    activity.h

