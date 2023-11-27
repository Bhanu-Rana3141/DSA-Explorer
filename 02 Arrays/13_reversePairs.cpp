#include<iostream>
#include<limits.h>
#include<algorithm>
#include<vector>
using namespace std;

int countPairs(vector<int>&arr, int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] > 2*arr[j]) count++;
        }
    }
    return count;
}

int countPairs2(vector<int>&arr, int n) {
    int i = 0, j = n-1, count = 0;
    while(i < j) {
        if(arr[i] > 2*arr[j]) {
            count++;
        }
        j--;
        if(i == j) {
            i++, j = n-1;
        }
    }
    return count;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;
    
    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int totalPairs = countPairs(arr, n);
    cout << "count: " << totalPairs << endl;

    int totalPairs2 = countPairs2(arr, n);
    cout << "count: " << totalPairs2;
    return 0;
}   