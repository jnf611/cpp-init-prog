"""
see .cpp
"""
import math

def e1(x):

	if x != 0.0:
		return True, x / (1.0 - math.exp(x))
	else:
		return False, float("nan")


def e2(x):

	if (x > 0.0) and (x != 1.0):
		return True, x * math.log(x) * math.exp(2 / (x - 1))
	else:
		return False, float("nan")


def e3(x):
	tmp1 = x*x - 8*x;

	if (tmp1 >= 0.0) and (x != 2.0):
		return True, (-x - math.sqrt(tmp1)) / (2 - x)
	else:
		return False, float("nan")


def e4(x):

	if x != 0:
		tmp1 = x*x - 1/x;
		if tmp1 > 0.0:
			tmp2 = (math.sin(x) - x/20) * math.log(tmp1);
			if tmp2 >= 0:
				return True, math.sqrt(tmp2)

	return False, float("nan")


def main():
	inputs = [-1.0, 0.0, 1.0, 2.0, 3.0, 8.0]

	for x in inputs:
		(defined, res) = e1(x)
		if defined:
			print("e1(" str(x) ") = " + str(res))
		else:
			print("e1(" str(x) ") is not defined")

		(defined, res) = e2(x)
		if defined:
			print("e2(" str(x) ") = " + str(res))
		else:
			print("e2(" str(x) ") is not defined")
		(defined, res) = e3(x)
		if defined:
			print("e3(" str(x) ") = " + str(res))
		else:
			print("e3(" str(x) ") is not defined")
		(defined, res) = e4(x)
		if defined:
			print("e4(" str(x) ") = " + str(res))
		else:
			print("e4(" str(x) ") is not defined")


if __name__ == "__main__":
	main()
