#include<iostream>
using namespace std;

int main()
{
    int n = 13;
    int k = 2;

    int leftShift = (n & (1 << k)) != 0;
    int rightShift = (1 & (n >> k)) != 0;

    cout << leftShift << " " << rightShift << endl;

    return 0;
}