#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "TransportStorage/TransportStorage.h"
#include "Transport/TransportBase/TransportBase.h"
#include "Database/Database.h"
#include "Transport/Transport.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"
#include "Serializable/Serializable.h"

#include <memory>
#include <chrono>
#include <thread>

#include <QMap>

// Данный класс отвечает за все операции со структурой и базой данных в зависимости от полученных комманд

class Controller
{
public:
    Controller();

    ~Controller();

    void addNewElement(std::vector<std::string>& args);

    void editElement(std::vector<std::string> args);

    QString& deleteDatabaseElement(const uint32_t& ID);

    bool checkElementAvilable(const uint32_t& ID);

    // Метод возвращает объект класса в который обёрнута структура данных
    TransportStorage& getStorage();

    void setList(TransportStorage& inputStorage);

    void setID(const uint32_t& ID);

    uint32_t& getID();

    void loadDatabase();

    void saveDatabase();

private:
    std::unique_ptr<Serializator> serializator;

    uint32_t uniqueID;
    std::shared_ptr<TransportStorage> transportStorage;
    QString deletingResult;
    std::shared_ptr<TransportObjectCreator> transportObjectCreator;
    Database* db;
};

#endif //CONTROLLER_H
