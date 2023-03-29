#pragma once
#include "Car.h"
class Seat : public Car
{
public:
	Seat();
	int getSpeed();
	int getCapacity();
	int getFuelCons();
	char* getName();
};

