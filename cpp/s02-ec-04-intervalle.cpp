/* Semaine 02 exercice 04
Soit I l'intervalle [-1,1[ dans l'ensemble des réels.

Écrivez le programme intervalle.cc qui :

    demande à l'utilisateur d'entrer un réel ;
    enregistre la réponse de l'utilisateur dans une variable x de type réel ;
    teste l'appartenance de x à l'ensemble I et affiche le message « x appartient à I » si c'est le cas, et « x n'appartient pas à I » dans le cas contraire.

Testez votre programme en l'exécutant plusieurs fois de suite en donnant successivement à x les valeurs -2.5, -1, 0.5, 1, et 1.5.


*/

#include <iostream>
using namespace std;

static const double my_lower_bound = -1.0;
static const double my_higher_bound = 1;

void belong_to_intervalle(double x)
{
	if ((x >= my_lower_bound) && (x < my_higher_bound))
	{
		cout << x << " belongs to ";
	}
	else
	{
		cout << x << " does not belong to ";
	}
	cout << "[" << my_lower_bound << ", " << my_higher_bound << "]" << endl;
}

int main()
{
	double x = 0.0;

	cout << "Enter a floating number " << endl;
	cin >> x;

	belong_to_intervalle(x);
	belong_to_intervalle(-2.5);
	belong_to_intervalle(-1.0);
	belong_to_intervalle(-0.5);
	belong_to_intervalle(0.0);
	belong_to_intervalle(1.0);
	belong_to_intervalle(1.5);

	return 0;
}
