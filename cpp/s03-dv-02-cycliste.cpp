#include <iostream>
#include <cmath> // pour atan, sin, abs et remainder
#include <iomanip> // pour setprecision
using namespace std;

static void get_user_input(double* m,
                    double* vent,
                    double* d_totale,
                    double* d_sommet,
                    double* pente_montee,
                    double* pente_descente)
{
  do
  {
    cout << "masse du cycliste (entre 40 et 180 kg) ? ";
    cin >> *m;
  }
  while (*m < 40.0 || *m > 180.0);
  
  do
  {
    cout << "vent (entre -20 et +20 km/h) ? ";
    cin >> *vent;
  }
  while (*vent < -20.0 || *vent > 20.0);
  
  do
  {
    cout << "distance du parcours (<= 200 km) ? ";
    cin >> *d_totale;
  }
  while (*d_totale < 11.0 || *d_totale > 200.0);

  do
  {
    cout << "distance au sommet du col (<= ";
    cout << *d_totale - 10;
    cout << " km) ? ";
    cin >> *d_sommet;
  }
  while (*d_sommet <= 0.0 || *d_sommet > (*d_totale - 10.0));

  do
  {
    cout << "pente moyenne jusqu'au sommet (<= 20 %) ? ";
    cin >> *pente_montee;
  }
  while (*pente_montee <= 0.0 || *pente_montee > 20.0);

  do
  {
    cout << "pente moyenne après le sommet (<= 20 %) ? ";
    cin >> *pente_descente;
  }
  while (*pente_descente <= 0.0 || *pente_descente > 20.0);

  cout << "paramètres de la simulation : "
       << *m << " "
       << *vent << " "
       << *d_totale << " "
       << *d_sommet << " "
       << *pente_montee << " "
       << *pente_descente << " "
       << endl;
}


int main()
{
  cout << setprecision(3);

  double t(0.0);    // temps, en min.
  double d(0.0);    // distance, en km
  double v(30.0);   // vitesse, en km/h
  double acc(0.0);  // accélération, en km/h/min
  double P(175.0);  // puissance, en W

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/
  double m(80.0), vent(-10.0), d_totale(50.0), d_sommet(30.0), pente_montee(5.0), pente_descente(-10.0);
  //get_user_input(&m, &vent, &d_totale, &d_sommet, &pente_montee, &pente_descente);
  
  const double dt = 1.0/60.0;
  double v_rel(v-vent);
  bool first = true;
  bool running = true;
  double pente(pente_montee);
  
  while (running && d < d_totale)
  {
    // affichage des informations courantes :
    if (abs(remainder(t, 5.)) < 1e-5) {
      cout << t << ", " << d << ", " << v << ", " << acc << ", " << P << endl;
    }
    t += dt;
    v_rel = v - vent;
    if (d < d_sommet)
    {
	  if (P > 10.0)
	    P -= 0.5*dt;
	  pente = pente_montee;
    }
    else
    {
		pente = pente_descente;
		P = 10.0;
	}
    acc = -2118.96 * sin(atan(pente/100)) - 5*v_rel*abs(v_rel)/m;
    if (P > 0.0 && v > 0.0)
	  acc += 777.6*P/(v*m);
	if (abs(acc) < 1e-5)
	   acc = 0.0;
	
	v += acc*dt;
	d += v*dt/60;
    
	if (d > d_sommet && first)
	{
      cout << "## Bernard a atteint le sommet en " << t << " min." << endl;
      first = false;
    }

    if (v < 3.0)
    {
      cout << "## Bernard abandonne, il n'en peut plus" << endl;
      cout << t << ", " << d << ", " << v << ", " << acc << ", " << P << endl;
      running = false;
    }
  }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  cout << "## Bernard est arrivé" << endl;
  cout << t << ", " << d << ", " << v << ", " << acc << ", " << P << endl;

  return 0;
}
