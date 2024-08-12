#include<iostream>
#include<vector>
using namespace std;

int f(int n) {
    if(n == 0 || n == 1) return 1;
    return f(n-1) + f(n-2);
}

int mf(int n, vector<int>& dp) {
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = mf(n-1, dp) + mf(n-2, dp);
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    // cout << f(n);


    // vector<int> dp(n+1, -1);
    // cout << mf(n, dp);


    // vector<int> dp(n+1, -1);
    // dp[0] = 1;
    // dp[1] = 1;
    // for(int i = 2; i<=n; i++) {
    //     dp[i] = dp[i-1] + dp[i-2];
    // }
    // cout << dp[n];


    int prev1 = 1;
    int prev2 = 1;
    for(int i = 2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1;

    return 0;
}