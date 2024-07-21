QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET += ConsoleApp
CONFIG += c++17
CONFIG += console
CONFIG += object_parallel_to_source

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database/Database.cpp \
    Transport/TransportCreator/TransportObjectCreator.cpp \
    Menu/Menu.cpp \
    Transport/AirTransport.cpp \
    Transport/Boat.cpp \
    Transport/Car.cpp \
    Transport/Shuttle.cpp \
    Transport/TransportBase/TransportBase.cpp \
    TransportStorage/TransportStorage.cpp \
    Controller/Controller.cpp \
    main.cpp
    Menu.cpp
    TransportBase.cpp
    Car.cpp
    Shuttle.cpp
    Boat.cpp
    AirTransport.cpp

HEADERS += \
    Database/Database.h \
    Transport/Transport.h \
    Transport/TransportCreator/TransportObjectCreator.h \
    Menu/Menu.h \
    Transport/AirTransport.h \
    Transport/Boat.h \
    Transport/Car.h \
    Transport/Shuttle.h \
    Transport/TransportBase/TransportBase.h \
    TransportStorage/TransportStorage.h \
    Controller/Controller.h \
    Transport/Transport.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# HEADERS += \
#     Database/Database.h \

# FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
