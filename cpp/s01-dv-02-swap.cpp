/*The goal of this exercice is to swap the value of three variables.

Download the source code available at the course webpage (https://d396qusza40orc.cloudfront.net/initprogcpp/assignments-data/swap3.cc) and complete it according to the instructions below.

WARNING: you should modify neither the beginning nor the end of the provided file. It's thus mandatory to proceed as follows:

    save the downloaded file as swap3.cc or swap3.cpp;

    write your code between these two provided comments:*/

    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/

    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/
/*
    save and test your program to be sure that it works properly; try for instance the values used in the example given below;

    upload the modified file (still named swap3.cc or swap3.cpp) in "OUTPUT submission" (not in "Additional"!).

The downloaded code aims at asking the user to input three values, and printing them once switched around. However, the code to move these values around is missing and you have to write it.

You are thus asked to complete the provided program (between the comments as explained above) so as to perform the following permutation : the content of a should go into b, the initial value of b into c and the initial value of c into a, as illustrated in the execution example below.
2.2 Execution example

Entrez la premiere  valeur : 51
Entrez la deuxieme  valeur : 876
Entrez la troisieme valeur : 235
Les valeurs entrees sont : a = 51, b = 876 et c = 235
Permutation: a ==> b, b ==> c, c ==> a
Les valeurs permutees sont : a = 235, b = 51 et c = 876
*/
#include <iostream>

using namespace std;

int main()
{
  cout << "Entrez la premiere  valeur : ";
  int a(0);
  cin >> a;
  cout << "Entrez la deuxieme  valeur : ";
  int b(0);
  cin >> b;
  cout << "Entrez la troisieme valeur : ";
  int c(0);
  cin >> c;

  cout << "Les valeurs entrees sont : a = " << a << ", b = " << b
       << " et c = " << c << endl;

  cout << "Permutation: a ==> b, b ==> c, c ==> a" << endl;

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
   int tmp = c;
   c = b;
   b = a;
   a = tmp;

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  cout << "Les valeurs permutees sont : a = " << a << ", b = " << b
       << " et c = " << c << endl;

  return 0;
}
