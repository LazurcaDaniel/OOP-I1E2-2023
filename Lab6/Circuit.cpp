#include "Circuit.h"
#include <iomanip>
Circuit::Circuit()
{
	len = n = 0;
	constanta = 0;
	max_index = 255;
	a = new Car*[255];
}

void Circuit::SetLength(int l)
{
	len = l;
}

void Circuit::SetWeather(int w)
{
	constanta = w / 100.0;
}

bool Circuit::AddCar(Car* x)
{
	if (n < this->max_index) {
		a[n] = x;
		n++;
		return true;
	}
	return false;
}

double Circuit::GetRaceFuelCons(Car* x)
{
	return 1.0 * (x->getFuelCons() * (1 + constanta)) / 100;
}

double Circuit::GetRaceSpeed(Car* x)
{
	return 1.0 * (x->getSpeed() * (1 - constanta));
}

double Circuit::GetRaceTime(Car *x)
{
	return len / GetRaceSpeed(x);
}

void Circuit::Race()
{
	bool ok = 0;
	do
	{
		ok = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (GetRaceTime(a[i]) > GetRaceTime(a[i + 1]))
			{
				std::swap(a[i], a[i + 1]);
				ok = 1;
			}
		}
	} while (ok);
}

void Circuit::ShowFinalRanks()
{
	int loc = 1;

	for (int i = 0; i < n; i++)
	{
		double consumTotal = a[i]->getCapacity();
		
		double timp = GetRaceTime(a[i]);
		consumTotal -= len * GetRaceFuelCons(a[i]);
		
		if (consumTotal >= 0)
		{
			std::cout << "Masina " << a[i]->getName() << " a terminat pe locul " << loc << " cu timpul de " << std::setprecision(4) << timp << " secunde.\n";
			loc++;
		}
	}
}

void Circuit::ShowWhoDidNotFinish()
{

	for (int i = 0; i < n; i++)
	{
		double consumTotal = a[i]->getCapacity();

		consumTotal -= len * GetRaceFuelCons(a[i]);

		if (consumTotal < 0)
		{
			std::cout << a[i]->getName() << " nu a terminat cursa! \n";
		}
	}
}

Circuit :: ~Circuit()
{
	len = n = 0;
	constanta = 0.0;
	if(a != nullptr)
		delete[] a;
}
