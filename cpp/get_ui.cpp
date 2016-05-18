#include <iostream>
#include <vector>
#include "get_ui.hpp"
using namespace std;

/* Ask user for integer in interval or superior or egal to a number */
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

/* Ask user for values of a double vector */
vector<double> get_ui_vector_double(size_t n, const string& name)
{
	vector<double> v(n);

	cout << "enter values of double vector " << name
		<< " of length " << n << ":" << endl;
	for (size_t i = 0; i < n; ++i)
	{
		cout << "  " << name << "[" << i << "]: ";
		cin >> v[i];
	}

	return v;
}

/*
 * Ask user for values of a double matrix
 */
vector<vector<double>> get_ui_matrix(size_t max_n, const string& name)
{
	cout << "enter value of matrix " << name << ":" << endl;
	cout << "  enter row number:" << endl;
	size_t m = get_ui_int(0, max_n);
	cout << "  enter column number:" << endl;
	size_t n = get_ui_int(0, max_n);

	vector<vector<double>> Mat(m, vector<double>(n));
	for (size_t i = 0; i < m; ++i)
	{
		cout << "  enter values of row " << i << ": " << endl;
		for (size_t j = 0; j < n; ++j)
		{
			cout << "    " << name << "[" << i << "," << j << "]: ";
			cin >> Mat[i][j];
		}
	}

	return Mat;
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
