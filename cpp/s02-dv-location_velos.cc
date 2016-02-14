#include <iostream>
using namespace std;

const int tarif[] = {1, 2};
const int start_period = 7;
const int end_period = 19;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut(25);
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin(25);
  cin >> fin;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  if ((debut > 24) || (debut < 0) || (fin > 24) || (fin < 0))
  {
    cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
  }
  else if (debut == fin)
  {
    cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
  }
  else if (debut > fin)
  {
    cout << "Bizarre, le début de la location est après la fin ..." << endl;
  }
  else
  {
    cout << "Vous avez loué votre vélo pendant: " << endl;
    //             7                19
    //             |                 |
    //   [      ]  |                 |      [        ]
    //             |     [       ]   |
    //        [    |        ]        |        ]
    //             |        [        |      ]
    int somme = 0;
    int nb_heure[] = {0, 0};
    if (fin <= start_period || debut >= end_period)
    {
        nb_heure[0] += fin-debut;
    }
    else if (fin <= end_period && debut >= start_period)
    {
		nb_heure[1] += fin-debut;
	}
	else if (debut < start_period)
	{
		nb_heure[0] += start_period-debut;
		nb_heure[1] += fin-start_period;
		if (fin > end_period)
		{
			nb_heure[0] += fin-end_period;	
		}
	}
	else
	{
		nb_heure[0] += fin-end_period;
		nb_heure[1] += end_period-start_period;
	}

    for (int i = 0; i < 2; ++i)
    {
      somme += tarif[i] * nb_heure[i];
      cout << nb_heure[i] << " heure(s) au tarif horaire de "
           << tarif[i] << " franc(s)" << endl;
    }

    cout << "Le montant total à payer est de " << somme
         << " franc(s)." << endl;
    }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
