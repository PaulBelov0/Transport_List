#include "Database.h"

Database::Database()
{
    db = new QSqlDatabase;
    db->addDatabase("QSQLITE");
    db->setDatabaseName("./testDB");

    query = new QSqlQuery(*db);
    query->exec("CREATE TABLE TransportDatabase(ID INT, Type TEXT, Model TEXT, Year INT, Weight INT, SpecialFirst TEXT, SpecialSecond INT)");
}

Database::~Database() { delete query; delete db; }

TransportMap& Database::download()
{
    TransportMap map;

    return map;

}

void Database::upload()
{
    TransportMap map;
    for(const auto& element : map.getMap())
    {

    }
}

QSqlDatabase* Database::getDatabase()
{
    return db;
}
