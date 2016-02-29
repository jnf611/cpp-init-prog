/* s04 ec13
* tailor development cosinus
*/

#include <iostream>
#include <cmath>
using namespace std;

double factorielle(unsigned int n)
{
    double res = 1;

    for (unsigned int i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

const unsigned int max_uint = 85;

unsigned int get_uint()
{
    unsigned int ui;

    do
    {
        cout << "enter uint < " << max_uint << " : ";
        cin >> ui;
    }
    while (ui >= max_uint);

    return ui;
}

double cos_tailor_dev(double x, unsigned int n)
{
    double ret = 0.0;

    for (unsigned int i = 0; i <= n; ++i)
    {
        //ret += (pow(-1, i)*pow(x, 2*i))/factorielle(i);
        //avoid previous costly call to pow
        int sign = i%2?-1:1;
        ret += sign*pow(x, 2*i)/factorielle(i);
    }

    return ret;
}

int main()
{
    unsigned int n = get_uint(); // < max_uint;
    double x = 0.1;
    cout.precision(12);

    double res = cos_tailor_dev(x, n);
    cout << res << "/" << cos(x) << endl;

    return 0;
}
