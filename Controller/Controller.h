#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "TransportStorage/TransportStorage.h"
#include "Transport/TransportBase/TransportBase.h"
#include "Database/Database.h"
#include "Transport/Transport.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"

#include <memory>
#include <chrono>
#include <thread>

#include <QMap>

class Controller
{
public:
    Controller();

    void addNewElement(const uint32_t& ID, const std::string& type,
                      const std::string& brand, const std::string& model,
                      const uint32_t& year, const uint32_t& weight,
                      const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                      );

    void addNewElement(std::vector<std::string> args);

    void editElement(const uint32_t& ID, const std::string& type,
                     const std::string& brand, const std::string& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                     );

    void editElements(std::vector<std::string> args);

    QString& deleteDatabaseElement(const uint32_t& ID);

    bool checkElementAvilable(const uint32_t& ID);

    TransportStorage& getStorage();

    void setMap(TransportStorage& inputStorage);

    void setID(const uint32_t& ID);

    uint32_t& getID();


private:
    uint32_t uniqueID;
    std::unique_ptr<TransportStorage> transportStorage;
    QString deletingResult;
    std::shared_ptr<TransportObjectCreator> transportObjectCreator;
};

#endif //CONTROLLER_H
