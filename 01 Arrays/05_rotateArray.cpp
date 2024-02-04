/*
TC : INBUILT FUNCTION ROTATE  O(n) 
SC : O(1)
*/

#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverse(int arr[], int s, int e) {
    while(s <= e) {
        swap(arr[s], arr[e]);
        s++, e--;
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int k;
    cout << "Enter steps to rotate: ";
    cin >> k;

    k = k % n;

    // USING INBUILT FUNCTION ROTATE 

    // LEFT ROTATION - (arr.begin(), arr.begin() + k, arr.end())
    // rotate(arr, arr+k, arr+n);
    // printArray(arr, n);

    // RIGHT ROTATION  - (arr.begin(), arr.end()-k, arr.end())
    // rotate(arr, arr+n-k, arr+n);
    // printArray(arr, n);

    reverse(arr, 0, n-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);

    printArray(arr, n);
    
    return 0;
}