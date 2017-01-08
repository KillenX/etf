#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;

class Sifra
{
protected:
	int mod;
public:
	friend ostream& operator<<(ostream& str, Sifra& other );
	Sifra(int mod);
	virtual string operator()(string poruka)=0;
	virtual void print(ostream&)=0;
	virtual ~Sifra();
};

