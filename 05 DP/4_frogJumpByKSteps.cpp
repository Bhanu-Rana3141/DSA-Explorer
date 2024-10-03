#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int rf(int i, vector<int>& arr, int k) {

    if(i == 0) return 0;
    int minSteps = INT_MAX;

    for(int j = 1; j<=k; j++) {
        if(i-j >= 0) {
            int jump = rf(i-j, arr, k) + abs(arr[i] - arr[i-j]);
            minSteps = min(minSteps, jump);
        }
    }
    return minSteps;
}

int mf(int i, vector<int>& arr, int k, vector<int>& dp) {

    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
    int minSteps = INT_MAX;

    for(int j = 1; j<=k; j++) {
        if(i-j >= 0) {
            int jump = mf(i-j, arr, k, dp) + abs(arr[i] - arr[i-j]);
            minSteps = min(minSteps, jump);
        }
    }

    return dp[i] = minSteps;
}

int tf(int n, vector<int>& arr, int k, vector<int>& dp) {

    dp[0] = 0;

    for(int i = 1; i<n; i++) {
        
        int minSteps = INT_MAX;
        for(int j = 1; j<=k; j++) {
            if(i-j >= 0) {
                int jump = dp[i-j] + abs(arr[i] - arr[i-j]);
                minSteps = min(minSteps, jump);
            } 
        }
        dp[i] = minSteps;
    }

    return dp[n-1];
}

int main()
{
    int k = 3;
    vector<int> arr = {10, 30, 40, 50, 20};
    int n = arr.size();

    // cout << rf(n-1, arr, k);

    vector<int> dp(n, -1);
    // cout << mf(n-1, arr, k, dp);

    cout << tf(n, arr, k, dp);


    


    return 0;
}