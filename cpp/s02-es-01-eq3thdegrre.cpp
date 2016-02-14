/* exercice supplémentaire S02
On veut écrire un programme qui demande trois valeurs (a0, a1, a2) à l'utilisateur et affiche la (ou les) solution(s) réelle(s) z 
de l'équation du troisième degré :

z3 + a2 z2 + a1 z + a0 = 0

Indications - commencer par calculer :

Q=(3a1−a2a2)/9
R=(9a2a1−27a0−2a23)/54
D=Q3+R2
Démonstration des formules à la page : http://mathworld.wolfram.com/CubicFormula.html

Si D < 0, on calcule les trois solutions réelles ainsi :

θ=acos(R(−Q)3√)	(la fonction acos existe en C++ dans la bibliothèque <cmath> - 
i.e. il faut inclure ce fichier en début de programme)
z1 =	2−Q−−−√cos(θ/3)−a2/3
z2 =	2−Q−−−√cos((θ+2π)/3)−a2/3	Pour π, vous pouvez utiliser la constante M_PI souvent présente dans <cmath>
(ce n'est pas rigoureusement une constante officielle, mais elle est présente sur la plupart des compilateurs. Une alternative consiste à utiliser acos(-1.0) : const double pi(acos(-1.0));)
z3 =	2−Q−−−√cos((θ+4π)/3)−a2/3
Sinon, on calcule :
S =	(R+D−−√)1/3	La racine cubique de x est obtenue en C++ par «pow(x,1.0/3.0)». 
Notez que la racine cubique de (-x) est l'opposé de la racine cubique de x. 
Il faut en effet traiter séparément le cas où x < 0 du cas x >= 0, car C++ ne l'accepte pas dans la fonction pow.
T =	(R−D−−√)1/3	
Si D=0 et S+T != 0, il y a 2 racines :

z1 =	S+T−a2/3
z2 =	−(S+T)/2−a2/3	(racine double)
Sinon, il y a une racine unique : z1 ci-dessus.

*/
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
	double a2 = 0;
	double a1 = 0;
	double a0 = 0;
	cout << "resolution of \"z^3 + a2 z^2 + a1 z + a0 = 0\"" << endl;
	cout << "enter a2: "; cin >> a2;
	cout << "enter a1: "; cin >> a1;
	cout << "enter a0: "; cin >> a0;
	
	// Computing intermediary results Q=(3a1−a2a2)/9, R=(9a2a1−27a0−2a23)/54, 
	// and D=Q3+R2
	double q = (3*a1 - pow(a2,2)) / 9;
	double r = (9*a2*a1 - 27*a0 - 2*pow(a2, 3)) / 54;
	double d = pow(q,3) + pow(r,2);
	
	if (d < 0)
	{
		double theta = acos(r / sqrt(pow(-q, 3)));
		double pi = acos(-1.0);
		double z1 = 2*sqrt(-q)*cos( theta        /3) - a2/3;
		double z2 = 2*sqrt(-q)*cos((theta + 2*pi)/3) - a2/3;
		double z3 = 2*sqrt(-q)*cos((theta + 4*pi)/3) - a2/3;
		cout << "solutions are z1=" << z1 << ", z2=" << z2 << ", z3=" << z3 << endl;
	}
	else
	{
		// Computing intermediary results 
		double s = 0.0;
		double tmp = r + sqrt(d);
		if      (tmp == 0.0) { s =  0.0;               }
		else if (tmp >= 0.0) { s =  pow(tmp,  1.0/3.0);}
		else                 { s = -pow(-tmp, 1.0/3.0);}
		
		double t = 0.0;
		tmp = r - sqrt(d);
		if      (tmp == 0.0) { t =  0.0;               }
		else if (tmp >= 0.0) { t =  pow(tmp,  1.0/3.0);}
		else                 { t = -pow(-tmp, 1.0/3.0);}
		
		double z1 = s + t - a2/3;
		if (d == 0.0 && (s + t) != 0.0)
		{
			double z2 = -(s + t)/2 - a2/3;
			cout << "solutions are single root z1=" << z1 
			     << ", and double root z2=" << z2 << endl;
		}
		else
		{
			cout << "solution is single root z1=" << z1 << endl;
		}
	}

	return 0;
}
