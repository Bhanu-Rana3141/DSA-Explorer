#include<iostream>
using namespace std;

int main()
{
    int bin = 1101;
    int dec = 0;
    int pow = 1;

    while(bin != 0) {
        int ld = bin % 10;
        dec += pow * ld;
        pow *= 2;
        bin /= 10;
    }

    cout << dec;

    return 0;
}