#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>

#include "TransportStorage/TransportStorage.h"
#include "Transport/TransportCreator/TransportObjectCreator.h"

class Database
{
public:
    Database();
    ~Database();

    TransportStorage& download();
    void upload(std::list<std::shared_ptr<TransportBase>> inputMap);
    QSqlDatabase& getDatabase();
    QSqlQuery& getQuery();

private:
    std::shared_ptr<TransportStorage> outputStorage;

    QSqlDatabase* db;
    QSqlQuery* query;
};

#endif // DATABASE_H
