#include <iostream>
#include <fstream>

#include "Rotacija.h"
#include "Array.h"
using std::cout;
using std::cin;
using std::ifstream;
using std::ofstream;

int main(int argc,char** argv)
{
	if (argc < 3) return 0;
	ifstream input;
	ofstream out;
	int n;
	char priv[100];

	cout << "unesite rotacioni kljuc: ";
	cin >> n;
	Rotacija toCode(1,n),toText(0,n);
	input.open(argv[1]);
	out.open(argv[2]);
	while (input.good())
	{
		input.getline(priv,99);
		out << toCode(priv)<<"\n";
	}

	cin.ignore();
	cin.get();
	return 0;
}