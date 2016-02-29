/* semaine 04 ec 13

Les nombres de Fibonnaci sont définis par la suite :

    F(0) = 0
    F(1) = 1
    F(n) = F(n-1)+ F(n-2) 	avec n>1

Le but de cet exercice est d'écrire un programme qui calcule la valeur de F(n) selon la définition récursive précédente.

Dans le fichier fibonacci.cc, prototypez puis définissez la fonction

    int Fibonacci(int n)

qui calcule la valeur de F(n) de manière récursive (cette fonction devra donc faire appel à elle-même) sans utiliser de structure de boucle (for, while, etc...) et sans aucune variable locale.

Pour comparaison, voici une manière itérative (i.e. non récursive) de calculer les n premier termes de la suite :

Note : la méthode récursive est coûteuse en temps de calcul, ne la lancez pas pour des nombres trop élevés (disons supérieurs à 40).
*/

#include <iostream>
#include "get_ui.hpp"
using namespace std;

const int max_recursive_fibonnaci = 40;

int FibonacciIteratif(int n)
{
	int Fn(0);    // stocke F(i)  , initialisé par F(0)
	int Fn_1(Fn); // stocke F(i-1), initialisé par F(0)
	int Fn_2(1);  // stocke F(i-2), initialisé par F(-1)

	if (n > 0)
		for (int i(1); i <= n; ++i) {
			Fn   = Fn_1 + Fn_2;    // pour n>=1 on calcule F(n)=F(n-1)+F(n-2)
			Fn_2 = Fn_1;           // et on decale...
			Fn_1 = Fn;
		}

	return Fn;
}

int FibonacciRecursive(int n)
{
	int Fn = 0;

	if (n == 0)
	{
		Fn = 0;
	}
	else if (n == 1)
	{
		Fn = 1;
	}
	else
	{
		Fn = FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
	}

	return Fn;
}

int main()
{
	do
	{
		int n = get_ui_int(0, max_recursive_fibonnaci);
		int n_iterative = FibonacciIteratif(n);
		cout << "Iterative method :" << endl << "F(" << n << ") = " << n_iterative << endl;
		int n_recursive = FibonacciRecursive(n);
		cout << "Recursive method :" << endl << "F(" << n << ") = " << n_recursive << endl;
	}
	while(get_ui_continue());

	return 0;
}
