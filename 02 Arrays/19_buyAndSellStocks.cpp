#include<iostream>
using namespace std;

// BRUTE : USING NESTED LOOPS, TC - O(N^2), SC - O(1)
int maxProfit(int arr[], int n) {

    int maxProfit = 0;
    int profit = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            profit = max(profit, arr[j] - arr[i]);
        }
        maxProfit = max(maxProfit, profit);
    }
    return maxProfit;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int profit = maxProfit(arr, n);
    cout << "Max Profit: " << profit;
    
    return 0;
}