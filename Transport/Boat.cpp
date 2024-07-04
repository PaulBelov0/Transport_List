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
    specialFirst = displacement;
    specialSecond = std::to_string(screwDepth);
    outputQstring = "Q";
}

Boat::~Boat() {}

void Boat::editSpecialFirst(const uint32_t& displacement)
{
    specialFirst = displacement;
}


void Boat::editSpecialSecond(const QString& screwDepth)
{
    specialSecond = screwDepth.toInt();
}

QVariant& Boat::getSpecialFirst()
{
    outputQstring = specialFirst;
    return outputQstring;
}

QVariant& Boat::getSpecialSecond()
{
    outputQstring = QString::fromStdString(specialSecond);
    return outputQstring;
}
