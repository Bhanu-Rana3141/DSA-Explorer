/*
APPROACH 1 - LINEAR SEARCH
TC - O(N)
SC - O(1)

APPROACH 2 - BINARY SEARCH
EC - O(LOG N)
SC - O(1)
*/

#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int key){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {

    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    int index = binarySearch(arr, n, key);

    cout << "Key found at index: " << index;
    return 0;
}