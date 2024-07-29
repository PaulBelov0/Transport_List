#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "TransportStorage/TransportStorage.h"
#include "Transport/TransportBase/TransportBase.h"
#include "Database/Database.h"
#include "Transport/Transport.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"

#include <memory>

#include <QMap>

class Controller
{
public:
    Controller(const TransportStorage& storage);

    void addNewElement(std::vector<std::string>& args);

    void editElement(std::vector<std::string> args);

    QString& deleteDatabaseElement(const uint32_t& ID);

    bool checkElementAvilable(const uint32_t& ID);

    TransportStorage& getStorage();

    void setList(const TransportStorage& inputStorage);

    void setID(const uint32_t& ID);

    uint32_t& getID();

    void loadDatabase();

    void saveDatabase();

private:
    uint32_t uniqueID;
    std::shared_ptr<TransportStorage> transportStorage;
    QString deletingResult;
    std::shared_ptr<TransportObjectCreator> transportObjectCreator;
    Database* db;
};

#endif //CONTROLLER_H
