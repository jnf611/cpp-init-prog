#include <iostream>
using namespace std;

int main()
{
	int a(5);
	int b(2);
	double c(a/b);
	
	cout << a << " / " << b << " = " << c << " or " << (double)a/b << endl;
	
	return 0;
}

