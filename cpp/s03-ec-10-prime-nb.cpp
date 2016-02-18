/*s03-ec10
Écrivez le programme premier.cc qui demande à l'utilisateur d'entrer un entier n
strictement plus grand que 1, puis décide si ce nombre est premier ou non.

Algorithme :

Vérifier si le nombre n est pair (si oui, il n'est pas premier sauf si c'est 2).

Pour tous les nombres impairs inférieurs ou égaux à la racine carrée de n,
vérifier s'ils divisent n. Si ce n'est pas le cas, alors n est premier.

Tâches :

Si n n'est pas premier, votre programme devra afficher le message:
"Le nombre n'est pas premier, car il est divisible par D ", où D est un diviseur
de n autre que 1 et n.

Sinon, il devra afficher le message: "Je crois fortement que ce nombre est premier".

Testez votre programme avec les nombres : 2, 16, 17, 91, 589, 1001, 1009,
1299827 et 2146654199. Indiquez ceux qui sont premiers.

Les résultats devraient ressembler à ceci :

2 est premier
16 n'est pas premier, car il est divisible par 2
17 est premier
91 n'est pas premier, car il est divisible par 7
589 n'est pas premier, car il est divisible par 19
1001 n'est pas premier, car il est divisible par 7
1009 est premier
1299827 est premier
2146654199 n'est pas premier, car il est divisible par 46327
*/

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n, int* d)
{
	bool isPrime = true;
	*d = 2;
	
	if (n > 3)
	{
		if(n%2 == 0)
		{
			isPrime = false;
		}
		else
		{
			int limit = sqrt(n);
			int i = 3;
			while (isPrime && i < limit)
			{
				if (n%i == 0)
				{
					isPrime = false;
					*d = n/i;
				}
				i += 2;
			}
		}
	}
	
	return isPrime;
}

bool test_is_prime()
{
	int input[] =   {2,    16,    17,   91,    589,   1001,  1009, 1299827, 2146654199};
	bool output[] = {true, false, true, false, false, false, true, true,    false     };
	
	int nbInput = sizeof(input)/sizeof(input[0]); 
	if (nbInput != sizeof(output)/sizeof(output[0]))
	{
		cout << "Error in test set";
		return false;
	}
	
	int d;
	for (int i = 0; i < nbInput; ++i)
	{
		if(output[i] != is_prime(input[i], &d))
		{
			cout << "Error " << input[i] << " expected to be " << (output[i]?"prime":"not prime") << endl;
			return false;
		}
	}
	
	return true;
}

int main()
{
	if (!test_is_prime())
	{
		return 1;
	}
	
	int n;
	do
	{
		cout << "entrez un nombre entier > 1: ";
		cin >> n;
	}
	while (n < 2);
	
	int d;
	bool prime = is_prime(n, &d);
	cout << n;
	if (prime)
	{
		cout << " est premier" << endl;
	}
	else
	{
		cout << " n'est pas premier, car il est divisible par " << d;
	}
	cout << endl;
	
	
	return 0;
}
	
