#include <iostream>
#include <iomanip> // pour setprecision()
#include <cmath>   // pour exp()
using namespace std;

int main()
{
  // réduire le format d'affichage
  cout << setprecision(4);

  const double population_initiale(7.0); // population initiale, en milliard d'humains
  const int    annee_depart(2011);       // année initiale
  double taux(1.2);                          // taux de croissance, en %

  int annee(annee_depart);                // année de calcul
  double population(population_initiale); // population mondiale pour l'année 'annee'

  cout << "====---- PARTIE 1 ----====" << endl;
  cout << "Population en " << annee << " : " << population
       << endl;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  do
  {
    cout << "Quelle année (> " << annee_depart << ") ? ";
    cin >> annee;
  }
  while (annee <= annee_depart);
  
  double pop_2016 = population_initiale * exp(taux*(2016 - annee_depart)/100);
  const double expected_pop_2016 = 7.433;
  if ((pop_2016 > (expected_pop_2016+0.001)) || (pop_2016 < (expected_pop_2016-0.001)))
  {
    cout << "error partie 1:" << pop_2016 << ", while expecting: "<< expected_pop_2016 << endl;
    return 1;
  }
  
  population = population_initiale * exp(taux*(annee - annee_depart)/100);
  cout << "Population en " << annee << " : " << population
       << endl;

  // ===== PARTIE 2 =====
  cout << endl << "====---- PARTIE 2 ----====" << endl;
  
  double population_cible = population_initiale;
  do
  {
     cout << "Combien de milliards (> " << population_initiale << ") ? ";
     cin >> population_cible;
  }
  while (population_cible <= population_initiale);
  
  cout << "Population voulue : " << population << endl;
  
  annee = annee_depart;
  do
  {
     annee++;
     population = population_initiale * exp(taux*(annee - annee_depart)/100);
     cout << "Population en " << annee << " : " << population << endl;
  }
  while (population < population_cible);

  // ===== PARTIE 3 =====
  cout << endl << "====---- PARTIE 3 ----====" << endl;
  
  annee = annee_depart;
  population = population_initiale;
  double population_seuil = population_initiale;
  double annee_seuil = annee_depart;
  do
  {
     annee++;
     population = population_seuil * exp(taux*(annee - annee_seuil)/100);
     cout << "Population en " << annee << " : " << population 
        << ", taux : " << taux << endl;
     if (population > (2*population_seuil))
     {
		 taux /= 2.0;
		 annee_seuil = annee;
		 population_seuil = population;
     }
  }
  while (population < population_cible);

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
