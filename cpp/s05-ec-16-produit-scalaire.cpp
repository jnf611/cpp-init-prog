/*s04e16
Exercice 16 : produit scalaire (tableaux dynamiques, niveau 1)
Cet exercice correspond à l'exercice n°18 (pages 55 et 218) de l'ouvrage C++ par la pratique (3e édition, PPUR).
Écrivez un programme scalaire.cc qui calcule le produit scalaire de deux vecteurs, implémenté au moyen de tableaux dynamiques.

Votre programme devra utiliser (entre autres) les éléments suivants :

deux variables de type tableau dynamique de réels ;
une fonction qui calcule le produit scalaire : double scalaire(vector<double> u, vector<double> v);
Méthode :

demander à l'utilisateur d'entrer n, la taille effective des vecteurs.
vérifier que n est compris entre 1 et N_MAX (et demander à l'utilisateur d'entrer à nouveau une valeur tant que ce n'est pas le cas).
demander à l'utilisateur les composantes (v1 0... v1n-1 , v2 0 ... v2n-1) des vecteurs v1 et v2.
appeler la fonction scalaire(...) pour calculer le produit scalaire de v1 et v2.
afficher le résultat.
Rappel :
Le produit scalaire de a par b est: a.b = a 1*b1 + a2*b2 + ... + a n*bn

Exemple: a = (5, 3, -1)   b = (2, 1, 2)    a.b = 11
*/

#include <iostream>
#include <vector>
#include "get_ui.hpp"
using namespace std;

const int N_MAX = 3;

double scalaire(const vector<double>& u, const vector<double>& v)
{
	double s = 0.0;

	for (size_t i = 0; i < u.size(); ++i)
	{
		s += u[i]*v[i];
	}

	return s;
}

int main()
{
	int n = get_ui_int(0, N_MAX);
	vector<double> u = get_ui_vector_double(n, "u");
	vector<double> v = get_ui_vector_double(n, "v");

	double s = scalaire(u, v);
	cout << "s = " << s << endl;
}
