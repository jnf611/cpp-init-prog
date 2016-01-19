#include <iostream>
using namespace std;

int main()
{
	int n(4);
	double d(1.0);
	
	cout << "n = " << n << " and d = " << d << endl;
	
	const double pi(3.14);
	cout << "pi = " << pi << endl;
	
	//pi = 3.10; // won't compile, pi is const (read only variable)
	
	return 0;
}

