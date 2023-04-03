#include <iostream>

using namespace std;

float operator"" _Kelvin(long double x)
{
	return x - 273.15;
}

float operator"" _Farenheit(long double x)
{
	return (x - 32.0) / 1.8;
}

int main()
{
	float a = 300.0_Kelvin;
	float b = 120.0_Farenheit;
	printf("%.2fC, %.2fC", a, b);
	
	return 0;
}