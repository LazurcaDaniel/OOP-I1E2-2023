#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdarg.h>


int main()
{
	//1
	Sort x1(10, 0, 15);
	x1.Print();
	x1.QuickSort(0,x1.GetElementsCount()-1,1);
	printf("\n");
	x1.Print();
	printf("\n------------------\n");
	//2
	Sort x2;
	x2.Print();
	x2.BubbleSort(0);
	printf("\n");
	x2.Print();
	printf("\n------------------\n");
	//3
	int arr[10] = { 1,9,3,3,2,5,7,4,5,10 };
	Sort x3(arr,10);
	x3.Print();
	x3.QuickSort(0, x3.GetElementsCount() - 1, 0);
	printf("\n");
	x3.Print();
	printf("\n------------------\n");
	
	//4
	Sort x4(10, 3,5,7,2,3,11,4,6,5,7);
	x4.Print();
	x4.InsertSort(0);
	printf("\n");
	x4.Print();
	printf("\n------------------\n");
	//5
	char arr2[100] = "1,54,26,436,75,37,35,29,4,23";
	Sort x5(arr2,10);
	x5.Print();
	x5.BubbleSort(1);
	printf("\n");
	x5.Print();
}