#pragma once
class Car
{
public:
	virtual int getSpeed() = 0;
	virtual int getCapacity() = 0;
	virtual int getFuelCons() = 0;
	virtual char* getName() = 0;
protected:
	char* name;
	int speed, capacity, fuelCons;
};

