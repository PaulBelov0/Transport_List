#ifndef MENU_H
#define MENU_H

#include <TransportMap/transportmap.h>
#include <Transport/TransportBase/TransportBase.h>
#include <Database/Database.h>
#include <Transport/transport.h>

class Menu
{
public:

	Menu();
	~Menu();

    int addNewElement(const uint32_t& ID,
                      const QString& type,
                      const QString& brand,
                      const QString& model,
                      const uint32_t& year,
                      const uint32_t& weight,
                      const uint32_t& specFirst,
                      const QString& specSecond
                      );
    void editElement(const uint32_t& ID,
                     const QString& type,
                     const QString& brand,
                     const QString& model,
                     const uint32_t& year,
                     const uint32_t& weight,
                     const uint32_t& specFirst,
                     const QString& specSecond
                     );
    QString& deleteDatabaseElement(const uint32_t& ID);
    void findElement();
    void saveDatabase();
    TransportMap& loadDatabase();
    QSqlDatabase* getDatabaseFromSource();

    bool checkElementAvilable(uint32_t& ID);

private:
    static uint32_t uniqueID;
    TransportMap& transportMap;
    Database database;
};

#endif //MENU_H
