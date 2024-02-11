/*
APPROACH 1 - LINEAR
TC - O(N)
SC - O(1)

APPROACH 2 - BINARY
TC - O(LOG N)
SC - O(1)
*/

#include<iostream>
using namespace std;

int uniqueElement_1(int *arr, int n) {

    // EDGE CASES
    if(n == 1) {
        return arr[0];
    }
    if(arr[0] != arr[1]) {
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]) {
        return arr[n-1];
    }

    for(int i=1; i<n-1; i++) {
        if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) {
            return arr[i];
        } 
    }
    return -1;
}

int uniqueElement_2(int *arr, int n) {

    // EDGE CASES
    if(n == 1) {
        return arr[0];
    }
    if(arr[0] != arr[1]) {
        return arr[0];
    }
    if(arr[n-1] != arr[n-2]) {
        return arr[n-1];
    }

    int s = 1;
    int e = n-2;

    while(s <= e) {
        int mid = s + (e-s)/2;
        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) {
            return arr[mid];
        }
        // eliminate left part
        else if((mid % 2 == 0 && arr[mid+1] == arr[mid]) || (mid % 2 != 0 && arr[mid-1] == arr[mid])) {
            s = mid + 1;
        }
        // eliminate right part
        else {
            e = mid - 1;
        }
    }
    return -1;
}

int main() { 

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // int ans = uniqueElement_1(arr, n);
    int ans = uniqueElement_2(arr, n);

    cout << "Unique element : " << ans;
    
    return 0;
}