#include <iostream>
#include "Rotacija.h"
using std::cout;
using std::cin;

int main()
{
	Rotacija rot(1, 3);
	string test = "Srdjan Hajder";
	cout << rot<<std::endl;
	cout << rot(rot(test));


	cin.ignore();
	cin.get();
	return 0;
}