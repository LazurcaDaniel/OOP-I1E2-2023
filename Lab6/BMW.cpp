#include "BMW.h"
#include <cstring>

BMW::BMW()
{
	this->capacity = 60;
	this->speed = 112; 
	this->fuelCons = 11;
	this->name = new char[4];
	strcpy_s(this->name, 4, "BMW");
	this->name[3] = '\0';
}

int BMW::getSpeed()
{
	return this->speed;
}
int BMW::getCapacity()
{
	return this->capacity;
}
int BMW::getFuelCons()
{
	return this->fuelCons;
}

char* BMW::getName()
{
	return this->name;
}
