#include "Students.h"
#include <cstring>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

Student::Student()
{
	this->grade_english = 0;
	this->grade_math = 0;
	this->grade_history = 0;
	this->average_grade = 0;
	this->name = new char[100];
}

bool Student::setName(const char *name)
{
	
	if (strlen(name) > 100)
		return false;
	strcpy(this->name, name);
	this->name[strlen(this->name)] = '\0';
	return true;
}

bool Student::set_grade_english(int x)
{
	if (x < 1 || x>10)
		return false;
	this->grade_english = x;
	return true;
}
bool Student::set_grade_history(int x)
{
	if (x < 1 || x>10)
		return false;
	this->grade_history = x;
	return true;
}
bool Student::set_grade_math(int x)
{
	if (x < 1 || x>10)
		return false;
	this->grade_math = x;
	return true;
}

bool Student::set_Average()
{
	if (this->grade_english > 0 && this->grade_history > 0 && this->grade_math > 0)
	{
		this->average_grade = (float)((this->grade_english + this->grade_history + this->grade_math) / 3.0); return true;
	}
	return false;
}

const char* Student:: getName()
{
	return this->name;
}

float Student::get_average()
{
	return this->average_grade;
}

int Student::get_grade_english()
{
	return this->grade_english;
}

int Student::get_grade_history()
{
	return this->grade_history;
}

int Student::get_grade_math()
{
	return this->grade_math;
}