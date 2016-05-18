/*s04e15
*/

#include <iostream>
#include <vector>
using namespace std;

void display(const string& s, const vector<int>& v)
{
	cout << s << ": ";
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i] << ", ";
	}
	cout << endl;
}

/*
A : Quelles valeurs contient le tableau tab après l'exècution des lignes suivantes ? Expliquez.
int const taille(10);
vector<int> tab;
for (size_t i(0); i < taille; ++i) {
    tab.push_back(tab.size());
}
*/

void A()
{
	int const taille(10);
	vector<int> tab;
	for (size_t i(0); i < taille; ++i)
	{
		tab.push_back(tab.size());
	}

	display("tab of A", tab);
}

/*
B : Que fait la fonction f suivante ?
*/

void f(vector<int>& tab, vector<int>& tab2)
{
    for (size_t i(0); i < tab.size(); ++i) {
        tab2.push_back(tab[0]);
    }
}

int main()
{
	// A
	A();

	// B
	int tab_cinq[5] = {0, 1, 2, 3, 4};
	int tab_trois[3] = {11, 12, 13};
	vector<int> cinq(tab_cinq, tab_cinq+(sizeof(tab_cinq)/sizeof(tab_cinq[0])));
	vector<int> trois(tab_trois, tab_trois+(sizeof(tab_trois)/sizeof(tab_trois[0])));

	f(cinq, trois);
	display("cinq", cinq);
	display("trois", trois);

	return 0;
}
