#include "NumberList.h"
#include <stdio.h>
using namespace std;

void NumberList::Init()
{
	this->count = 0;
}

bool NumberList::Add(int x)
{
	if (this->count >= 10)
		return false;
	this->number[this->count] = x;
	this->count++;
	return true;
}

void NumberList::Sort()
{
	bool ok = 0;
	do
	{
		ok = 0;
		for(int i=0; i<this->count-1; i++)
			if (this->number[i] > this->number[i + 1])
			{
				int aux = this->number[i];
				this->number[i] = this->number[i + 1];
				this->number[i + 1] = aux;
				ok = 1;
			}
	} while (ok);
}

void NumberList::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ",this->number[i]);
}