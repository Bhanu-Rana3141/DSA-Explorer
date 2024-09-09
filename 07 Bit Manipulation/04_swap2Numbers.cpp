#include<iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 2;
    cout << a << " " << b << endl;

    a = a^b;
    b = b^a;
    a = a^b;

    cout << a << " " << b;

    return 0;
}