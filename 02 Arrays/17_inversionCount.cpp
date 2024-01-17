/*
INVERSIONS COUNT : Basically in this question, we have to count how many number of swaps to be done to make the given array sorted

APPROACH 1 (BRUTE): NESTED LOOPS 
TC : O(n^2)
SC : O(1)

APPROACH 2 MERGE SORT 
*/

#include<iostream>
using namespace std;

int countInversions(int *arr, int n) {
    
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j] && i < j) {
                count++;
            }
        }
    }
    return count;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    
    int totalInversion = countInversions(arr, n);
    cout << "Total Inversions: " << totalInversion;
    
    return 0;
}