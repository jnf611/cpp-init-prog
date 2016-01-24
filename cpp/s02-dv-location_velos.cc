#include <iostream>
using namespace std;

const int tarif[] = {1, 2};

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
    int somme = 0;
    int nb_heure[] = {24-19+7, 19-7}; // 12 et 12
    if (debut < 7)
    {
        nb_heure[0] -= debut - 7;
    }
    if (fin > 19)
    {
		nb_heure[0] -= 19 - fin;
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
