#pragma once
#include "Car.h"
class Volvo: public Car
{
public:
	Volvo();
	int getSpeed();
	int getCapacity();
	int getFuelCons();
	char* getName();
};

