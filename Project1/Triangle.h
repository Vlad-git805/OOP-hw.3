#pragma once
#include <iostream>

using namespace std;

class Triangl
{
private:
	int width;
	int height;
	static int countOfTriangle;
	static int sumOfArea;
public:
	Triangl()
	{
		width = 0;
		height = 0;
		countOfTriangle++;
	}
	Triangl(int _width, int _height)
	{
		width = _width;
		height = _height;
		countOfTriangle++;
	}
	void Print() const;
	float GetArea();
	float GetPerimeter();
	void SetWidth(int _width);
	void SetHeight(int _height);

	static int GetCountOfTriangl();
	static int GetsumOfArea();
};

