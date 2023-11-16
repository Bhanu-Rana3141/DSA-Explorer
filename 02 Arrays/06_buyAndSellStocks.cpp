#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

/* Approach 1 -> Using nested loops -> O(n^2)

    int maxProfit = 0;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[j] - arr[i] > maxProfit) {
                maxProfit = arr[j] - arr[i];
            }
        }
    }
    cout << "Max profit : " << maxProfit;
*/
    
/* Approach 2 -> Using 2 pointers -> O(n)
    int maxProfit = 0;
    int i=0, j=n-1;

    while(i < j) {
        if(arr[j] - arr[i] > maxProfit) {
            maxProfit = arr[j] - arr[i];
        }
        j--;
        if(i == j) {
            i++, j=n-1;
        }
    }
    cout << "max profit: " << maxProfit;
*/

// Approach - 3 DP -> O(n)
    int mini = arr[0], profit = 0;
    for(int i=1; i<n; i++) {
        int diff = arr[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, arr[i]);
    }
    cout << "profit: " << profit;
}