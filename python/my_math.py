#!/usr/bin/env python3
""" my math module
self implemented math functions """
import math


def is_prime(n):
	"""prime(n)
	Return True if number is prime"""
	is_prime = True # assuming n=2 which is prime
	if n < 2:
		is_prime = False
	elif n > 2:
		if n%2 == 0:
			is_prime = False
		else:
			for i in range (3, int(math.sqrt(n)) + 1):
				if n%i == 0:
					is_prime = False
					break
	
	return is_prime
	
	
def unittest_is_prime():
	"""" unit test for is prime function 
	Return 0 if test encountered no error"""
	tested_input    = [-1, 0, 1, 2, 3, 4, 5, 7, 9, 17]
	expected_result = [False, False, False, True, True, False, True, True, False, True]
	for i, n in enumerate(tested_input):
		result = is_prime(n)
		if result != expected_result[i]:
			print("ERROR in isprime(" + str(n) + ") = " + str(result)
				+ " while expecting " + str(expected_result[i])) 
			return 1
	print("unittest_is_prime() runned succesfully")
	return 0
	

if __name__ == "__main__":
	if unittest_is_prime():
		print("ERROR in unittest_is_prime()")

