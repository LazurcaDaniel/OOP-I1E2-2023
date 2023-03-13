#pragma once
#include <iostream>
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>
class Sort
{
	int number_elements;
	int* list;
public:

	Sort(int nr_elements,int min, int max);
	Sort(int tmp[], int nr_elements);
	Sort();
	Sort(int nr_elements, ...);
	Sort(char numbers[], int nr_elements);

	void QuickSort(int low, int high, bool ascendent);
	int Partition(int* list, int low, int high, bool ascendent);
	void InsertSort(bool ascendent);
	void BubbleSort(bool ascendent);
	int GetElementsCount();
	int GetElementsIndex(int index);
	void Print();
};

