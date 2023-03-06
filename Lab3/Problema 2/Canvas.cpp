#include "Canvas.h"
#include <iostream>
#define _CTR_SECURE_NO_WARNINGS

Canvas::Canvas(int width, int height) :width(width), height(height)
{
	this->matrix = (char**)malloc(this->height * sizeof(char*));
	for (int i = 0; i < this->width; i++)
	{
		this->matrix[i] = (char*)(malloc(this->width * sizeof(char)));
		memset(this->matrix[i], ' ', this->width);
	}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if(x>=0 && x<this->height && y>=0 && y<this->width)
	this->matrix[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{

	int dx = abs(x2 - x1);
	int sx = x1 < x2 ? 1 : -1;
	int dy = -abs(y2 - y1);
	int sy = y1 < y2 ? 1 : -1;
	int error = dx + dy;

	while (true)
	{
		if (x1 >= 0 && x1 < this->height && x2 >= 0 && x2 < this->height && y1 >= 0 && y1 < this->width && y2 >= 0 && y2 < this->width)
		{
			this->SetPoint(x1, y1, ch);
			if (x1 == x2 && y1 == y2)
				break;
			int e2 = 2 * error;
			if (e2 >= dy)
			{
				if (x2 == x1)
					break;
				error += dy;
				x1 += sx;
			}
			if (e2 <= dx)
			{
				if (y1 == y2)
					break;
				error += dx;
				y1 += sy;
			}
		}
		else break;
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
				if (i >= 0 && i < this->height && j >= 0 && j < this->width)
				this->matrix[i][j] = ch;

	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray )
				if (i >= 0 && i < this->height && j >= 0 && j < this->width)
				this->matrix[i][j] = ch;
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	this->DrawLine(top, left, top, right, ch);
	this->DrawLine(top, left, bottom, left, ch);
	this->DrawLine(bottom, left, bottom, right,ch);
	this->DrawLine(bottom, right, top, right,ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; ++i)
		for (int j = left; j <= right; ++j)
			if (i >= 0 && i < this->height && j >= 0 && j < this->width)
				this->matrix[i][j] = ch;
}



void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf(" \n");
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			this->matrix[i][j] = ' ';
		}
	
	}
}