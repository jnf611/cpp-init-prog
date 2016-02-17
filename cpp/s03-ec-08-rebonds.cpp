/* Semaine 4 Exercice 8
L'objectif de cet exercice est de résoudre le problème suivant :

Lorsqu'une balle tombe d'une hauteur initiale h, sa vitesse à l'arrivée au sol
est v=2∗h∗g−−−−−−√.
Immédiatement après le rebond, sa vitesse est v1=eps∗v
(où eps est une constante et v la vitesse avant le rebond).
Elle remonte alors à la hauteur h=v122g.

Le but est d'écrire un programme (rebonds1.cc) qui calcule la hauteur à laquelle
la balle remonte après un nombre nbr de rebonds.
Méthode :

On veut résoudre ce problème, non pas du point de vue formel (équations)
mais par simulation du système physique (la balle).

Utilisez une itération for et des variables 
- v, v1, (les vitesses avant et après le rebond),
- et h, h1 (les hauteurs au début de la chute et à la fin de la remontée).

Tâches :

Écrivez le programme rebonds1.cc qui affiche la hauteur après le nombre de
rebonds spécifié.

Votre programme devra utiliser la constante g, de valeur 9,81 et demander à
l'utilisateur d'entrer les valeurs de:

    H0 (hauteur initiale, contrainte : H0 > 0),
    eps (coefficient de rebond, contrainte 0 <= eps < 1)
    nbr (nombre de rebonds, contrainte : 0 <= NBR).

Essayez les valeurs H0 = 25, eps = 0.9, NBR = 10.
La hauteur obtenue devrait être environ 3.04.
* 
* */

#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

void get_input(double* h0, double* eps, int* nbr)
{
	do
	{
		cout << "Enter initial height h0:";
		cin >> *h0;
	}
	while (*h0 <= 0);
	
	do
	{
		cout << "Enter rebond coeff eps:";
		cin >> *eps;
	}
	while ((*eps < 0.0) || (*eps >= 1.0));
	
	do
	{
		cout << "Enter nb rebond";
		cin >> *nbr;
	}
	while (*nbr <= 0);
}

double compute_heigth(double h0, double eps, int nbr)
{
	double hBefore;
	double hAfter;
	double vBefore;
	double vAfter;
	
	hAfter = h0;
	for (int i = 0; i < nbr; ++i)
	{
		hBefore = hAfter;
		vBefore = sqrt(2*g*hBefore);
		vAfter = vBefore*eps;
		hAfter = vAfter*vAfter/(2*g);
	}
	
	return hAfter;
}

int main()
{
	double h = compute_heigth(25, 0.9, 10);
	const double expectedHeight = 3.04;
	if ((h < expectedHeight - 0.01) || (h > expectedHeight + 0.01))
	{
		cout << "ERROR: unexpected result h = " << h 
			<< " different form expected height = " << expectedHeight << endl;
		return 1;
	}

	double h0 = 0.0;
	double eps = 0.0;
	int nbr = 0;
		
	get_input(&h0, &eps, &nbr);
	double hAfter = compute_heigth(h0, eps, nbr);
		
	cout << "heigh after " << nbr << " rebonds starting initially at h0 = "
		<< h0 << " is h = " << hAfter;
	
	return 0;
}
