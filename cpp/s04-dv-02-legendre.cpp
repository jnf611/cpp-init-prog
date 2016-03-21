/* S04 DV02
 * Les mathématiciens supposent (Mais cela n'a pas encore été démontré à ce
 * jour ; c'est ce qu'on appelle la « conjecture de Legendre », d'après le
 * mathématicien français du 18e–19e siècle Adrien-Marie Legendre.) que pour
 * tout nombre entier n, il existe au moins un nombre premier compris entre n^2
 * et (n+1)^2. C'est ce que nous voulons vérifier à l'aide d'un programme.
 * 
 * Nous allons pour cela utiliser plusieurs sous-tâches (Il existe bien sûr
 * plusieurs autres solutions (d'autres algorithmes), comme par exemple stocker
 * en mémoire les résultats déjà acquis. Nous avons ici pris le parti de ne rien
 * stocker en mémoire, mais de refaire les calculs à chaque fois. Nous vous
 * demandons de respecter cette marche à suivre.) :
 * - savoir si un nombre donné est un nombre premier ;
 * - tester si un nombre entier donné n vérifie la propriété ci-dessus ;
 * - tester tous les nombres entiers compris entre deux bornes. 
 * 
 * 
 * Pour la première sous-tâche, nous vous demandons d'écrire une fonction
 * est_premier prenant en paramètre un int et retournant un booléen, « vrai » si
 * le nombre fourni en paramètre est un nombre premier et « faux » sinon.
 * 
 * Pour tester si un nombre x est premier, on peut procéder comme suit :
 * - tout nombre inférieur ou égal à 1 n'est pas premier ;
 * - 2 est premier ;
 * - tout autre nombre pair n'est pas premier ;
 * - pour tout autre nombre (forcément impair donc), on recherche un diviseur :
 * 		- faire une boucle de 3 à la racine carrée de ce nombre x (La racine
 * 		carrée de x s'écrit « sqrt(x) » en C++.) ;
 * 		- si le reste de la division entière de x par le nombre de la boucle
 * 		est nul, alors x n'est pas premier ;
 * 		- si à la fin de la boucle, tous les restes étaient non nuls, alors x
 * 		est premier ;
 * 		pour rappel, le reste de la division entière de x par y s'écrit :
 * 		« x % y » en C++.
 * 
 * 
 * Afin de tester si votre procédure est correcte, nous vous demandons de plus
 * d'écrire une fonction test_premiers prenant deux entiers en paramètres et
 * testant chaque entier compris entre ces deux bornes pour voir s'il est
 * premier. Cette fonction devra écrire à l'écran la liste des nombres premiers
 * trouvés en respectant strictement le format donné dans les exemples de
 * déroulement fournis plus loin.
 * 
 * Pour tester si un nombre entier donné n vérifie la propriété de la conjecture
 * de Legendre, nous vous demandons d'écrire une fonction legendre qui prend en
 * paramètre un int n et retourne un int. Cette fonction testera tous les
 * nombres compris entre n*n+1 et (n+1)*(n+1)-1 et s'arrêtera au premier nombre
 * premier rencontré, qu'elle retournera. Si, par contre, aucun nombre premier
 * n'a été trouvé entre ces deux bornes, la fonction retournera 0.
 * 
 * 
 * Enfin, la dernière fonction à fournir s'appelle test_legendre. Elle ne prend
 * aucun paramètre et ne retourne rien. Elle commence par demander à
 * l'utilisateur d'entrer un nombre en respectant strictement le format donné
 * dans les exemples de déroulement fournis plus loin. Tant que le nombre
 * entré par l'utilisateur est inférieur ou égal à 0, la fonction redemande un
 * nombre. Une fois ce premier nombre entré, elle demande un second nombre, qui
 * doit être supérieur ou égal au premier nombre entré (voir exemples de
 * déroulement plus bas).
 * 
 * Une fois que deux valeurs valides ont été fournies, la fonction effectue
 * enfin le test de la conjecture de Legendre sur tous les nombres compris entre
 * les deux nombres saisis. Si la conjecture est vérifiée, cette procédure
 * affiche le nombre testé suivi de «  : » suivi du premier nombre premier
 * trouvé (voir exemples de déroulement plus bas). Sinon, si jamais le nombre
 * testé ne vérifie pas la conjecture de Legendre, alors le programme doit
 * afficher « PAS TROUVÉ ! » (Et à vous la célébrité!).
 */
#include <iostream>
#include <cmath> // pour sqrt()
#include <cstring> // pour sqrt()
#include <stdlib.h> // pour sqrt(
#include "get_ui.hpp"
#include "my_string.hpp"
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
 
/*Teste si un nombre est premier*/
bool est_premier(int n)
{
	bool is_prime = true;

	if (n < 2)
	{
		is_prime = false;
	}
	else if (n > 2)
	{
		if (n%2 == 0)
		{
			is_prime = false;
		}
		else
		{
			int sqrt_n = sqrt(n);
			for (int i = 3; i <= sqrt_n; ++i)
			{
				if (n%i == 0)
				{
					is_prime = false;
					break;
				}
			}
		}
	}

	return is_prime;
}

/* Unit test for est_premier()
 * return 1 if one test fails */
int unit_test_est_premier()
{
	int input[] =   {-1,    0,     1,     2,    3,    4,     5,    9,     17};
	bool output[] = {false, false, false, true, true, false, true, false, true};
	int nb_test = sizeof(input)/sizeof(input[0]);

	for (int i = 0; i < nb_test; ++i)
	{
		if (output[i] != est_premier(input[i]))
		{
			cout << "is prime(" << input[i]
				<< ") is different from expected result " << output[i] << endl;
			return 1;
		}
	}

	return 0;
}

const int size_string = 10;
/* Test function that returns prime numbers between nb_min and nb_max*/
string test_premiers(int nb_min, int nb_max)
{
	string str_ret("");
	char str_n[size_string];

	for (int i = nb_min; i <= nb_max; ++i)
	{
		if (est_premier(i))
		{
			str_ret += to_string(i, str_n, size_string);
			str_ret += ", ";
		}	
	}

	return str_ret;
}

/* Unit test for test_premiers */
int unit_test_test_premiers()
{
	string str_result = test_premiers(0, 100);
	string str_expected("2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, ");

	if(str_result.compare(str_expected))
	{
		cout << "the prime number between 0 and 100 : " << endl
			<< str_result << endl
			<< "is different from "
			<< endl << str_expected << endl;
		return 1;
	}

	return 0;
}

/* Unit test suite*/
int unit_test()
{
	if (unit_test_est_premier())
	{
		cout << "ERROR unit_test_est_premier() failed" << endl;
		return -1;
	}

	if (unit_test_test_premiers())
	{
		cout << "ERROR unit_test_test_premiers() failed" << endl;
		return -1;
	}

	return 0;
}

/* Legendre
 * Cette fonction testera tous les nombres compris entre n*n+1 et (n+1)*(n+1)-1
 * et s'arrêtera au premier nombre premier rencontré, qu'elle retournera.
 * Si, par contre, aucun nombre premier n'a été trouvé entre ces deux bornes, la
 * fonction retournera 0. */
int legendre(int n)
{
	for (int i = n*n+1; i <= (n+1)*(n+1)-1; ++i)
	{
		if (est_premier(i))
		{
			return i;
		}
	}

	return 0;
}

/* Test function for legendre conjecture
 * tests the conjecture for all numbers in a user selected interval */
void test_legendre()
{
	int nb_min = get_ui_int(1, 1);
	int nb_max = get_ui_int(nb_min, nb_min);

	cout << "Premiers entre " << nb_min
		<< " et " << nb_max
		<< " :" << endl;

	for (int i = nb_min; i <= nb_max; ++i)
	{
		cout << "Tester la conjecture de Legendre entre : ";
		cout << i*i+1;
		cout << " et : ";
		cout << (i+1)*(i+1)-1;
		cout << " --> ";

		int first_prime = legendre(i);
		if (first_prime == 0)
		{
			cout << "PAS TROUVÉ !";
			break;
		}
		else
		{
			cout << first_prime;
		}
		cout << endl;
	}
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
	if (unit_test())
		return 1;

	string str_0_100 = test_premiers(0, 100);
	cout << str_0_100 << endl;
	test_legendre();
	return 0;
}
