#include <iostream>
#include "Rotacija.h"
using std::cout;
using std::cin;

int main()
{
	Rotacija rot(1, 3);
	string test = "PROGRAMSKI JEZICI 1";
	cout << rot;
	cout << rot(test);


	cin.ignore();
	cin.get();
	return 0;
}