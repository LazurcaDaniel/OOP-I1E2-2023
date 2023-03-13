#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>

Sort::Sort(int nr_elements, int min, int max) //1
{
	this->number_elements = nr_elements;
	this->list = new int[nr_elements+1];
	for (int i = 0; i < this->number_elements; i++)
	{
		this->list[i] = rand() % (max - min + 1) + min;
	}
}

Sort::Sort() : list(new int[10] {3, 7, 5, 3, 2, 6, 4, 10, 15, 3}) //2
{
	this->number_elements = 10;
}
Sort::Sort(int tmp[], int nr_elements) //3
{
	this->number_elements = nr_elements;
	this->list = new int[nr_elements + 1];
	for (int i = 0; i < this->number_elements; i++)
	{
		this->list[i] = tmp[i];
	}
}

Sort::Sort(int nr_elements, ...) // 4
{
	this->number_elements = nr_elements;
	this->list = new int[nr_elements];
	va_list l;
	va_start(l,nr_elements);
	for (int i = 0; i < nr_elements; i++)
	{
		this->list[i] = va_arg(l,int);
	}
}

Sort::Sort(char numbers[], int nr_elements)//5
{
	this->number_elements = nr_elements;
	this->list = new int[nr_elements];

	int count = 0;
	char* context = NULL;
	char* t = strtok_s(numbers, ",", &context);
	while (t != nullptr)
	{
		this->list[count] = atoi(t);
		t = strtok_s(nullptr, ",", &context);
		count++;
	}
}

int Sort::GetElementsCount()
{
	return this->number_elements;
}

int Sort::GetElementsIndex(int index)
{
	if (index < 0 || index > this->number_elements)
		return -1;

	return this->list[index];
}




void Sort::InsertSort(bool ascendent )
{
	if (ascendent)
	{
		int key, j;
		for (int i = 1; i < this->number_elements; i++)
		{
			key = this->list[i];
			j = i - 1;
			while (j >= 0 && this -> list[j] > key)
			{
				this->list[j + 1] = this->list[j];
				j--;
			}
			this->list[j + 1] = key;
		}
	}
	else
	{
		int key, j;
		for (int i = 1; i < this->number_elements; i++)
		{
			key = this->list[i];
			j = i - 1;
			while (j >= 0 && this -> list[j] < key)
			{
				this->list[j + 1] = this->list[j];
				j--;
			}
			this->list[j + 1] = key;
		}
	}
}

void Sort::BubbleSort(bool ascendent)
{
	bool ok = 0;
	if(ascendent)
	do
	{
		ok = 0;
		for (int i = 0; i < this->number_elements - 1; i++)
		{
			if (this->list[i] > this->list[i + 1])
			{
				std::swap(this->list[i], this->list[i + 1]);
				ok = 1;
			}
		}
	} while (ok == 1);
	else
	{
		do
		{
			ok = 0;
			for (int i = 0; i < this->number_elements - 1; i++)
			{
				if (this->list[i] < this->list[i + 1])
				{
					std::swap(this->list[i], this->list[i + 1]);
					ok = 1;
				}
			}
		} while (ok == 1);

	}
}

int Sort::Partition(int* list, int low, int high, bool ascendent) 
{
	int pivot = list[high];
	int i = low - 1;
	if (ascendent)
	{
		for (int j = low; j <= high; j++)
		{
			if (list[j] < pivot)
			{
				i++;
				std :: swap(list[i],list[j]);
			}
		}
	}
	else
	{
		for (int j = low; j <= high; j++)
		{
			if (list[j] > pivot)
			{
				i++;
				std::swap(list[i], list[j]);
			}
		}
	}
	std::swap(list[i + 1], list[high]);
	return (i + 1);
}

void Sort::QuickSort(int low, int high, bool ascendent)
{
	if (low < high)
	{
		int partition_index = Partition(this->list, low, high, ascendent);
		QuickSort(low, partition_index - 1, ascendent);
		QuickSort(partition_index + 1, high, ascendent);
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->number_elements; i++)
		printf("%d ", this->list[i]);
}


