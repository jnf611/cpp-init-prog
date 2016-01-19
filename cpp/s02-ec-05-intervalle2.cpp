/* Semaine 02 exercice 05
Reprenez pour cela le problème de l'exercice précédent avec : 
et en utilisant uniquement les opérateurs relationnels < et ==.
Tous les opérateurs logiques sont, par contre, autorisés.

Notez que, en logique élémentaire, « non (A et B) » peut aussi s'écrire « (non A) ou (non B) ».

Testez avec les valeurs .

*/

#include <iostream>
using namespace std;

void belong_to_intervalle(double x)
{
	// I = [2,3[ U ]0,1] U [-10,-2]

	if ((((-10.0 == x) || (-10.0 < x)) && ((x < -2.0) || (x == -2.0))) ||
		((0.0 < x) && ((x < 1.0) || (x == 1.0))) ||
		(((2.0 < x) || (2.0 == x)) && (x < 3.0)))
	{
		cout << x << " belongs to I" << endl;
	}
	else
	{
		cout << x << " does not belong to I" << endl;
	}
}

int main()
{
	double x = 0.0;

	cout << "Enter a floating number " << endl;
	cin >> x;

	belong_to_intervalle(x);

	double tableEntries[] = {-20.0, -10.0, -2.0, -1.0, 0.0, 1.0, 1.5, 2.0, 3.0, 4.0};
	unsigned n = sizeof(tableEntries)/sizeof(tableEntries[0]);
	for (unsigned int i = 0; i < n; ++i)
	{
		belong_to_intervalle(tableEntries[i]);
	}

	return 0;
}
