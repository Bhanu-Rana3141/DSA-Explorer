#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter array size: ";
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int hash[5] = {0};
    for(int i=0; i<n; i++) {
        hash[arr[i]]++;
    }

    // int q;
    // cout << "Enter no of elements to find frequency: ";
    // cin >> q;
    // while(q--) {
    //     int number;
    //     cin >> number;
    //     // cout << hash[number] << endl;
    // }

    for(int i=0; i<n; i++) {
        if(hash[i] != 0) {
            cout << arr[i] << " : " << hash[arr[i]] << endl;
        }
    }


    return 0;
}