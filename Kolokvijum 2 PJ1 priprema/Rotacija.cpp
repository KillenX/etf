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
	string out=str;
	if (mod)
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
			{
				out[i] = ((str[i] - 0x41 + n) % 26 + 0x41);
			}
			else if (islower(str[i]))
			{
				out[i] = ((str[i] - 0x61 + n) % 26 + 0x61);
			}
			else
				out[i] = str[i];
		}
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			if (isupper(str[i]))
			{
				out[i] = ((str[i] - 0x41 +26- n) % 26 + 0x41);
			}
			else if (islower(str[i]))
			{
				out[i] = ((str[i] - 0x61 +26- n) % 26 + 0x61);
			}
			else
				out[i] = str[i];
		}
	}
	
		return out;
	
}

Rotacija::~Rotacija(){}




