#!/usr/bin/env python3
""" my math module
self implemented math functions """
import math
import my_math
import get_ui

def legendre(n):
	""" Check Legendre's conjecture
	Return first prime number between n^2 and (n+1)^2
	or 0 when none found"""
	for p in range(n*n+1, (n+1)*(n+1)):
		if (my_math.is_prime(p)):
			return p
	
	return 0

	
def test_legendre():
	""" Test program for Legendre conjecture"""
	a = get_ui.get_int(0, 100)
	b = get_ui.get_int(a, a)
	
	for n in range(a, b):
		p = legendre(n)
		str_res = "legendre for " + str(n) + " --> "
		if p != 0:
			print(str_res + str(p))
		else:
			print(str_res + "NOT FOUND")
			return
			
	
if __name__ == "__main__":
	test_legendre()
 
