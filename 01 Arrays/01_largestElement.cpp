/*
Approach 1 -> Sort Array and print last element
TC -> O(n log n)

Approach 2 -> create a variable and compare it with all other elements 
TC -> O(n)

*/


#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;
    
    int *arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    cout << "Max: " << arr[n-1] << endl;

    int maxi = arr[0];
    for(int i=1; i<n; i++) {
        maxi = max(maxi, arr[i]);
    }

    cout << "max: " << maxi;

    return 0;
}   