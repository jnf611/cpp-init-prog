/*Écrivez un programme age.cc qui :

    demande son âge à l'utilisateur ;
    lit la réponse de l'utilisateur et l'enregistre dans une variable age de type entier ;
    calcule l'année de naissance (à un an près) de l'utilisateur et l'enregistre dans la variable annee de type entier ;
    affiche l'année de naissance ainsi calculée.
*/

#include <stdlib.h>
#include <stdio.h>

int main ()
{
	const int year =2016;
	int age = 0;
	printf("what your age ? ");
	scanf("%d", &age);
	
	int birthDate = year - age;
	printf("your are born in %d", birthDate);
	
	return 0;
}
