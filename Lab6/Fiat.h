#pragma once
#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	int getSpeed();
	int getCapacity();
	int getFuelCons();
	char* getName();
};

