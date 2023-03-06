#include "Math.h"
#include <stdio.h>;
#include <cstring>;
#include <string>
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
	Math* x = nullptr;
	
	printf("%d \n", x->Add(4, 6));
	printf("%d \n", x->Add(8, 9, 3));
	printf("%g \n", x->Add(3.5, 8.1));
	printf("%g \n", x->Add(4.0, 6.3, 10.2));
	printf("%d \n", x->Mul(4, 6));
	printf("%d \n", x->Mul(8, 9, 3));
	printf("%g \n", x->Mul(3.5, 8.1));
	printf("%g \n", x->Mul(4.0, 6.3, 10.2));
	printf("%d \n", x->Add(5, 1, 2, 3, 4, 5));
	printf("%s", x->Add("432423", "5454"));

}