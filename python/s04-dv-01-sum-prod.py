#!/usr/bin/env python3
"""Semaine 4 Devoir 1"""

def sum_number(i):
    """Somme des chiffres d'un nombre"""
    sum_nb = 0

    while i > 0:
        sum_nb += i%10
        i //= 10

    return sum_nb


def product_number(i):
    """Produit des chiffres d'un nombre"""

    if i == 0:
        product = 0
    else:
        product = 1
        while i > 0:
            product *= i%10
            i //= 10

    return product


def unit_test_sum_number():
    """Unit tests for sum_number()"""
    if sum_number(0) != 0:
        return 1
    if sum_number(1) != 1:
        return 1
    if sum_number(12) != 3:
        return 1
    if sum_number(123) != 6:
        return 1

    return 0


def unit_test_product_number():
    """Unit tests for product_number()"""
    if product_number(0) != 0:
        return 1
    if product_number(1) != 1:
        return 1
    if product_number(12) != 2:
        return 1
    if product_number(123) != 6:
        return 1
    if product_number(1230) != 0:
        return 1

    return 0


def sum_product_equal(i):
    """Return True if the product of the numbers is equal to the sum of the
    numbers"""
    return sum_number(i) == product_number(i)


def unit_test_sum_product_equal():
    """Unit tests for sum_product_equal()"""
    if not sum_product_equal(0):
        return 1
    if not sum_product_equal(1):
        return 1
    if not sum_product_equal(2):
        return 1
    if sum_product_equal(12):
        return 1
    if not sum_product_equal(123):
        return 1

    return 0


def unit_tests():
    """Unit test script"""
    if unit_test_sum_number():
        print("error in sum_number")
        return 1
    if unit_test_product_number():
        print("error in product_number")
        return 1
    if unit_test_sum_product_equal():
        print("error in sum_product_equal")
        return 1

    return 0


def main():
    """Find first numbers which number product is equal to the number sum
    Example: 123 -> 1+2+3 = 6 = 1*2*3"""
    nb_found = 0
    i = 10
    string = ""

    while nb_found < 20:
        if sum_product_equal(i):
            string += str(i) + ", "
            nb_found += 1
        i += 1
    print(string)

    return 0

if __name__ == "__main__":

    if not unit_tests():
        main()
