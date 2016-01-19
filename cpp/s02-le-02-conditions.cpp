/*
Cours S02 - 2. Conditions

Multiplication d'un boolean et affichage
*/
#include <iostream>
using namespace std;

int main()
{
	int a(5);
	int b(2);
	int c(5);
	bool d(true);
	bool e(false);
	
	cout << "(a == b) = " << (a == b) << endl;
	cout << "(a == c) = " << (a == c) << endl;
	// overload for bool<< make implicit cast to int ?
	cout << "d = " << d << " and then (bool)d = " << (bool)d << endl;
	
	// guessing that there is a cast
	cout << "2 * (a == b) = " << 2 * (a == b) << endl;
	cout << "2 * (a == c) = " << 2 * (a == c) << endl;
	
	e = a;
	cout << "e = " << e << endl;
	
	return 0;
}
