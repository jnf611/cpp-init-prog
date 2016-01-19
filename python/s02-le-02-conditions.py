#!/usr/bin/env python3
"""
Cours S02 - 2. Conditions

Multiplication d'un boolean et affichage
"""

a = 5;
b = 2;
c = 5;
d = True;
e = False;

print("(a == b) = " + str(a == b));
print("(a == c) = " + str(a == c));
# overload for bool<< make implicit cast to int ?
print("d = " + str(d) + " and then (bool)d = " + str((bool(d))));

#guessing that there is a cast
print("2 * (a == b) = " + str(2 * (a == b)));
print("2 * (a == c) = ");
print(2 * (a == c));

print(type(a))
print(type(e))
e = a;
print("e = " + str(e))
print(type(e))
