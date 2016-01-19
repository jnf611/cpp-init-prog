#!/usr/bin/env python3

"""
Nous voulons écrire un programme permettant de calculer l'IMC (indice de
masse corporelle) d'une personne. L'IMC se calcule à partir du poids et
de la taille suivant la formule : poids (en kg) divisé par le carré de
sa taille (en m).
"""

def imc(masse, taille):
	return masse / taille / taille;
	
def descriptif_imc(imc):
	if (imc < 20.0):
		return "très maigre";
	elif (imc < 25.0):
		return "maigre";
	else:
		return "gros";

masse = float(input("poids (kg)"))
taille = float(input("taille (m)"))
valeur_imc = imc(masse, taille)
print("votre imc est de " + str(valeur_imc))
print("vous etes : " + descriptif_imc(valeur_imc))
