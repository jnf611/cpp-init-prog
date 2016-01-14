#!/usr/bin/env python3
"""
go to same exo in other language due to special french char
"""

import math

BASE          = 4;
fromage       = 800.0;
water         = 2.0;
garlic        = 2.0;
bread  = 400.0;
	
nb_people = input("how much people will attend the \"fondue\"? ");

if (nb_people > 0):
	print("you will need :\n" +
	"fromage: " + str((fromage * nb_people) / BASE) + "g\n" +
	"water:   " + str((water * nb_people) / BASE) + "dl\n" +
	"garlic:  " + str(math.ceil((garlic * nb_people) / BASE)) + "gousses\n" +
	"bread:   " + str((bread * nb_people) / BASE) + "g\n");
	
	
	#associativity in python : is the same as in c (at least for the +*/ operators
	print("fromage * nb_people / BASE = " + str(fromage * nb_people / BASE));
	print("(fromage * nb_people) / BASE = " + str((fromage * nb_people) / BASE)); 
	print("(nb_people * fromage) / BASE = " + str((nb_people * fromage) / BASE));
	print("nb_people * fromage / BASE = " + str(nb_people * fromage / BASE));
	print("nb_people / BASE * fromage = " + str(nb_people / BASE * fromage));
	print("(nb_people / BASE) * fromage = " + str((nb_people / BASE) * fromage));
