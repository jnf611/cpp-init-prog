#!/usr/bin/env python3
"""
user input interaction
"""

def get_int(min_ui, max_ui):

	ret = 0;
	not_in_range = True;

	while not_in_range:
		msg = "enter integer";
		if min_ui >= max_ui:
			msg += " >= " + str(min_ui);
		else:
			msg += " between " + str(min_ui) + " and " + str(max_ui);
		msg += ": ";
		ret = int(input(msg));
		not_in_range = (ret < min_ui) or ((min_ui < max_ui) and (ret > max_ui))

	return ret;


def do_continue():

	ret = False

	c = str(raw_input("do you want to continue : "))
	if c == "o" or c == "O":
		ret = True;

	return ret;
