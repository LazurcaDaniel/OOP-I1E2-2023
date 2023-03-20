#pragma once
class Number
{
	int base;
	char* value;
public:
	Number(const char* value, int base); ///base between 2 and 16
	Number(const long int x);
	Number(const Number& x);
	Number(Number&& x);
	Number();
	~Number();

	friend Number operator+(const Number& x,const Number& y);
	friend Number operator-(const Number& x,const Number& y);
	Number& operator+=(Number& x);
	Number& operator-=(Number& x);

	Number& operator=(const Number& x);
	Number& operator=(const char* str);
	Number& operator=(long int x);

	Number& operator++();
	Number& operator++(int);
	Number& operator--(int);
	Number& operator--();


	bool operator>(Number& x);
	bool operator<(Number& x);
	bool operator<=(Number& x);
	bool operator>=(Number& x);
	bool operator==(Number& x);

	char operator[](int index);
	
	
	
	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();

};

char reVal(int x);
long int chVal(const char c);
long int conv_base10(char* c, int base);