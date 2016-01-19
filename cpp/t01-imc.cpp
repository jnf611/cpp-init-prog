/*
Nous voulons écrire un programme permettant de calculer l'IMC (indice de
masse corporelle) d'une personne. L'IMC se calcule à partir du poids et
de la taille suivant la formule : poids (en kg) divisé par le carré de
sa taille (en m).
*/

#include <iostream>
using namespace std;

const char* qualificatif_imc(double imc)
{
	if (imc < 20.0)
		return "très maigre";
	else if (imc < 25.0)
		return "maigre";
	else
		return "gros";
}

double imc(double masse, double taille)
{
	return (masse / taille / taille);
}

int main()
{
	double masse;
	double taille;
	
	cout << "Masse (kg) : ";
	cin >> masse;
	cout << "Taille (m): ";
	cin >> taille;
	
	double valeur_imc = imc(masse, taille);
	cout << "Votre imc est de " << valeur_imc << endl;
	cout << "Vous êtes : " << qualificatif_imc(valeur_imc); 
	
	return 0;
}

