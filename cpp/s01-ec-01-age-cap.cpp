/*Écrivez un programme age.cc qui :

    demande son âge à l'utilisateur ;
    lit la réponse de l'utilisateur et l'enregistre dans une variable age de type entier ;
    calcule l'année de naissance (à un an près) de l'utilisateur et l'enregistre dans la variable annee de type entier ;
    affiche l'année de naissance ainsi calculée.
*/

#include <iostream>
using namespace std;

int main ()
{
	const int year(2016);
	int age;
	cout << "what your age ? ";
	cin >> age;
	
	int birthDate(year - age);
	cout << "your are born in " << birthDate << endl;
	
	return 0;
}
