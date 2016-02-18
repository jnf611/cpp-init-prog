""" week 03 ec 09 """
import math

g = 9.81

def get_user_input():
	""" get user input
	initialize value outside bound to force user correct input"""
	
	h0 = -1.0
	while h0 <= 0.0:
		h0 = float(input("Enter initial height h0: "))

	eps = -1.0
	while (eps < 0.0) or (eps > 1.0):
		eps = float(input("Enter rebond coeff eps: "))
		
	hFin = -1.0
	while hFin <= 0:
		hFin = float(input("Enter final height: "))

	return h0, eps, hFin


def compute_nbr(h0, eps, hFin):

	nbr = 0
	hAfter = h0

	while hAfter > hFin:
		hBefore = hAfter
		vBefore = math.sqrt(2*g*hBefore)
		vAfter = vBefore*eps
		hAfter = vAfter*vAfter/(2*g)
		nbr += 1

	return nbr


def main():

	cNbr = compute_nbr(10, 0.9, 2)
	expectedNbr = 8
	if cNbr != expectedNbr:
		print("ERROR: computed result nbr = " + str(cNbr)
			+ " different from expected nbr = " + str(expectedNbr))
		return

	h0, eps, hFin = get_user_input()
	nbr = compute_nbr(h0, eps, hFin)
		
	print("After " + str(nbr) + " rebonds starting initially at h0 = "
		+ str(h0) + "m, heigth is now inferior to " + str(hFin) + "m")


if __name__ == "__main__":
	main()
