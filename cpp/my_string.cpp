#include <cstddef>
#include "my_string.hpp"

/* Invert the string */
void invert_string(char* str, int n)
{
	for (int i = 0; i < (n+1)/2; i++)
	{
		char tmp = str[n-i];
		str[n-i] = str[i];
		str[i] = tmp;
	}
}

/* Int to string conversion 
 * convert an integer to a c-string
 * return a pointer to the string or NULL*/
char* to_string(int n, char* str, int len)
{
	int i = 0;

	do
	{
		str[i] = (n%10) + 48;
		n /= 10;
		++i;
	}
	while(n && (i < len));

	if (i == len)
	{
		return NULL;
	}
	else
	{
		str[i] = '\0';
		invert_string(str, i-1);
		return str;
	}
}
