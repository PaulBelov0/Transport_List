QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    TransportMap/transportmap.cpp \
    Menu/Menu.cpp \
    Transport/AirTransport.cpp \
    Transport/Boat.cpp \
    Transport/Car.cpp \
    Transport/Shuttle.cpp \
    Transport/TransportBase/TransportBase.cpp \
    Transport_Map/transportmap.cpp \
    main.cpp \
    mainwindow.cpp
    Menu.cpp
    TransportBase.cpp
    Car.cpp
    Shuttle.cpp
    Boat.cpp
    Air.Transport.cpp

HEADERS += \
    TransportMap/transportmap.h \
    Menu/Menu.h \
    Transport/AirTransport.h \
    Transport/Boat.h \
    Transport/Car.h \
    Transport/Shuttle.h \
    Transport/TransportBase/TransportBase.h \
    Transport/transport.h \
    Transport_Map/transportmap.h \
    mainwindow.h
    transport.h
    TransportBase.h
    Boat.h
    Car.h
    Shuttle.h
    AirTransport.h
    Menu.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
