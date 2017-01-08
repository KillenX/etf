#pragma once
#include "Sifra.h"
class Rotacija :
	public Sifra
{
	const int n;
public:
	Rotacija(int xmod,int xn);
	void print(ostream& str) override;
	string operator()(string str);

	~Rotacija();
};

