/* Semaine 4 Devoir 1
 * Exercice 1 — Sommes et produits
On s'intéresse ici à trouver des nombres dont la somme des chiffres est égale à
leur produit. Par exemple 123 est un tel nombre : 1+2+3=1×2×3.

On commence par vouloir écrire une fonction qui retourne la somme des chiffres
d'un nombre passé en argument. Par exemple, cette fonction devra retourner 3
quand 12 est passé en argument (puisque 1+2=3) et 7 quand 223 est passé en
argument (2+2+3=7).

Mais comment calculer la somme des chiffres d'un nombre n ?

Tout d'abord, on peut remarquer que le reste de la division de n par 10
(c'est-à-dire « n modulo 10 », noté en C++ n % 10), donne le chiffre le plus à
droite de n. Par exemple, 178 % 10 donne 8.

Pour obtenir le deuxième chiffre le plus à droite de n, on commence par diviser
n par 10, en utilisant la division entière. Avec n=178, on obtient 17.
Il suffit alors de prendre ce nouveau nombre modulo 10 pour obtenir le deuxième
chiffre. Par exemple, 17 % 10 nous donne 7.

Il n'y a plus qu'à répéter ces opérations jusqu'à ce que le résultat soit 0.
En continuant l'exemple précédent : 17 divisé par 10 donne 1 (division entière),
1 modulo 10 donne 1, 1 divisé par 10 donne 0, on s'arrête.

En sommant les chiffres obtenus grâce au modulo 10 au fur et à mesure qu'on les
calcule, on obtient la somme des chiffres du nombre n de départ.

Pour résumer, avec n=178 cela donnera les opérations suivantes :
178 % 10 donne 8 ;
178 / 10 donne 17 ;
17 % 10 donne 7, que l'on ajoute au 8 précédent ; cela fait 15 ;
17 / 10 donne 1 ;
1 % 10 donne 1, que l'on ajoute au 15 précédent ; cela fait 16 ;
1 / 10 donne 0 et on s'arrête ; le résultat est 16.
Ecrivez une fonction appelée somme qui, en appliquant la méthode décrite
ci-dessus, retourne la somme des chiffres du nombre entier qu'elle reçoit en
paramètre. La valeur de retour est donc également un nombre entier.

Ecrivez ensuite une fonction appelée produit qui retourne le produit des
chiffres d'un nombre passé en argument. Par exemple, cette fonction devra
retourner 2 quand 12 est passé en argument (1×2=2),
24 quand 423 est passé en argument (4×2×3=24).
Le principe de calcul est le même que pour la somme.

Utilisez ensuite vos deux fonctions pour écrire une fonction somme_produit_egaux
qui teste si la somme des chiffres d'un nombre entier passé en argument est
égale au produit de ces mêmes chiffres. Par exemple, somme_produit_egaux(12)
devra renvoyer false, somme_produit_egaux(123) devra renvoyer true.

Note : on peut écrire cette fonction en une seule ligne.

Utilisez enfin cette fonction somme_produit_egaux pour afficher les 20 premiers
nombres entiers plus grands que 10 dont la somme des chiffres est égale au
produit de ces mêmes chiffres. Pour vous aider à vérifier votre programme,
voici les 5 premiers nombres que vous devriez trouver :
22, 123, 132, 213 et 231.

ATTENTION ! Pour avoir les points, votre programme devra respecter strictement
le format d'affichage suivant : liste de nombres en une seule ligne, séparés par
des virgules. Pour faciliter l'écriture de votre code le dernier nombre sera
également suivi d'une virgule. Il n'y aura qu'un seul retour à la ligne, à la
fin. Avec 5 nombres, cela donnerait :

22, 123, 132, 213, 231,
Notez bien qu'il y a une virgule (et une (L'espace du typographe est féminine.)
espace) à la fin.*/

#include <iostream>
using namespace std;

/* somme des chiffres d'un nombre */
int sum_number(int nb)
{
	int sum = 0;
	
	do
	{
		sum += nb%10;
		nb /= 10;
	}
	while (nb > 0);
	
	return sum;
}

/* produit des chiffres d'un nombre */
int product_number(int nb)
{
	int product = 1;
	
	do
	{
		product *= nb%10;
		nb /= 10;
	}
	while (nb > 0);
	
	return product;
}

int unit_test_sum_number()
{
	if (sum_number(0) != 0)
		return 1;
	if (sum_number(1) != 1)
		return 1;
	if (sum_number(12) != 3)
		return 1;
	if (sum_number(123) != 6)
		return 1;

	return 0;
}

int unit_test_product_number()
{
	if (product_number(0) != 0)
		return 1;
	if (product_number(1) != 1)
		return 1;
	if (product_number(12) != 2)
		return 1;
	if (product_number(123) != 6)
		return 1;
	if (product_number(1230) != 0)
		return 1;

	return 0;
}

bool sum_product_equal(int nb)
{
	return (sum_number(nb) == product_number(nb));
}

int unit_test_sum_product_equal()
{
	if (!sum_product_equal(0))
		return 1;
	if (!sum_product_equal(1))
		return 1;
	if (!sum_product_equal(2))
		return 1;	
	if (sum_product_equal(12))
		return 1;
	if (!sum_product_equal(123))
		return 1;

	return 0;
}

int unit_tests()
{
	if( unit_test_sum_number())
	{
		cout << "error in sum_number" << endl;
		return 1;
	}
	if( unit_test_product_number())
	{
		cout << "error in product_number" << endl;
		return 1;
	}
	if( unit_test_sum_product_equal())
	{
		cout << "sum_product_equal" << endl;
		return 1;
	}
	
	return 0;
}

int main()
{
	unit_tests();
	
	int nb_found = 0;
	int n = 10;
	
	while (nb_found < 20)
	{
		if (sum_product_equal(n))
		{
			cout << n << ", ";
			nb_found++;
		}
		n++;
	}
	cout << endl;
	
	return 0;
}
