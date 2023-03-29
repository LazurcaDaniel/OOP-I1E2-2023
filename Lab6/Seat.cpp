#include "Seat.h"
#include <cstring>

Seat::Seat()
{
	this->capacity = 58;
	this->speed = 75;
	this->fuelCons = 5;
	this->name = new char[5];
	strcpy_s(this->name, 5, "Seat");
	this->name[4] = '\0';
}

int Seat::getSpeed()
{
	return this->speed;
}
int Seat::getCapacity()
{
	return this->capacity;
}
int Seat::getFuelCons()
{
	return this->fuelCons;
}

char* Seat::getName()
{
	return this->name;
}