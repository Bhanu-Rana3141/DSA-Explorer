#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// recursion
int minimumEnergy(vector<int>& arr, int i) {

    if(i == 0) return 0;
    int left = minimumEnergy(arr, i-1) + abs(arr[i] - arr[i-1]);
    int right = INT_MAX;
    if(i > 1) {
        right = minimumEnergy(arr, i-2) + abs(arr[i] - arr[i-2]);
    }

    return min(left, right);
}

// memoization
int minimumEnergy(vector<int>& arr, int i, vector<int>& dp) {

    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];

    int left = minimumEnergy(arr, i-1, dp) + abs(arr[i] - arr[i-1]);
    int right = INT_MAX;
    if(i > 1) {
        right = minimumEnergy(arr, i-2, dp) + abs(arr[i] - arr[i-2]);
    }

    return dp[i] = min(left, right);
}

// tabulation
int f(vector<int>& arr, int n, vector<int>& dp) {

    dp[0] = 0;
    
    for(int i = 1; i<n; i++) {
        int fs = dp[i-1] + abs(arr[i] - arr[i-1]);
        int ss = INT_MAX;
        if(i > 1) {
            ss = dp[i-2] + abs(arr[i] - arr[i-2]);
        }

        dp[i] = min(fs, ss);
    }
    return dp[n-1];
}


int main()
{
    int n = 4;
    vector<int> arr = {10, 20, 30, 10};

    // cout << "minimum energy : " << minimumEnergy(arr, n-1);

    // vector<int> dp(n, -1);
    // cout << "minimum energy : " << minimumEnergy(arr, n-1, dp);


    // space optimisation
    int prev1 = 0;
    int prev2 = 0;

    for(int i = 1; i<n; i++) {
        int fs = prev1 + abs(arr[i] - arr[i-1]);
        int ss =  INT_MAX;
        if(i > 1) {
            ss = prev2 + abs(arr[i] - arr[i-2]);
        }
        
        int curr = min(fs, ss);
        prev2 = prev1;
        prev1 = curr;
    }

    cout << "ans: " << prev1;

    return 0;
}