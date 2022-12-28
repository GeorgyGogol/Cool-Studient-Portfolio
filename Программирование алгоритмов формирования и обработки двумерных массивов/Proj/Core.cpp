#include "Core.h"

#include <cstdlib>

int Core::GetRandom(int min, int max)
{
	return min + rand() % max;
}

Core::cMatrix::cMatrix(int width, int height)
{
	if (width < 0 || height < 0) throw "Error create Massive! Width or Height is uncorrect (<0)!";
	Width = width;
	Height = height;

	Mas = new int*[Height];
	for (int j = 0; j < Height; j++)
	{
		Mas[j] = new int[Width];
	}
}

Core::cMatrix::cMatrix(int side)
{
	if (side < 0) throw "Error create Massive! Side is uncorrect (<0)!";
	Width = side;
	Height = side;

	Mas = new int*[Height];
	for (int j = 0; j < Height; j++)
	{
		Mas[j] = new int[Width];
	}
}

Core::cMatrix::~cMatrix()
{
	for (int j = 0; j < Height; j++)
	{
		delete[] Mas[j];
	}
	delete[] Mas;
}

int Core::cMatrix::get(int x, int y) const
{
	if (x < 0 || x >= Width) throw "cMatrix::get() x is out Width!";
	if (y < 0 || y >= Height) throw "cMatrix::get() y is out Heigth!";
	return Mas[y][x];
}

void Core::cMatrix::set(int x, int y, int num)
{
	if (x < 0 || x >= Width) throw "cMatrix::set() x is out Width!";
	if (y < 0 || y >= Height) throw "cMatrix::set() y is out Heigth!";
	Mas[y][x] = num;
	return;
}

int Core::cMatrix::get_productRow(int row) const
{
	if (row < 0 || row >= Height) throw "cMatrix::get_productRow Row out Height!";

	int out = 1;
	for (int i = 0; i < Width; i++) out *= Mas[row][i];
	return out;
}

