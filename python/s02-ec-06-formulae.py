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


def compute_and_display(callback, x):

	(defined, res) = callback(x)
	if defined:
		print(callback.__name__ + "(" + str(x) + ") = " + str(res))
	else:
		print(callback.__name__ + "(" + str(x) + ") is not defined")


def main():
	inputs = [-1.0, 0.0, 1.0, 2.0, 3.0, 8.0]

	for x in inputs:
		compute_and_display(e1, x)
		compute_and_display(e2, x)
		compute_and_display(e3, x)
		compute_and_display(e4, x)

if __name__ == "__main__":
	main()
