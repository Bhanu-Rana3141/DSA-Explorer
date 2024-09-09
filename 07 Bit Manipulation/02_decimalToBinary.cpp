#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n = 13;

    // int bin = 0;
    // while(n != 0) {
    //     int p = n % 2;
    //     bin = bin * 10 + p;
    //     n /= 2;
    // }

    string bin = "";
    while(n != 0) {
        if(n % 2 == 1) {
            bin += "1";
        }
        else {
            bin += "0";
        }
        n /= 2;
    }

    reverse(bin.begin(), bin.end());
    cout << bin;
    
    return 0;
}