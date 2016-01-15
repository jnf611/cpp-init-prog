""" see .cpp exercice"""

use_int = input("use int ?")
if (use_int):
	# define variables as int
	x = 2 
	y = 4
else:
	# define variables as float
	x = 2.0;
	y = 4.0;
a = x + y;
b = x - y;
c = x * y;
d = x / y;
print("a = x + y = " + str(a))
print("b = x - y = " + str(b))
print("c = x * y = " + str(c))
print("d = x / y = " + str(d))
