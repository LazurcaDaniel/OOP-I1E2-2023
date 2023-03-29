#pragma once
#include "Car.h"
class RangeRover : public Car
{
public:
	RangeRover();
	int getSpeed();
	int getCapacity();
	int getFuelCons();
	char* getName();
};

