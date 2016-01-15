#!/usr/bin/env python3
"""See cpp"""

def swap2(tab):

	print("Les valeurs entrees sont : a = " + str(tab[0]) + ", b = " + str(tab[1]) + " et c = " + str(tab[2]))
	print("Permutation: a ==> b, b ==> c, c ==> a");
	
	tab[0], tab[1], tab[2] = tab[2], tab[0], tab[1]

	print("Les valeurs permutees sont : a = " + str(tab[0]) + ", b = " + str(tab[1]) + " et c = " + str(tab[2]))

	return 0;

def main():
	a = input("Entrez la premiere  valeur : ");
	b = input("Entrez la deuxieme  valeur : ");
	c = input("Entrez la troisieme valeur : ");
	
	tab = [a, b, c];

	print("Les valeurs entrees sont : a = " + str(a) + ", b = " + str(b) + " et c = " + str(c))
	print("Permutation: a ==> b, b ==> c, c ==> a");

	tmp = c;
	c = b;
	b = a;
	a = tmp;
	

	print("Les valeurs permutees sont : a = " + str(a) + ", b = " + str(b) + " et c = " + str(c))
	
	swap2(tab)

	return 0;

if (__name__ == "__main__"):
	main();
