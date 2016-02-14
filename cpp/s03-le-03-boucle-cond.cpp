/*semaine 03 lecon boucle conditionnelle*/

#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	int i = 0;
	
	do
	{
		cout << "i vaut " << i << endl;
		++i;
	}
	while (i < 1);
	
	do
	{
		cout << "i vaut " << i << endl;
		++i;
	}
	while (i < 10) /*cout << "does this compile" << endl" NO*/;
	
	return 0;
}
