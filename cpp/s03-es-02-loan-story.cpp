/***  Semaine 03 Exercice supplémentaire 02
Une histoire de prêt (niveau 2)
Cet exercice correspond à l'exercice n°8 (pages 22 et 204) de l'ouvrage C++ par
la pratique (3e édition, PPUR).
L'objectif de cet exercice est de résoudre le problème suivant :
Une banque fait un prêt à une personne X pour un montant total de S0 euros
à une personne X.
Cette personne rembourse chaque mois un montant fixe r et paye (en plus) un
intérêt variable i = ir * S, où ir est le taux d'intérêt mensuel (fixe) et S la
somme restant à rembourser (avant déduction du remboursement mensuel).

Le but est de déterminer la somme des intérêts encaissés par la banque une fois
le prêt remboursé.

Écrivez pour cela le programme pret.cc qui calcule la somme des intérêts
encaissés et la durée en mois du remboursement, puis qui affiche ces
informations à l'écran.

Le programme doit en outre demander à l'utilisateur les valeurs S0 (strictement
positif), r (strictement positif) et ir (compris strictement entre 0 et 1) et
s'assurer de leur validité.

Testez votre programme avec les valeurs suivantes : S0=30000, r=1200, ir=0.01
(i.e. 1%). La somme des intérêts encaissés (sur 25 mois) est alors de 3900
euros.*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double S0 = 30000; // montant du pret initial
	double r  = 1200.0;  // remboursement par mois
	double ir = 0.01;    // taux d'interet mensuel
	// we skip part about user input and check
	
	int nb_mois = S0/r;
	if (nb_mois*r < S0)
	{
		nb_mois++;
	}
	double somme_i = 0.0; // somme des intérêts
	double S = S0; // somme restant à rembourser
	cout << "le remboursement s'étale sur " << nb_mois << " mois." << endl;
	for (int n = 0; n < nb_mois; ++n)
	{
		double i = ir*S;
		somme_i += i;
		S -= min(r, S);
	}
	cout << "la somme des intérêts versés est de " << somme_i << " euros." << endl;
	
	
	return 0;
}
