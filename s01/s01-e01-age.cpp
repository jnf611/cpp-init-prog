#include <iostream>

using namespace std;

static const int year = 2019;

int main()
{
    int age;
    cout << "How old are you ? ";
    cin >> age;
    cout << "you are born in " << year - age << endl;
}

