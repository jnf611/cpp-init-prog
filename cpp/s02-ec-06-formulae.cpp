/*
[lire la donnée en entier avant de poser des questions !] Soient les expressions suivantes :
x1−expx
xlog(x)exp2x−1
−x−x2−8x√2−x
(sin(x)−x20)log(x2−1x)−−−−−−−−−−−−−−−−−−−−√ On rappelle que le logarithme est défini sur les réels strictement positifs, la racine carrée sur les réels positifs ou nuls, la fraction 1/x sur les réels non nuls. Les autres fonctions sont définies sur l'ensemble des réels.
Écrivez un programme formules.cc qui :

demande à l'utilisateur d'entrer un réel ;
enregistre la réponse de l'utilisateur dans une variable x de type réel ;
teste pour chacune des expressions ci-dessus si elle est définie pour x :
si oui, le programme calcule le résultat de l'expression puis l'affiche ;
sinon, le programme affiche : « Expression i : indéfinie » où i est le numéro de l'expression considérée.
Testez votre programme avec les valeurs : -1, 0, 1, 2, 3, 8

*/

#include <iostream>
#include <cmath>
using namespace std;

bool e1(double x, double* res)
{
	bool ret = false;
	
	if (x != 0)
	{
		*res = x / (1 - exp(x));
		ret = true;
	}
	
	return ret;
}

bool e2(double x, double* res)
{
	bool ret = false;
	
	if (x > 0.0 && x != 1.0)
	{
		*res = x * log(x) * exp(2 / (x - 1));
		ret = true;
	}
	
	return ret;
}

bool e3(double x, double* res)
{
	bool ret = false;
	double tmp1 = x*x - 8*x;
	
	if ((tmp1 >= 0.0) && (x != 2.0))
	{
		*res = (-x - sqrt(tmp1)) / (2 - x);
		ret = true;
	}
	
	return ret;
}


bool e4(double x, double* res)
{
	bool ret = false;
	double tmp1 = x*x - 1/x;
	
	if (tmp1 >= 0.0)
	{
		double tmp2 = (sin(x) - x/20) * log(tmp1);
		if (tmp2 >= 0)
		{
			*res = sqrt(tmp2);
			ret = true;
		}
	}
	
	return ret;
}


int main()
{
	double x = 0.0;
	double input[] = {-1.0, 0.0, 1.0, 2.0, 3.0, 8.0};
	unsigned n = sizeof(input)/sizeof(input[0]);
	double res = 0.0;
	
	for (unsigned int i = 0; i < n; ++i)
	{
		x = input[i];
		if (e1(x, &res))
		{
			cout << "e1(" << x << ") = " << res << endl;
		}
		else
		{
			cout << "e1(" << x << ") undefined" << endl;
		}
		if (e2(x, &res))
		{
			cout << "e2(" << x << ") = " << res << endl;
		}
		else
		{
			cout << "e2(" << x << ") undefined" << endl;
		}
		if (e3(x, &res))
		{
			cout << "e3(" << x << ") = " << res << endl;
		}
		else
		{
			cout << "e3(" << x << ") undefined" << endl;
		}
		if (e4(x, &res))
		{
			cout << "e4(" << x << ") = " << res << endl;
		}
		else
		{
			cout << "e4(" << x << ") undefined" << endl;
		}
	}

	return 0;
}
