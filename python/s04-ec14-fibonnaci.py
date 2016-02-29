#!/usr/bin/env python3
""" semaine 04 ec 13
fibonacci suites (see cpp files)
"""

import get_ui

max_recursive_fibonnaci = 40

def FibonacciIteratif(n):
	"""Compute Fibonacci iteratively"""
	Fn = 0       # stocke F(i)  , initialized by F(0)
	Fn_1 = Fn;   # stocke F(i-1), initialized by F(0)
	Fn_2 = 1;    # stocke F(i-2), initialized par F(-1)

	if n > 0:
		for i in range (1, n+1):
			Fn   = Fn_1 + Fn_2    # pour n>=1 on calcule F(n)=F(n-1)+F(n-2)
			Fn_2 = Fn_1           # et on decale...
			Fn_1 = Fn

	return Fn


def FibonacciRecursive(n):
	"""Compute Fibonacci recursively"""
	Fn = 0

	if n == 0:
		Fn = 0
	elif n == 1:
		Fn = 1
	else:
		Fn = FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);

	return Fn


def main():

	do_continue = True

	while do_continue:
		n = get_ui.get_int(0, max_recursive_fibonnaci);
		n_iterative = FibonacciIteratif(n);
		print("Iterative method :\nF(" + str(n) + ") = " + str(n_iterative))
		n_recursive = FibonacciRecursive(n);
		print("Recursive method :\nF(" + str(n) + ") = " + str(n_recursive));
		do_continue = get_ui.do_continue()



if __name__ == "__main__":
	main()
