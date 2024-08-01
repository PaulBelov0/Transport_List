#include "Database.h"

Database::Database()
    : db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
      query(new QSqlQuery(*db))
{
    db->setDatabaseName("./TransportDatabase.db");
    db->open();

    query->exec("CREATE TABLE TransportDatabase(ID INT, Type TEXT, Brand TEXT, Model TEXT, Year INT, Weight INT, SpecialFirst INT, SpecialSecond TEXT);");

    outputStorage.reset(new TransportStorage());
}

Database::~Database()
{
    //delete query;
    //delete db;
}


TransportStorage& Database::download()
{
    std::list<std::shared_ptr<TransportBase>> list;

    std::vector<std::string> transportArgs;

    if (db->isValid() == true)
        while (query->next() == true)
        {
            transportArgs.push_back(query->value("ID").toString().toStdString());
            transportArgs.push_back(query->value("Type").toString().toStdString());
            transportArgs.push_back(query->value("Brand").toString().toStdString());
            transportArgs.push_back(query->value("Model").toString().toStdString());
            transportArgs.push_back(query->value("Year").toString().toStdString());
            transportArgs.push_back(query->value("Weght").toString().toStdString());
            transportArgs.push_back(query->value("SpecialFirst").toString().toStdString());
            transportArgs.push_back(query->value("SpecialSecond").toString().toStdString());

            TransportObjectCreator creator(transportArgs);

            list.push_back(creator.getTransportObject());
        }

    std::shared_ptr<TransportStorage> outputStorage(new TransportStorage(list));
    return *outputStorage.get();

}

void Database::upload(std::list<std::shared_ptr<TransportBase>> inputMap)
{

    for(const auto& element : inputMap)
    {
        query->prepare("INSERT INTO TransportDatabase(ID, Type, Brand, Model, Year, Weight, Specialfirst, SpecialSecond)"
                       "VALUES(:ID, :Type, :Brand, :Model, :Year, :Weight, :Specialfirst, :SpecialSecond)");

        // Binding all values:

        query->bindValue(":ID", element->uniqueID);
        query->bindValue(":Type", QString::fromStdString(element->type));
        query->bindValue(":Brand", QString::fromStdString(element->brand));
        query->bindValue(":Model", QString::fromStdString(element->model));
        query->bindValue(":Year", element->year);
        query->bindValue(":Weight", element->weight);

        if(element->type == "Air")
        {
            std::shared_ptr<AirTransport> airTmp = std::dynamic_pointer_cast<AirTransport>(element);
            query->bindValue(":SepcialFirst", airTmp->wingspan);
            query->bindValue(":SpecialSecond", airTmp->payloadCapacity);
        }
        else if(element->type == "Car")
        {
            std::shared_ptr<Car> carTmp = std::dynamic_pointer_cast<Car>(element);
            query->bindValue(":SepcialFirst", carTmp->mileage);
            query->bindValue(":SpecialSecond", carTmp->ownersQuantity);
        }
        else if (element->type == "Boat")
        {
            std::shared_ptr<Boat> boatTmp = std::dynamic_pointer_cast<Boat>(element);
            query->bindValue(":SepcialFirst", boatTmp->displacement);
            query->bindValue(":SpecialSecond", boatTmp->screwDepth);
        }
        else if (element->type == "Shuttle")
        {
            std::shared_ptr<Shuttle> shuttleTmp = std::dynamic_pointer_cast<Shuttle>(element);
            query->bindValue(":SepcialFirst", shuttleTmp->maxFlyingDistance);
            query->bindValue(":SpecialSecond", QString::fromStdString(shuttleTmp->fuelType));
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
