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
            std::vector<std::string> args;

            //Binding arguments to create transport object:

            args.push_back(query->value("ID").toString().toStdString());
            args.push_back(query->value("Type").toString().toStdString());
            args.push_back(query->value("Brand").toString().toStdString());
            args.push_back(query->value("Model").toString().toStdString());
            args.push_back(query->value("Year").toString().toStdString());
            args.push_back(query->value("weight").toString().toStdString());
            args.push_back(query->value("SpecialFirst").toString().toStdString());
            args.push_back(query->value("SpecialSecond").toString().toStdString());

            //End of binding

            TransportObjectCreator creator(args);

            map.insert({creator.getTransportObject()->uniqueID, creator.getTransportObject()});
        }

    std::unique_ptr<TransportStorage> outputStorage(new TransportStorage(map));
    return outputStorage;

}

void Database::upload(TransportStorage& inputStorage)
{

    for(const auto& element : inputStorage.getMap())
    {
        query->prepare("INSERT INTO TransportDatabase(ID, Type, Brand, Model, Year, Weight, Specialfirst, SpecialSecond)"
                       "VALUES(:ID, :Type, :Brand, :Model, :Year, :Weight, :SpecialFirst, :SpecialSecond)");

        // Binding all values:

        query->bindValue(":ID", element.second->uniqueID);
        query->bindValue(":Type", QString::fromStdString(element.second->type));
        query->bindValue(":Brand", QString::fromStdString(element.second->brand));
        query->bindValue(":Model", QString::fromStdString(element.second->model));
        query->bindValue(":Year", element.second->year);
        query->bindValue(":Weight", element.second->weight);

        if (element.second->type == "Air")
        {
            auto air = std::dynamic_pointer_cast<std::shared_ptr<AirTransport>>(element.second);
            query->bindValue(":SpecialFirst", air.get()->get()->wingspan);
            query->bindValue(":SpecialSecond", air.get()->get()->payloadCapacity);
        }
        else if (element.second->type == "Car")
        {
            auto car = std::dynamic_pointer_cast<std::shared_ptr<Car>>(element.second);
            query->bindValue(":SpecialFirst", car.get()->get()->mileage);
            query->bindValue(":SpecialSecond", car.get()->get()->ownersQuantity);
        }
        else if (element.second->type == "Boat")
        {
            auto boat = std::dynamic_pointer_cast<std::shared_ptr<Boat>>(element.second);
            query->bindValue(":SpecialFirst", boat.get()->get()->displacement);
            query->bindValue(":SpecialSecond", boat.get()->get()->screwDepth);
        }
        else
        {
            auto shuttle = std::dynamic_pointer_cast<std::shared_ptr<Shuttle>>(element.second);
            query->bindValue(":SpecialFirst", shuttle.get()->get()->maxFlyingDistance);
            query->bindValue(":SpecialSecond", QString::fromStdString(shuttle.get()->get()->fuelType));
        }
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
