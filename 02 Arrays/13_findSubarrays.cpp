/*
Sub array -> contigous part of array 
*/

#include<iostream>
using namespace std;

int subarrayMaxLen(int arr[], int n, int k) {

    int maxLen = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += arr[j];
            if(sum > k) {
                break;
            }
            else if(sum == k) {
                maxLen = max(maxLen, j-i+1);
                if(arr[j+1] != 0) {
                    break;
                }
            }
        }
    }
    return maxLen;
}


int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    cout << "Max Length of subarray is: " << subarrayMaxLen(arr, n, k);
    delete []arr;
    
    return 0;
}