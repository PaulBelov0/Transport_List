#ifndef DATABASE_H
#define DATABASE_H

#include <QVariant>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlDriver>
#include <TransportMap/transportmap.h>
#include <Transport/TransportCreator/TransportCreator.h>

class Database
{
public:
    Database();
    ~Database();

    TransportMap& download();
    void upload(TransportMap& inputMap);
    QSqlDatabase& getDatabase();
    QSqlQuery& getQuery();

private:
    TransportMap outputMap;

    QSqlDatabase* db;
    QSqlQuery* query;
};

#endif // DATABASE_H
