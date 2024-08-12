#include<iostream>
#include<vector>
using namespace std;

// RECURSION
int fibo(int n) {
    if(n <= 1) {
        return n;
    }
    return fibo(n-1) + fibo(n-2);
}

// MEMOIZATION
int f(int n, vector<int>& dp) {
    if(n <= 1) {
        return n;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    return dp[n] = f(n-1, dp) + f(n-2, dp);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // RECURSION 
    // cout << fibo(n);


    // MEMOIZATION
    // vector<int> dp(n+1, -1);
    // cout << f(n, dp);


    // TABULATION
    // vector<int> dp(n+1, -1);
    // dp[0] = 0;
    // dp[1] = 1;

    // for(int i = 2; i<=n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }

    // cout << dp[n];


    // SPACE OPTIMISATION
    int prev2 = 0;
    int prev1 = 1;

    for(int i = 2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << prev1;

    return 0;
}