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
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/
 
/*Teste si un noombre est premier*/
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
			for (int i = 3; i < sqrt_n; ++i)
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
	if (est_premier(-1))
		return 1;
	if (est_premier(0))
		return 1;
	if (est_premier(1))
		return 1;
	if (!est_premier(2))
		return 1;
	if (!est_premier(3))
		return 1;
	if (est_premier(4))
		return 1;
	if (!est_premier(5))
		return 1;
	if (!est_premier(17))
		return 1;
		
	return 0;
}

/* Unit tests
 * return 1 if one unit test fail */
int unit_test()
{
	if (unit_test_est_premier())
	{
		cout << "ERROR unit_test_est_premier() failed" << endl;
		return 1;
	}
	return 0;
}

/* Invert the string */
void invert_string(char* str, int n)
{
	for (int i = 0; i < (n+1)/2; i++)
	{
		char tmp = str[n-i];
		str[n-i] = str[i];
		str[i] = tmp;
	}
}

/* Int to string conversion 
 * convert an integer to a c-string
 * return a pointer to the string or NULL*/
char* to_string(int n, char* str, int len)
{
	int i = 0;
	
	do
	{
		str[i] = (n%10) + 48;
		n /= 10;
		++i;
	}
	while(n && (i < len));
	
	if (i == len)
	{
		return NULL;
	}
	else
	{
		str[i] = '\0';
		invert_string(str, i-1);
		return str;
	}
}

string test_premiers(int nb_min, int nb_max)
{
	string str_ret("");
	char str_n[10];
	
	for (int i = nb_min; i <= nb_max; ++i)
	{
		if (est_premier(i))
		{
			str_ret += to_string(i, str_n);
			str_ret += ", ";
		}	
	}
	
	return str_ret;
}

void test_legendre()
{
		
	cout << "Premiers entre "
		<< " et "
		<< " :" << endl;

	cout << "Tester la conjecture de Legendre entre : ";

	cout << "et : ";

	cout << "PAS TROUVÉ !";
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
