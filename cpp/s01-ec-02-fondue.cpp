/*Le but de cet exercice est d'écrire un programme qui permet d'adapter automatiquement, en fonction du nombre de convives, les quantités d'ingrédients nécessaires à la confection d'une fondue fribourgeoise (au pur Vacherin fribourgeois ; une recette typiquement suisse, mais à ne pas confondre avec la fondue « moitié-moitié », suisse également ;-) ).

Ecrivez un programme fondue.cc qui :

    déclare une constante BASE, initialisée à 4, et qui indique le nombre de personnes pour laquelle est conçue la recette de base ;

    déclare une variable fromage, initialisée à 800.0, qui donne la quantité de fromage en grammes nécessaire pour BASE personnes (du « Vacherin fribourgeois » en l'occurrence !) ;

    déclare une variable eau, initialisée à 2.0, qui donne la quantité d'eau en décilitres nécessaire pour BASE personnes ;

    déclare une variable ail, initialisée à 2.0, qui donne le nombre de gousses d'ail nécessaires pour BASE personnes (on choisit le type double car on veut pouvoir utiliser des moitiés de gousses par exemple) ;

    déclare une variable pain, initialisée à 400.0, qui donne la quantité de pain en grammes nécessaire pour BASE personnes ;

    demande à l'utilisateur d'introduire le nombre de convives pour lequel on veut préparer la recette ;

    lit la réponse de l'utilisateur et l'enregistre dans une variable nbConvives de type entier ;

    adapte les quantités de chaque ingrédient en faisant une règle de trois (nouvelle_quantite = quantite_de_base * nb_convives / BASE ) ;

    et affiche la recette pour le nombre de convives voulus selon l'exemple ci-dessous.
*/

#include <iostream>
using namespace std;

int main ()
{
	const int BASE = 4;
	const double fromage = 800.0;
	const double water   = 2.0;
	const double garlic  = 2.0;
	const double bread   = 400.0;
	
	int nbPeople   = 0;
	cout << "how much people will attend the \"fondue\"? ";
	cin >> nbPeople;
	
	if (nbPeople > 0)
	{
		cout << "you will need :" << endl
			<< "fromage: " << (fromage * nbPeople) / BASE << "g" << endl
			<< "water:   "   << (water * nbPeople) / BASE << "dl" << endl
			<< "garlic:  "  << (garlic * nbPeople) / BASE << "gousses" << endl
			<< "bread:   "   << (bread * nbPeople) / BASE << "g" << endl;
			
		cout << "fromage * nbPeople / BASE = " << fromage * nbPeople / BASE << endl;
		cout << "(fromage * nbPeople) / BASE = " << (fromage * nbPeople) / BASE << endl; 
		cout << "(nbPeople * fromage) / BASE = " << (nbPeople * fromage) / BASE << endl;
		cout << "nbPeople * fromage / BASE = " << nbPeople * fromage / BASE << endl;
		cout << "nbPeople / BASE * fromage = " << nbPeople / BASE * fromage << endl;
		cout << "(nbPeople / BASE) * fromage = " << (nbPeople / BASE) * fromage << endl;
	}
	
	return 0;
}
