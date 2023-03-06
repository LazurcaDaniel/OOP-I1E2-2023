#include "Canvas.h"
#include <iostream>


int main()
{
	Canvas x(40, 40);
	x.FillCircle(10, 10, 3, 'X');
	x.DrawCircle(20, 30, 4, 'O');
	x.DrawRect(1, 1, 5, 5, '-');
	x.FillRect(2, 2, 4, 4, 'D');
	x.DrawLine(0,0, 35, 20, '*'); //this tests SetPoint as well
	x.DrawLine(35, 7, 5, 20, '*');
		
	x.Print();
	x.Clear();
	std :: cout << "------------------------------------" << '\n';
	x.Print();
	
}