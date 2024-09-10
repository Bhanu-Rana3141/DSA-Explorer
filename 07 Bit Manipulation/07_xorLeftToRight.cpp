#include<iostream>
using namespace std;

int main()
{
    int l = 4;
    int r = 8;

    int ans = 0;
    for(int i = l; i<=r; i++) {
        ans ^= i;
    }
    cout << ans;

    return 0;
}