""" Semaine 02 exercice 04
see ~.cpp
"""

def belong_to_intervalle(x):
	my_lower_bound = -1.0;
	my_higher_bound = 1;
	str_intervalle = "[" +  str(my_lower_bound) + ", " + str(my_higher_bound) + "]";

	if ((x >= my_lower_bound) and (x < my_higher_bound)):
		print(str(x) + " belongs to " + str_intervalle);
	else:
		print(str(x) + " does not belong to " + str_intervalle);



if (__name__ == '__main__'):

	x = input("Enter a floating number ")

	belong_to_intervalle(x);
	belong_to_intervalle(-2.5);
	belong_to_intervalle(-1.0);
	belong_to_intervalle(-0.5);
	belong_to_intervalle(0.0);
	belong_to_intervalle(1.0);
	belong_to_intervalle(1.5);

