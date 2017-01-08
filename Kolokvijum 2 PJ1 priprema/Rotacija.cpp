#include "Rotacija.h"
#include <cctype>

Rotacija::Rotacija(int xmod, int xn) : Sifra(xmod), n(xn)
{
}

void Rotacija::print(ostream & str)
{
	str << "Rotacija, kljuc je: " << n;
}

string Rotacija::operator()(string str)
{
	const char* in = str.c_str();
	size_t lim = str.length();
	std::cout << str[1];
	string out;
	if (mod)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isupper(in[i]))
			{
				out[i] = ((in[i] - 0x40 + mod) % 28 + 0x40);
			}
			else if (isupper(in[i]))
			{
				out[i] = ((in[i] - 0x60 + mod) % 28 + 0x60);
			}
			else
				out[i] = in[i];
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
			{
				out[i] = ((str[i] - 0x40 +27- mod) % 28 + 0x40);
			}
			else if (isupper(str[i]))
			{
				out[i] = ((str[i] - 0x60 +27- mod) % 28 + 0x60);
			}
			else
				out[i] = str[i];
		}
	}
	mod = !mod;
		return out;
	
}

Rotacija::~Rotacija(){}




