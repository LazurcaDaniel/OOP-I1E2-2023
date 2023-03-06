#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Math
{
public:
	int Add(int, int);
	int Add(int, int, int);
	double Add(double, double);
	double Add(double, double, double);
	int Mul(int, int);
	int Mul(int, int, int);
	double Mul(double, double);
	double Mul(double, double, double);
	int Add(int count, ...);
	char* Add(const char*, const char*);
};

