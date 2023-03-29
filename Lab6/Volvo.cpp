#include "Volvo.h"
#include <cstring>

Volvo::Volvo()
{
	this->capacity = 80;
	this->speed = 80;
	this->fuelCons = 5;
	this->name = new char[6];
	strcpy_s(this->name, 6, "Volvo");
	this->name[5] = '\0';
}

int Volvo::getSpeed()
{
	return this->speed;
}
int Volvo::getCapacity()
{
	return this->capacity;
}
int Volvo::getFuelCons()
{
	return this->fuelCons;
}

char* Volvo::getName()
{
	return this->name;
}
