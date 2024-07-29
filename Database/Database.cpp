#include "Database.h"

Database::Database()
{
    QCoreApplication::addLibraryPath ("./plugins");
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("./TransportDatabase.db");
    db->open();

    //В случае добавления новых полей в классы наследующих TransportBase - добавить соответствующие Special... поля в БД.

    query = new QSqlQuery;
    *query = QSqlQuery(*db);
    query->exec("CREATE TABLE TransportDatabase(ID INT, Type TEXT, Brand TEXT, Model TEXT, Year INT, Weight INT, SpecialFirst INT, SpecialSecond TEXT);");

    outputStorage.reset(download().get());
}

Database::~Database()
{
    delete query;
    delete db;
}

std::unique_ptr<TransportStorage> Database::download()
{
    std::list<std::shared_ptr<TransportBase>> list;
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

            list.push_back(creator.getTransportObject());
        }

    std::unique_ptr<TransportStorage> outputStorage(new TransportStorage(list));
    return outputStorage;

}

void Database::upload(TransportStorage& inputStorage)
{

    for(const auto& element : inputStorage.getList())
    {
        query->prepare("INSERT INTO TransportDatabase(ID, Type, Brand, Model, Year, Weight, Specialfirst, SpecialSecond)"
                       "VALUES(:ID, :Type, :Brand, :Model, :Year, :Weight, :SpecialFirst, :SpecialSecond)");

        // Binding all values:

        query->bindValue(":ID", element->uniqueID);
        query->bindValue(":Type", QString::fromStdString(element->type));
        query->bindValue(":Brand", QString::fromStdString(element->brand));
        query->bindValue(":Model", QString::fromStdString(element->model));
        query->bindValue(":Year", element->year);
        query->bindValue(":Weight", element->weight);

        if (element->type == "Air")
        {
            auto air = std::dynamic_pointer_cast<std::shared_ptr<AirTransport>>(element);
            query->bindValue(":SpecialFirst", air.get()->get()->wingspan);
            query->bindValue(":SpecialSecond", air.get()->get()->payloadCapacity);
        }
        else if (element->type == "Car")
        {
            auto car = std::dynamic_pointer_cast<std::shared_ptr<Car>>(element);
            query->bindValue(":SpecialFirst", car.get()->get()->mileage);
            query->bindValue(":SpecialSecond", car.get()->get()->ownersQuantity);
        }
        else if (element->type == "Boat")
        {
            auto boat = std::dynamic_pointer_cast<std::shared_ptr<Boat>>(element);
            query->bindValue(":SpecialFirst", boat.get()->get()->displacement);
            query->bindValue(":SpecialSecond", boat.get()->get()->screwDepth);
        }
        else
        {
            auto shuttle = std::dynamic_pointer_cast<std::shared_ptr<Shuttle>>(element);
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
