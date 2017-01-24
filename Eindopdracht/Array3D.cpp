#include "Array3D.h"

Array3D::Array3D(size_t x_length, size_t y_length, size_t z_length) : x_size{x_length}, y_size{ y_length }, z_size{ z_length }
{
	int totaal = (x_length * y_length * z_length);
	
	for (int x = 0; x < totaal; x++) {
		kamerArray[x] = nullptr;
	}

}

Array3D::Array3D()
{
}

Array3D::~Array3D()
{
	delete[] kamerArray;
}

void Array3D::voegKamerToeAanArray(Kamer * input, size_t x, size_t y, size_t z)
{
	size_t index = Index(x, y, z);
	kamerArray[index] = input;
}

Kamer* Array3D::getKamer(size_t x, size_t y, size_t z) const {
	size_t index = Index(x, y, z);
	return kamerArray[index];
}


size_t Array3D::Index(size_t x, size_t y, size_t z) const {
	{ return x_size * y_size * z + x_size * y + x; }
	//return x_size * y_size * z + x_size * y + x;
}