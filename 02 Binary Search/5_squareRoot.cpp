/*
APPROACH 1 - LINEAR
TC - O(N)
SC - O(1)

APPROACH 2 - BINARY
TC - O(LOG N)
SC - O(1)
*/

#include<iostream>
using namespace std;

int squareRoot_1(int n) {

    int i = 1;
    int ans = 1;

    while(i*i <= n) {
        ans = i*i;
        i++;
    }
    return i-1;
}

int squareRoot_2(int n) {

    int s = 0;
    int e = n;
    int ans = -1;

    while(s <= e) {

        int mid = s + (e-s) / 2;

        if(mid * mid <= n) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    // int ans = squareRoot_1(n);
    int ans = squareRoot_2(n);

    cout << "ans: " << ans;

    return 0;
}