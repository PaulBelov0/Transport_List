#ifndef MENU_H
#define MENU_H

#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>
#include <Database/Database.h>
#include <Transport/transport.h>
#include <MessageToUserWindow.h>
#include <memory>
#include <QMap>
class Menu
{
public:

    Menu();
	~Menu();

    int addNewElement(const uint32_t& ID, const QString& type,
                      const QString& brand, const QString& model,
                      const uint32_t& year, const uint32_t& weight,
                      const uint32_t& specialFirst, const QString& specialSecond
                      );
    void editElement(const uint32_t& ID, const QString& type,
                     const QString& brand, const QString& model,
                     const uint32_t& year, const uint32_t& weight,
                     const uint32_t& specialFirst, const QString& specialSecond
                     );

    QString& deleteDatabaseElement(const uint32_t& ID);

    bool checkElementAvilable(uint32_t& ID);

    TransportMap& getMap();

    void setMap(TransportMap& inputMap);

    void setID(uint32_t& ID);

    uint32_t& getID();


private:
    MessageToUserWindow* messageToUserWindow;
    uint32_t uniqueID;
    std::unique_ptr<TransportMap> transportMap;
    QString deletingResult;
};

#endif //MENU_H
