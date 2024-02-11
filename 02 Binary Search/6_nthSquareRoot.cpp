/*

APPROACH 1 - LINEAR
TC - O(M*N)
SC - O(1)

APPROACH 2 - BINARY
TC - O(N * LOG M)
SC - O(1)

*/

#include<iostream>
using namespace std;

int nthSquareRoot_1(int n, int m) {

    for(int i=1; i<=m; i++) {
        long long ans = 1;

        for(int j=1; j<=n; j++) {
            ans = ans * i;
            if(ans > m) {
                break;
            }
        }
        if(ans == m) {
            return i;
        }
    }
    return -1;
}

int root(int mid, int n, int m) {

    int ans = 1;
    for(int i=1; i<=n; i++) {
        ans = ans * mid;
        if(ans > m) {
            return 2;
        }
    }
    if(ans == m) {
        return 1;
    }
    return 0;
}

int nthSquareRoot_2(int n, int m) {

    int s = 1;
    int e = m;

    while(s <= e) {

        int mid = s+(e-s)/2;

        int nthRoot = root(mid, n, m);
        if(nthRoot == 1) {
            return mid;
        }
        else if(nthRoot == 0) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return -1;
}

int main() {

   int n = 3;
   int m = 27;

    // int ans = nthSquareRoot_1(n, m);
    int ans = nthSquareRoot_2(n, m);

    cout << "ans: " << ans;
    
    return 0;
}