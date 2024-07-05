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
}

Database::~Database() { delete query; delete db; }

TransportMap& Database::download()
{
    while (query->next())
    {
        std::map<uint32_t, std::unique_ptr<TransportBase>> mapTmp = outputMap.getMap();
        std::unique_ptr<TransportCreator> creator = std::make_unique<TransportCreator>(query->value("ID").toUInt(), query->value("Type").toString(),
                                 query->value("Brand").toString(), query->value("Model").toString(),
                                 query->value("Year").toUInt(), query->value("weight").toUInt(),
                                 query->value("SpecialFirst").toUInt(), query->value("SpecialSecond").toString());

        std::initializer_list<std::pair<const uint32_t, std::unique_ptr<TransportBase>>>list =
            {std::pair<const uint32_t, std::unique_ptr<TransportBase>>(query->value("ID").toUInt(), creator->createTransportObject())};

        mapTmp.insert(list);
    }

    return outputMap;

}

void Database::upload(TransportMap& inputMap)
{

    for(const auto& element : inputMap.getMap())
    {
        query->prepare("INSERT INTO TransportDatabase(ID, Type, Brand, Model, Year, Weight, Specialfirst, SpecialSecond)"
                       "VALUES(:ID, :Type, :Brand, :Model, :Year, :Weight, :Specialfirst, :SpecialSecond)");
        query->bindValue(":ID", element.second->getID());
        query->bindValue(":Type", element.second->getType());
        query->bindValue(":Brand", element.second->getBrand());
        query->bindValue(":Model", element.second->getModel());
        query->bindValue(":Year", element.second->getYear());
        query->bindValue(":Weight", element.second->getWeight());
        query->bindValue(":SepcialFirst", element.second->getSpecialFirst());
        query->bindValue(":SpecialSecond", element.second->getSpecialSecond());

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
