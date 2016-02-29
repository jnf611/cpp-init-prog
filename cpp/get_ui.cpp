#include <iostream>
#include "get_ui.hpp"
using namespace std;

int get_ui_int(int min_ui, int max_ui)
{
	int ret = 0;

	do
	{
		cout << "enter integer";
		if (min_ui >= max_ui)
		{
			cout << " >= " << min_ui;
		}
		else
		{
			cout << " between " << min_ui << " and " << max_ui;
		}
		cout << ": ";
		cin >> ret;
	}
	while ((ret < min_ui) || ((min_ui < max_ui) && (ret > max_ui)));

	return ret;
}

bool get_ui_continue()
{
	char c = 'n';
	bool ret = false;

	cout << "do you want to continue [o/n]: ";
	cin >> c;
	if (c == 'o' || c == 'O')
	{
		ret = true;
	}

	return ret;
}
