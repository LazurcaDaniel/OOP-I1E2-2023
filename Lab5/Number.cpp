#include "Number.h"
#include <iostream>
#include <cstring>
#include <stdio.h>



long int chVal(const char c)
{
	if (c >= '0' && c <= '9')
		return (long int)(c - '0');
	else
	{
		return (long int)(c - 'A' + 10);
	}
}

long int conv_base10(char* c, int base)
{
	long int rez = 0;
	long int p = 1;
	int l = strlen(c);
	for (int i = l - 1; i >= 0; i--)
	{
		
		rez += p * chVal(c[i]);
		p *= (long int)base;
	}
	return rez;
}

Number::Number()
{
	this->base = 0;
	this->value = nullptr;
}

Number::Number(const char* value, int base)
{
	
		this->base = base;
		int i = strlen(value) + 1;
		this->value = new char[i];
		memcpy(this->value, value, i);
	
	
}

Number::Number(const Number& x)
{
	this->value = new char[strlen(x.value) + 1];
	strcpy_s(this->value, strlen(x.value) + 1, x.value);
	this->base = x.base;
}

Number::Number(Number&& x)
{
		this->value = x.value;
		this->base = x.base;
		x.value = nullptr;
}

int Number::GetBase()
{
	return this->base;
}

int Number::GetDigitsCount()
{
	return strlen(this->value);
}

Number::Number(const long int x)
{
	char rez[255];
	_itoa_s(x, rez, 10);
	rez[strlen(rez)] = '\0';
	this->value = new char[strlen(rez) + 1];
	strcpy_s(this->value, strlen(rez) + 1, rez);
	this->base = 10;
	
}

char reVal(int x)
{
	if (x >= 0 && x < 10)
		return (char)(x + '0');
	else
		return (char)(x - 10 + 'A');
}

void Number::SwitchBase(int newBase)
{
	if (newBase >= 2 && newBase <= 16) 
	{
		char rez[255];
		long int x = conv_base10(this->value, this->base);
		int index = 0;

		while (x > 0)
		{
			rez[index++] = reVal(x % newBase);
			x /= newBase;
		}

		rez[index] = '\0';

		int length = strlen(rez);

		for (int i = 0; i < length / 2; i++)
		{
			std::swap(rez[i], rez[length - i - 1]);
		}

		
		this->value = new char[length + 1];
		this->base = newBase;
		strcpy_s(this->value, length + 1, rez);
	}
}

char Number::operator[](int index)
{
	if (index >= 0 && index < strlen(this->value))
		return this->value[index];
	return -1;
}

Number& Number::operator=(const Number& x)
{
	int length = strlen(x.value) + 1;
	this->value = new char[length];
	strcpy_s(this->value, length, x.value);
	this->base = x.base;

	return (*this);
}

Number& Number::operator=(const char* str)
{
	Number d1(str, 10);
	if (this->base >= 2 && this->base <= 16)
		d1.SwitchBase(this->base);
	this->value = new char[strlen(d1.value) + 1];
	strcpy_s(this->value, strlen(d1.value) + 1, d1.value);
	this->base = 10;
	return(*this);

}

Number& Number::operator=(long int x)
{
	char rez[256];
	_itoa_s(x, rez, 10);
	rez[strlen(rez)] = '\0';
	this->value = new char[strlen(rez) + 1];
	strcpy_s(this->value, strlen(rez) + 1, rez);
	this->base = 10;
	return(*this);
}

Number operator+(const Number& x, const Number& y)
{
	int new_base = x.base > y.base ? x.base : y.base;
	long int d1 = conv_base10(x.value, x.base);
	long int d2 = conv_base10(y.value, y.base);
	long int rez = d1 + d2;
	
	Number k(rez);
	k.SwitchBase(new_base);
	return k;

}

Number operator-(const Number& x,const  Number& y)
{
	int new_base = x.base > y.base ? x.base : y.base;
	long int d1 = conv_base10(x.value, x.base);
	long int d2 = conv_base10(y.value, y.base);
	long int rez = d1 -	 d2;

	Number k(rez);
	k.SwitchBase(new_base);

	return k;

}

Number& Number::operator+=(Number& x)
{
	Number k(this->value, this->base);
	k = k + x;
	this->value = new char[strlen(k.value) + 1];
	strcpy_s(this->value, strlen(k.value) + 1, k.value);
	this->base = k.base;

	return (*this);
}

Number& Number::operator-=(Number& x)
{
	Number k(this->value, this->base);
	k = k - x;
	this->value = new char[strlen(k.value) + 1];
	strcpy_s(this->value, strlen(k.value) + 1, k.value);
	this->base = k.base;
	free(k.value);
	k.base = NULL;
	return(*this);
}


bool Number::operator>(Number& x)
{
	long int d1 = conv_base10(this->value, this->base);
	long int d2 = conv_base10(x.value,x.base);
	if (d1 > d2)
		return 1;
	return 0;
}

bool Number::operator<(Number& x)
{
	long int d1 = conv_base10(this->value, this->base);
	long int d2 = conv_base10(x.value, x.base);
	if (d1 < d2)
		return 1;
	return 0;
}


bool Number::operator<=(Number& x)
{
	long int d1 = conv_base10(this->value, this->base);
	long int d2 = conv_base10(x.value, x.base);
	if (d1 <= d2)
		return 1;
	return 0;
}


bool Number::operator>=(Number& x)
{
	long int d1 = conv_base10(this->value, this->base);
	long int d2 = conv_base10(x.value, x.base);
	if (d1 >= d2)
		return 1;
	return 0;
}


bool Number::operator==(Number& x)
{
	long int d1 = conv_base10(this->value, this->base);
	long int d2 = conv_base10(x.value, x.base);
	if (d1 == d2)
		return 1;
	return 0;
}

Number& Number::operator--(int)
{
	this->value[strlen(this->value) - 1] = '\0';
	return (*this);
}

Number& Number::operator--()
{
	strcpy_s(this->value, strlen(this->value), this->value + 1);
	return (*this);
}

Number& Number::operator++()
{
	int d = conv_base10(this->value, this->base);
	d++;
	Number k(d);
	k.SwitchBase(this->base);
	
	this->value = new char[strlen(k.value) + 1];
	strcpy_s(this->value, strlen(k.value) + 1, k.value);
	free(k.value);
	k.base = NULL;
	return(*this);
}

Number& Number::operator++(int)
{
	int d = conv_base10(this->value, this->base);
	d++;
	Number k(d);
	k.SwitchBase(this->base);
	
	this->value = new char[strlen(k.value) + 1];
	strcpy_s(this->value, strlen(k.value) + 1, k.value);
	free(k.value);
	k.base = NULL;
	return(*this);
}

void Number::Print()
{
	printf("%s\n", this->value);
}

Number :: ~Number()
{
	if (this->value != nullptr)
	{
	
		this->value = nullptr;
		this->base = NULL;
	}
}