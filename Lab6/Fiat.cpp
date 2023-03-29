#include "Fiat.h"
#include <cstring>

Fiat::Fiat()
{
	this->capacity = 50;
	this->speed = 75;
	this->fuelCons = 3.5;
	this->name = new char[5];
	strcpy_s(this->name, 5, "Fiat");
	this->name[4] = '\0';
}

int Fiat::getSpeed()
{
	return this->speed;
}
int Fiat::getCapacity()
{
	return this->capacity;
}
int Fiat::getFuelCons()
{
	return this->fuelCons;
}

char* Fiat::getName()
{
	return this->name;
}
