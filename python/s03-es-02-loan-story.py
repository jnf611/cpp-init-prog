#!/usr/bin/env python3
"""Semaine 03 Exercice supplementaire 02"""
import math

def bank_loan_parameter(S0, r, ir):

	nb_month = int(math.ceil(S0/r))
	sum_interest = 0.0 #somme des interets
	S = S0  #somme restant a rembourser
	for n in range(0, nb_month):
		i = ir*S;
		sum_interest += i;
		S -= min(r, S);
	return nb_month, sum_interest

if __name__ == "__main__":
	S0 = 30000  # montant du pret initial
	r  = 1200.0 # remboursement par mois
	ir = 0.01   # taux d'interet mensuel
	# we skip part about user input and check
	nb_month, sum_interest = bank_loan_parameter(S0, r, ir)

	print("le remboursement s'etale sur " + str(nb_month) + " mois.")
	print("la somme des interets verses est de " + str(sum_interest) + " euros.");
