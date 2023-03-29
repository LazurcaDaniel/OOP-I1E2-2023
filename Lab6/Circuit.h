#pragma once
#include <iostream>
#include "Car.h"
class Circuit
{
	int len, n;
	double constanta;
	int max_index;
	Car** a;
public:
	Circuit();
	~Circuit();
	void SetLength(int l);
	void SetWeather(int w);
	bool AddCar(Car* x);
	double GetRaceSpeed(Car* x);
	double GetRaceFuelCons(Car* x);
	double GetRaceTime(Car* x);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();

};


