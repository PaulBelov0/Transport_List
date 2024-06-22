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

    outputString[5] = "Wingspan: ";
    outputString[5] += wingspan;
    outputString[6] = "Payload capacity: ";
    outputString[6] += payloadCapacity;

    for (int i = 5; i < 7; i++)
    {
        output[7] = QString::fromStdString(outputString[i]);
    }

    return output;
}

std::string AirTransport::finderOnValueType(char typeOfValue)
{
	std::string returningValue = TransportBase::finderOnValueType(typeOfValue);

	if (returningValue == std::to_string(NULL))
	{
		if (typeOfValue == '6')
		{
			returningValue = std::to_string(wingspan);
			return returningValue;
		}
		else if (typeOfValue == '7')
		{
			returningValue = std::to_string(payloadCapacity);
		}
	}
	else
	{
		return returningValue;
	}
}
