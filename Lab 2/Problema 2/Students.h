#pragma once
#define _CRT_SECURE_NO_WARNINGS
class Student
{
private:
	 char* name;
	int grade_english, grade_math, grade_history;
	float average_grade;
public:
	Student(); ///init

	/// Setters
	bool setName(const char* name);
	bool set_grade_english(int x);
	bool set_grade_math(int x);
	bool set_grade_history(int x);
	bool set_Average();
	 
	///Getters
	const char* getName();
	int get_grade_english();
	int get_grade_math();
	int get_grade_history();
	float get_average();
};
