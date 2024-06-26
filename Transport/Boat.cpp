#include <Transport/Boat.h>
//Realization boat class:

Boat::Boat(uint32_t ID)
{
	uniqueID = ID;
	type = "Water Transport";
}

Boat::~Boat() {}

void Boat::editDisplacement(int displacement)
{
	this->displacement = displacement;
}

void Boat::editScrewDepth(int screwDepth)
{
	this->screwDepth = screwDepth;
}

QString* Boat::print()
{
    QString* output = new QString [7];

    TransportBase::print();

    outputString[5] = "Displacement: ";
    outputString[5] += displacement;
    outputString[6] = "Screw depth: ";
    outputString[6] += screwDepth;

    for (int i = 5; i < 7; i++)
    {
        output[7] = QString::fromStdString(outputString[i]);
    }

    return output;
}

