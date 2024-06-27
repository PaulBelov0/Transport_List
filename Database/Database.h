#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <TransportMap/transportmap.h>

class Database
{
public:
    Database();
    ~Database();

    TransportMap& download();
    void upload();
    QSqlDatabase* getDatabase();

private:

    QSqlDatabase* db;
    QSqlQuery* query;
};

#endif // DATABASE_H
