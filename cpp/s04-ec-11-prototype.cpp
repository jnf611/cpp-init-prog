/* S04 EC11
Écrivez un programme proto.cc dans lequel vous définissez une fonction
demander_nombre() respectant le prototype suivant :

int demander_nombre();
Cette fonction doit demander à l'utilisateur un entier et le renvoyer.
Placez la définition de la fonction avant le main().
Faites appel à la fonction dans le main() et affichez le résultat renvoyé.
Que se passe-t-il si l'on déplace la définition de la fonction demander_nombre()
après le main() et que l'on recompile le programme ?
(faites-le et vérifiez si le compilateur réagit comme vous vous y attendiez).
Ajoutez ensuite le prototype de la fonction demander_nombre() avant main() et
recompilez le programme.
Modifiez maintenant la fonction pour qu'elle prenne 2 arguments :
les bornes minimales et maximales entre lesquelles l'utilisateur doit donner le
nombre.
La fonction doit boucler tant que l'utilisateur ne donne pas un chiffre valide.
Raffinez encore le programme de sorte que si la borne maximale est inférieure ou
égale à la borne minimale, elle ne soit pas prise en compte (c'est-à-dire que
l'on peut entrer n'importe quel chiffre plus grand que la borne minimale).
*/

#include <iostream>
using namespace std;

static int demande_nomber(int min, int max);

int main()
{
	int a(demande_nomber(0, 10));
	cout << "a=" << a << endl;
	int b(demande_nomber(10, 0));
	cout << "b=" << b << endl;
}

static int demande_nomber(int min, int max)
{
	int a(0);
	
	do
	{
		cout << "entrer un entier? ";
		cin >> a;
	}
	while (a < min || (max > min && a > max));
	
	return a;
}
