#include<iostream>
using namespace std;

// int hashh[10]; -> if declared globally every element get's initialised as 0 instead of garbage value

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;


    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int q;
    cout << "Enter q: ";
    cin >> q;

    int hash[13] = {0};
    
    for(int i=0; i<n; i++) {
        hash[arr[i]] += 1; // hash needs a integer, it goes on integer and increment value by 1
    }

    while(q--) {
        int num;
        cin >> num;
        cout << hash[num] << " ";
    }

    

    return 0;
}