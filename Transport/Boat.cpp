#include <Transport/Boat.h>
//Realization boat class:

Boat::Boat(const int& ID, const QString& brand,
           const QString& model, const int& year,
           const int& weight, const int& displacement,
           const int& screwDepth
           )
    : TransportBase(ID, brand, model, year, weight)
{
    type = "Boat";
    this->displacement = displacement;
    this->screwDepth = std::stoi(std::to_string(screwDepth));
}

Boat::Boat(TransportBase* transportObject)
    : TransportBase(transportObject->getID().toUInt(), transportObject->getBrand().toString(),
                    transportObject->getModel().toString(), transportObject->getYear().toUInt(),
                    transportObject->getWeight().toUInt()
                    )
{
    type = "Boat";
    this->displacement = transportObject->getSpecialFirst().toUInt();
    this->screwDepth = transportObject->getSpecialSecond().toUInt();
}

Boat::~Boat() {}

void Boat::operator=(TransportBase& object)
{
    TransportBase::operator=(object);
    displacement = object.getSpecialFirst().toUInt();
    screwDepth = object.getSpecialSecond().toUInt();
}

std::unique_ptr<TransportBase> Boat::clone() const
{
    return std::make_unique<Boat>(*this);
}

void Boat::editSpecialFirst(const uint32_t& displacement)
{
    this->displacement = displacement;
}


void Boat::editSpecialSecond(const QString& screwDepth)
{
    this->screwDepth = screwDepth.toInt();
}

QVariant Boat::getSpecialFirst()
{
    return QString::fromStdString(std::to_string(displacement));
}

QVariant Boat::getSpecialSecond()
{
    return QString::fromStdString(std::to_string(screwDepth));
}
