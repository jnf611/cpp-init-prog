/* s05e17
Exercice 17 : Multiplication de matrices (tableaux dynamiques, niveau 2)
Cet exercice correspond à l'exercice n°20 (pages 57 et 222) de l'ouvrage C++ par la pratique (3e édition, PPUR).
On cherche ici à écrire un programme mulmat.cc qui calcule la multiplication de deux matrices (rappel ci-dessous).

Vous utiliserez pour représenter la matrice un tableau dynamique de tableaux dynamiques de doubles.

Déclarations :

dans main(), déclarez deux matrices M1 et M2.
Fonctions :

la fonction de prototype vector<vector<double>> lire_matrice();
qui lit depuis le clavier les éléments d'une matrice (après avoir demandé sa taille) et retourne la matrice résultante.
la fonction de prototype
vector<vector<double>> multiplication(const vector<vector<double>>& Mat1,
                                      const vector<vector<double>>& Mat2);
qui multiplie deux matrices de tailles et renvoie le résultat.
la fonction de prototype
void  affiche_matrice(const vector<vector<double>> M);

qui affiche le contenu d'une matrice ligne par ligne.
Méthode :

lire depuis le clavier les dimensions l1 (nombre de lignes) et c1 (nombre de colonnes) de la première matrice M1
lire le contenu de M1.
De même, lire les dimensions puis le contenu de la seconde matrice M2.
Vérifier que le nombre de lignes de M2 est identique au nombre de colonnes de M1.
Dans le cas contraire, afficher un message d'erreur « Multiplication de matrices impossible ! ».
Effectuer la mutliplication des matrices : M = M1*M2 :
Les dimensions de M sont : l1 (nombre de lignes) et c2 (nombre de colonnes).
l'élément Mi,j est défini par Mij=∑kM1ik∗M2kj.
afficher le résultat ligne par ligne.
*/

#include <iostream>
#include <vector>
#include "get_ui.hpp"
using namespace std;

const int N_MAX = 3;

void affiche(const vector<vector<double>> M)
{
	for (size_t i = 0; i < M.size(); ++i)
	{
		for (size_t j = 0; j < M[i].size(); ++j)
		{
			cout << M[i][j] << " ";
		}
	}
}

vector<vector<double>> multiplication(const vector<vector<double>>& Mat1,
                                      const vector<vector<double>>& Mat2)
{
	unsigned int m = Mat1.size();
	unsigned int n = Mat2[0].size();
	vector<vector<double>> ret(m, vector<double>(n));

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			for (size_t k = 0; k < Mat1[i].size(); k++)
			{
				ret[i][j] += Mat1[i][k]*Mat2[k][j];
			}
		}
	}

	return ret;
}

int main()
{
	vector<vector<double>> Mat1 = get_ui_matrix(N_MAX, "Mat1");
	vector<vector<double>> Mat2 = get_ui_matrix(N_MAX, "Mat2");

	if (Mat1[0].size() != Mat2.size())
	{
		cout << "ERROR: unable to multiplicate M1 and M2" << endl;
		return 1;
	}
	else
	{
		vector<vector<double>> Mat3 = multiplication(Mat1, Mat2);
		affiche(Mat3);
	}
}
