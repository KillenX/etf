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
	input.open(argv[1]);
	out.open(argv[2]);
	

	cout << "Unesite rotacioni kljuc: ";
	cin >> n;
	Rotacija toCode(1,n);
	
	while (input.good())
	{
		input.getline(priv,99);
		out << toCode(priv)<<"\n";
	}
	in.close();
	out.close();
	cin.ignore();
	cin.get();
	return 0;
}