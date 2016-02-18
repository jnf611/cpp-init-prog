/* week 03 ec 09

On se demande maintenant combien de rebonds fait cette balle avant que la
hauteur à laquelle elle rebondit soit plus petite que (ou égale à) une hauteur
donnée h_fin.

Écrivez le programme rebonds2.cc qui affiche le nombre de rebonds à l'écran.

Il devra utiliser une boucle do...while, et demander à l'utilisateur d'entrer les valeurs de :

H0 (hauteur initiale, contrainte : H0 > 0),
eps (coefficient de rebond, contrainte 0 <= eps < 1)
h_fin (hauteur finale désirée, contrainte : 0 < h_fin < H0).
Essayez les valeurs H0=10, eps=0.9, h_fin=2. Vous devriez obtenir 8 rebonds. */



#include <iostream>
#include <cmath>
using namespace std;

const double g = 9.81;

void get_user_input(double* h0, double* eps, double *hFin)
{
	do
	{
		cout << "Enter initial height h0: ";
		cin >> *h0;
	}
	while (*h0 <= 0);
	
	do
	{
		cout << "Enter rebond coeff eps: ";
		cin >> *eps;
	}
	while ((*eps < 0.0) || (*eps >= 1.0));
	
	do
	{
		cout << "Enter final height: ";
		cin >> *hFin;
	}
	while (*hFin <= 0);
}

int compute_nbr(double h0, double eps, double hFin)
{
	double hBefore;
	double hAfter;
	double vBefore;
	double vAfter;
	int nbr = 0;
	
	hAfter = h0;
	while (hAfter > hFin)
	{
		hBefore = hAfter;
		vBefore = sqrt(2*g*hBefore);
		vAfter = vBefore*eps;
		hAfter = vAfter*vAfter/(2*g);
		++nbr;
	}
	
	return nbr;
}

int main()
{
	int cNbr = compute_nbr(10, 0.9, 2);
	const int expectedNbr = 8;
	if (cNbr != expectedNbr)
	{
		cout << "ERROR: computed result nbr = " << cNbr 
			<< " different from expected nbr = " << expectedNbr << endl;
		return 1;
	}

	double h0 = 0.0;
	double eps = 0.0;
	double hFin = 0.0;
	
	get_user_input(&h0, &eps, &hFin);
	int nbr = compute_nbr(h0, eps, hFin);
		
	cout << "After " << nbr << " rebonds starting initially at h0 = "
		<< h0 << "m, heigth is now inferior to " << hFin << "m" << endl;
	
	return 0;
}
