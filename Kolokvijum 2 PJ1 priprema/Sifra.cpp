#include "Sifra.h"



Sifra::Sifra(int xmod):mod(xmod)
{}
ostream& operator<<(ostream& str, Sifra& other)
{
	other.print(str);
	return str;
}

Sifra::~Sifra()
{
}
