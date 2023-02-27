#include "Students.h"
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
int cmp_name(Student* x1, Student* x2)
{
	char s1[256], s2[256];
	strcpy(s1, x1->getName());
	strcpy(s2, x2->getName());
	for (int i = 0; i < strlen(s1); i++)
		s1[i] = s1[i] + ('a' - 'A');
	for (int i = 0; i < strlen(s2); i++)
		s2[i] = s2[i] + ('a' - 'A');
	return strcmp(s1, s2);
}

int cmp_eng_grade(Student* x1, Student* x2)
{
	if (x1->get_grade_english() > x2->get_grade_english())
		return 1;
	else if (x1->get_grade_english() < x2->get_grade_english())
		return -1;
	return 0;
}
int cmp_math_grade(Student* x1, Student* x2)
{
	if (x1->get_grade_math() > x2->get_grade_math())
		return 1;
	else if (x1->get_grade_math() < x2->get_grade_math())
		return -1;
	return 0;
}
int cmp_history_grade(Student* x1, Student* x2)
{
	if (x1->get_grade_history() > x2->get_grade_history())
		return 1;
	else if (x1->get_grade_history() < x2->get_grade_history())
		return -1;
	return 0;
}
int cmp_average(Student* x1, Student* x2)
{
	if (x1->get_average() > x2->get_average())
		return 1;
	else if (x1->get_average() < x2->get_average())
		return -1;
	return 0;
}