/* S03 EC7
Ecrivez un programme tables.cc affichant les tables de multiplication de 2 à 10.

Votre programme devra produire la sortie suivante à l'écran :

Tables de multiplication

Table de 2 :
  1 * 2 = 2
  ...
  10 * 2 = 20
...
Table de 5 :
  1 * 5 = 5
  2 * 5 = 10
  ...
...
Table de 10 :
  1 * 10 = 10
  ...
*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i, j;
	
	for (i = 2; i <= 10; ++i)
	{
		printf("Table de %d\n", i);
		for (j = 1; j <= 10; j++)
		{
			printf("  %d * %d = %d\n", j, i, i*j);
		}
		printf("\n");
	}
	return 0;
}
