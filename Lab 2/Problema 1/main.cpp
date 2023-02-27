#include <stdio.h>
#include "NumberList.h"

int main()
{
	NumberList vector;
	vector.Init();
	vector.Add(16);
	vector.Add(312);
	vector.Add(31);
	vector.Add(94);
	vector.Add(-13);
	vector.Add(0);
	vector.Add(100);
	vector.Add(432);
	vector.Add(986);
	vector.Add(875);
	//aici nu mai adauga valoarea, fiind al 11-lea element
	vector.Add(1);
	vector.Print();
	vector.Sort();
	printf("\n");
	vector.Print();

}