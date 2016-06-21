/* s6ec19
Exercice 19 : nombres complexes (structures, niveau 1)
Cet exercice correspond à l'exercice n°22 (pages 60 et 225) de l'ouvrage C++ par la pratique (3e édition, PPUR).

Le but de ce programme est d'effectuer les manipulations élémentaires sur les nombres complexes : addition, soustraction, multiplication et division.

Dans le fichier complexes.cc, définissez une structure Complexe représentant un nombre complexe comme deux double (forme cartésienne).

Ensuite, prototypez puis définissez une procédure affiche qui prend un nombre complexe en argument et l'affiche.

Dans le main(), déclarez et initialisez un nombre complexe. Affichez-le. Compilez et exécutez votre programme pour vérifier que tout fonctionne comme prévu jusqu'ici.

Prototypez puis définissez une fonction addition qui prend deux nombres complexes en argument et retourne leur somme.

Testez votre fonction dans le main().

Terminez l'exercice en écrivant puis testant les fonctions soustraction, multiplication et division.

Rappel : la multiplication de z=(x,y) par z'=(x',y') est le nombre complexe z*z'=(x*x'-y*y', x*y'+y*x').
la division de z=(x,y) par z'=(x',y') est le nombre complexe z/z'=((x*x'+y*y')/(x'*x'+y'*y'), (y*x'-x*y')/(x'*x'+y'*y')).
Exemple d'exécution

(1,0) + (0,1) = (1,1)
(0,1) * (0,1) = (-1,0)
(1,1) * (1,1) = (0,2)
(0,2) / (0,1) = (2,0)
(2,-3) / (1,1) = (-0.5,-2.5)
*/

#include <iostream>
using namespace std;

struct Complexe
{
	double x;
	double y;
};

const struct Complexe i = {0, 1};

string to_string(const Complexe& c)
{
	return "(" + to_string(c.x) + "," + to_string(c.y) + ")";
}

void display(const Complexe& c)
{
	cout << to_string(c) << endl;
}

Complexe add(Complexe a, const Complexe& b)
{
	a.x += b.x;
	a.y += b.y;

	return a;
}

Complexe substract(Complexe a, const Complexe& b)
{
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

Complexe multiply(Complexe a, const Complexe& b)
{
	double a_x = a.x;
	a.x = a_x*b.x - a.y*b.y;
	a.y = a_x*b.y + a.y*b.x;

	return a;
}

Complexe divide(Complexe a, const Complexe& b)
{
	double den = b.x*b.x + b.y*b.y;
	double a_x = a.x;
	a.x = (a_x*b.x + a.y*b.y) / den;
	a.y = (a.y*b.x - a_x*b.y) / den;

	return a;
}

int main()
{
	Complexe a = {1, 0};
	display(a);
	Complexe b; b.x = 2.0; b.y = 1.0;
	display(b);

	cout << to_string(a) << " + " << to_string(b) << " = "
		<< to_string(add(a, b)) << endl;
	cout << to_string(a) << " - " << to_string(b) << " = "
		<< to_string(substract(a, b)) << endl;
	cout << to_string(b) << " * " << to_string(i) << " = "
		<< to_string(multiply(b, i)) << endl;
	Complexe bi = multiply(b, i);
	cout << to_string(bi) << " / " << to_string(i) << " = "
		<< to_string(divide(bi, i)) << endl;

	return 0;
}
