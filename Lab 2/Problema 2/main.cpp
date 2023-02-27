#include "Students.h"
#include "Comparisons.h"
#include <cstring>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	Student *a, *b;
	a = new Student;
	b = new Student;
	a->setName("Marian");
	
	printf("%s:", a->getName());

	a->set_grade_english(7);
	a->set_grade_history(8);
	a->set_grade_math(10);
	a->set_Average();

	printf("%d %d %d %f \n", a->get_grade_english(), a->get_grade_history(), a->get_grade_math(), a->get_average());

	b->setName("Costica");
	printf("%s:", b->getName());

	b->set_grade_english(5);
	b->set_grade_history(10);
	b->set_grade_math(7);
	b->set_Average();
	
	printf("%d %d %d %f \n", b->get_grade_english(), b->get_grade_history(), b->get_grade_math(), b->get_average());
	printf("%d %d %d %d %d", cmp_average(a, b), cmp_eng_grade(a, b), cmp_history_grade(a, b), cmp_math_grade(a, b), cmp_name(a, b));
}
