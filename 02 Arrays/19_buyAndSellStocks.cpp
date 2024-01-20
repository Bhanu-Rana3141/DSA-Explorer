#include<iostream>
using namespace std;

/* BRUTE : USING NESTED LOOPS, TC - O(N^2), SC - O(1)
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
*/

// OPTIMAL - TRAVERSING ARRAY LINEARLY, TC - O(N), SC - 0(1)
int maxProfit(int arr[], int n) {

    int maxProfit = 0;
    int mini = arr[0];

    for(int i=1; i<n; i++) {
        int diff = arr[i] - mini;
        // update maxProfit on basis of this condition
        if(diff > maxProfit) {
            maxProfit = diff;
        }
        mini = min(mini, arr[i]);
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
    cout << "Profit : " << profit;
    
    
    return 0;
}