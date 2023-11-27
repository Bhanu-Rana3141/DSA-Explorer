#include<iostream>
using namespace std;

void isSorted1(int arr[], int n) {

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > arr[j]) {
               cout << "Array is not sorted";
               return;
            }
        }
    }
    cout << "Array is sorted";
    cout << endl;
}

void isSorted2(int arr[], int n) {

    for(int i=1; i<n; i++) {
        if(arr[i-1] > arr[i]) {
            cout << "Array is not sorted";
            return;
        }
    }
    cout << "Array is sorted";
    cout << endl;
}

void isRotatedSorted(int arr[], int n) {

    int count = 0;

    for(int i=1; i<n; i++) {
        if(arr[i-1] > arr[i]) {
            count++;
        }
    }

    if(arr[n-1] > arr[0]) {
        count++;
    }

    if(count <= 1) {
        cout << "Array is sorted";
    }
    else{
        cout << "Array is not sorted";
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    isSorted1(arr,n);
    isSorted2(arr,n);
    isRotatedSorted(arr,n);

    return 0;
}