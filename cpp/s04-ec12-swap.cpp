/*
* semaine 04 ex conseill� 12
* swap
*/

#include <iostream>
using namespace std;

void echange(int& i, int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

int main()
{
    int i(10);
    int j(55);

    cout << "Avant: i=" << i << " et j=" << j << endl;
    echange(i,j);
    cout << "Apr�s: i=" << i << " et j=" << j << endl;

    return 0;
}
