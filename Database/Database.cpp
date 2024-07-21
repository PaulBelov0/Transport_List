#include "Database.h"

Database::Database()
{
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("./TransportDatabase.db");
    db->open();

    query = new QSqlQuery;
    *query = QSqlQuery(*db);
    query->exec("CREATE TABLE TransportDatabase(ID INT, Type TEXT, Brand TEXT, Model TEXT, Year INT, Weight INT, SpecialFirst INT, SpecialSecond TEXT);");

    outputStorage.reset(download().get());
}

Database::~Database() { delete query; delete db; }

std::unique_ptr<TransportStorage> Database::download()
{
    std::map<uint32_t, std::shared_ptr<TransportBase>> map;
    if (db->isValid())
        while (query->next())
        {
            TransportObjectCreator creator(query->value("ID").toUInt(), query->value("Type").toString().toStdString(),
                                           query->value("Brand").toString().toStdString(), query->value("Model").toString().toStdString(),
                                           query->value("Year").toUInt(), query->value("weight").toUInt(),
                                           query->value("SpecialFirst").toUInt(), query->value("SpecialSecond").toString().toStdString());

            map.insert({creator.getTransportObject()->getID(), creator.getTransportObject()});
        }

    std::unique_ptr<TransportStorage> outputStorage(new TransportStorage(map));
    return outputStorage;

}

void Database::upload(TransportStorage& inputStorage)
{

    for(const auto& element : inputStorage.getMap())
    {
        query->prepare("INSERT INTO TransportDatabase(ID, Type, Brand, Model, Year, Weight, Specialfirst, SpecialSecond)"
                       "VALUES(:ID, :Type, :Brand, :Model, :Year, :Weight, :Specialfirst, :SpecialSecond)");

        // Binding all values:

        query->bindValue(":ID", element.second->getID());
        query->bindValue(":Type", QString::fromStdString(element.second->getType()));
        query->bindValue(":Brand", QString::fromStdString(element.second->getBrand()));
        query->bindValue(":Model", QString::fromStdString(element.second->getModel()));
        query->bindValue(":Year", element.second->getYear());
        query->bindValue(":Weight", element.second->getWeight());
        query->bindValue(":SepcialFirst", element.second->getSpecialFirst());
        query->bindValue(":SpecialSecond", QString::fromStdString(element.second->getSpecialSecond()));
    }
    query->finish();
}

QSqlDatabase& Database::getDatabase()
{
    return *db;
}

QSqlQuery& Database::getQuery()
{
    return *query;
}
