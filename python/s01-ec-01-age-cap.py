#!/usr/bin/env python3

"""Ecrivez un programme age.cc qui :

    demande son age a l'utilisateur ;
    lit la reponse de l'utilisateur et l'enregistre dans une variable age de type entier;
    calcule l'annee de naissance (a un an pres) de l'utilisateur et l'enregistre dans la variable annee de type entier;
    affiche l'annee de naissance ainsi calculee.
"""

YEAR = 2016;

age = input("what your age ? ")
birthDate = YEAR - age;
print("your are born in " + str(birthDate));

