TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        crypt.cpp \
        main.cpp \
        products.cpp \
        users.cpp

HEADERS += \
    products.h \
    users.h
