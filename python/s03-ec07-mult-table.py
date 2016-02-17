#!/usr/bin/env python
""" S03 EC7
Tables de multiplication
see cpp file """

def main():

	for i in range(2, 11):
		print("Table de " + str(i))
		for j in range(1, 11):
			print("  " + str(j) + " * " + str(i) + " = " + str(i*j))
		print("")

if __name__ == "__main__":
	main()
