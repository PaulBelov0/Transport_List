#ifndef MENU_H
#define MENU_H

#include "TransportStorage/TransportStorage.h"
#include "Transport/TransportBase/TransportBase.h"
#include "Database/Database.h"
#include "Transport/Transport.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"
#include "MessageToUserWindow.h"

#include <memory>
#include <QMap>

class Menu
{
public:

    Menu();
	~Menu();

    int addNewElement(const uint32_t& ID, const std::string& type,
                      const std::string& brand, const std::string& model,
                      const uint32_t& year, const uint32_t& weight,
                      const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                      );

    void editElement(const uint32_t& ID, const std::string& type,
                     const std::string& brand, const std::string& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFieldFirst, const std::string& specialFieldSecond
                     );

    QString& deleteDatabaseElement(const uint32_t& ID);

    bool checkElementAvilable(const uint32_t& ID);

    TransportStorage& getStorage();

    void setMap(TransportStorage& inputStorage);

    void setID(const uint32_t& ID);

    uint32_t& getID();


private:
    MessageToUserWindow* messageToUserWindow;
    uint32_t uniqueID;
    std::unique_ptr<TransportStorage> transportStorage;
    QString deletingResult;
    std::shared_ptr<TransportObjectCreator> transportObjectCreator;
};

#endif //MENU_H
