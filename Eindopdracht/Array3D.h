#pragma once
#include "Kamer.h"
class Array3D
{
public:
	Array3D(size_t, size_t, size_t);
	Array3D();
	~Array3D();

	void voegKamerToeAanArray(Kamer* input, size_t x, size_t y, size_t z);
	Kamer * getKamer(size_t x, size_t y, size_t z) const;
	size_t Index(size_t x, size_t y, size_t z) const;

private:
	size_t x_size;
	size_t y_size;
	size_t z_size;

	Kamer* kamerArray[10000];
};