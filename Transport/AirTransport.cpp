#include <Transport/AirTransport.h>

//Realizaton air transport class:

AirTransport::AirTransport(uint32_t ID)
{
	uniqueID = ID;
	type = "Air Transport";
}

AirTransport::~AirTransport() {}

void AirTransport::editWingspan(int wingspan)
{
	this->wingspan = wingspan;
}

void AirTransport::editPayloadCapacity(int payloadCapacity)
{
	this->payloadCapacity = payloadCapacity;
}

QString* AirTransport::print()
{
    QString* output = new QString [7];

    TransportBase::print();

    outputString[5] = wingspan;
    outputString[6] = payloadCapacity;

    for (int i = 5; i < 7; i++)
    {
        output[7] = QString::fromStdString(outputString[i]);
    }

    return output;
}

