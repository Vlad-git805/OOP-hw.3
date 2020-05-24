#include "Triangle.h"

int Triangl::countOfTriangle = 0;
int Triangl::sumOfArea = 0;

void Triangl::Print() const
{
	cout << "Width: " << width << endl;
	cout << "Height: " << height << endl;
}

float Triangl::GetArea()
{
	float area = 0;
	area = ((0.5 * width) * height);
	sumOfArea += area;
	return area;
}

float Triangl::GetPerimeter()
{
	float perimeter = 0;
	float storona = 0;
	storona = pow(height, 2) + pow(width / 2, 2);
	storona = sqrt(storona);
	perimeter = storona + storona + width;
	return perimeter;
}

void Triangl::SetWidth(int _width)
{
	if (_width <= 0)
		return;
	width = _width;
}

void Triangl::SetHeight(int _height)
{
	if (_height <= 0)
		return;
	height = _height;
}

int Triangl::GetCountOfTriangl()
{
	return countOfTriangle;
}
int Triangl::GetsumOfArea()
{
	return sumOfArea;
}
