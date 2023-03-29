#pragma once
#include "Car.h"
class BMW : public Car
{
public:
	BMW();
	int getSpeed();
	int getCapacity();
	int getFuelCons();
	char* getName();
};

