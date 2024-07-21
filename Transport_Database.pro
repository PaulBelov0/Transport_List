QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += object_parallel_to_source

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database/Database.cpp \
    DeleteElementWindow.cpp \
    EditElementFieldsWindow.cpp \
    MainWindow.cpp \
    MessageToUserWindow.cpp \
    SearchElementWindow.cpp \
    Transport/TransportCreator/TransportObjectCreator.cpp \
    Menu/Menu.cpp \
    Transport/AirTransport.cpp \
    Transport/Boat.cpp \
    Transport/Car.cpp \
    Transport/Shuttle.cpp \
    Transport/TransportBase/TransportBase.cpp \
    TransportStorage/TransportStorage.cpp \
    main.cpp
    Menu.cpp
    TransportBase.cpp
    Car.cpp
    Shuttle.cpp
    Boat.cpp
    AirTransport.cpp

HEADERS += \
    Database/Database.h \
    DeleteElementWindow.h \
    EditElementFieldsWindow.h \
    MainWindow.h \
    MessageToUserWindow.h \
    SearchElementWindow.h \
    Transport/Transport.h \
    Transport/TransportCreator/TransportObjectCreator.h \
    Menu/Menu.h \
    Transport/AirTransport.h \
    Transport/Boat.h \
    Transport/Car.h \
    Transport/Shuttle.h \
    Transport/TransportBase/TransportBase.h \
    TransportStorage/TransportStorage.h \
    transport.h
    TransportBase.h
    Boat.h
    Car.h
    Shuttle.h
    AirTransport.h
    Menu.h

FORMS += \
    DeleteElementWindow.ui \
    EditElementFieldsWindow.ui \
    MainWindow.ui \
    MessageToUserWindow.ui \
    SearchElementWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


HEADERS += \
    Database/Database.h \
    DeleteElementWindow.h \
    EditElementFieldsWindow.h \
    MainWindow.h \
    MessageToUserWindow.h \
    SearchElementWindow.h \

FORMS += \
    DeleteElementWindow.ui \
    EditElementFieldsWindow.ui \
    MainWindow.ui \
    MessageToUserWindow.ui \
    SearchElementWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
