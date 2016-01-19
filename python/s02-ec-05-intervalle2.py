""" Semaine 02 exercice 05
see .cpp
"""

def test_belong_to_intervalle():

	inputs =          [-20.0, -10.0, -2.0,  -1.0,   0.0,  1.0,   1.5,  2.0,   3.0,   4.0]
	expected_result = [False,  True, True, False, False, True, False, True, False, False]
	res = True;

	if (len(expected_result) != len(inputs)):
		print("error bad test set lengthes")
	else:
		for i, x in enumerate(inputs):
			if belong_to_intervalle(x) != expected_result[i]:
				print("error : " + str(x) + ": " + str(belong_to_intervalle(x)))
				res = False
	if res:
		print("success")

	return res

def belong_to_intervalle(x):

	#I = [2,3[ U ]0,1] U [-10,-2]

	if (   (((-10.0 == x) or (-10.0 <  x)) and ((x < -2.0) or (x == -2.0)))
		or ( (  0.0 <  x)                  and ((x <  1.0) or (x ==  1.0)))
		or (((  2.0 <  x) or (2.0   == x)) and  (x <  3.0)                )	):
		return True
	else:
		return False

if __name__ == "__main__":

	test_belong_to_intervalle()
