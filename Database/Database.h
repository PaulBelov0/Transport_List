#ifndef DATABASE_H
#define DATABASE_H

#include <QVariant>
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

    std::unique_ptr<TransportStorage> download();
    void upload(TransportStorage& inputMap);
    QSqlDatabase& getDatabase();
    QSqlQuery& getQuery();

private:
    std::unique_ptr<TransportStorage> outputMap;

    QSqlDatabase* db;
    QSqlQuery* query;
};

#endif // DATABASE_H
