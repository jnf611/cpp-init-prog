#include <iostream>
using namespace std;

int main()
{
	int n;
	int n2;
	
	cout << "enter a value for n" << endl;
	cin >> n;// rm: if a char or a string is input, n is set to 0
	n2 = n * n;
	cout << "square of " << n << " is " << n2 << endl;
	
	return 0;
}

