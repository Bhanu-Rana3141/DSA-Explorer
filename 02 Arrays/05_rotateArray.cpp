#include<iostream>
#include<algorithm>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    // LEFT ROTATION
    // rotate(arr, arr+k, arr+n);
    // printArray(arr, n);

    // RIGHT ROTATION 
    rotate(arr, arr+n-k, arr+n);
    printArray(arr, n);
    
    
    return 0;
}