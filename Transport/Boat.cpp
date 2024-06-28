#include <Transport/Boat.h>
//Realization boat class:

Boat::Boat(const int& ID, const QString& brand,
           const QString& model, const int& year,
           const int& weight, const int& displacement,
           const int& screwDepth
           )
{
    uniqueID = ID;
    type = "Boat";
    this->brand = brand.toStdString();
    this->model = model.toStdString();
    this->year = year;
    this->weight = weight;
    this->displacement = displacement;
    this->screwDepth = screwDepth;
}

Boat::~Boat() {}

void Boat::editSpecialFirst(const uint32_t& displacement)
{
    this->displacement = displacement;
}


void Boat::editSpecialSecond(const QString& screwDepth)
{
    this->screwDepth = screwDepth.toInt();
}

uint32_t& Boat::getSpecialFirst()
{
    return displacement;
}

QString& Boat::getSpecialSecond()
{
    std::string tmp = std::to_string(screwDepth);
    outputQstring = QString::fromStdString(tmp);
    return outputQstring;
}
