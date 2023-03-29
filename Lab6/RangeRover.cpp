#include "RangeRover.h"
#include <cstring>

RangeRover::RangeRover()
{
	this->capacity = 73;
	this->speed = 94;
	this->fuelCons = 6.4;
	this->name = new char[11];
	strcpy_s(this->name, 11, "RangeRover");
	this->name[10] = '\0';
}

int RangeRover::getSpeed()
{
	return this->speed;
}
int RangeRover::getCapacity()
{
	return this->capacity;
}
int RangeRover::getFuelCons()
{
	return this->fuelCons;
}

char* RangeRover::getName()
{
	return this->name;
}
