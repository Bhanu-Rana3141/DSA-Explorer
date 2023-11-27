#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printArray(vector<int> &arr) {

    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void countFrequency(vector<int>&arr, int n) {

    for(int i=0; i<n; i++) {
        if(arr[i] == -1) {
            continue;
        }
        int count = 1;
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }
        cout << arr[i] << " : " << count << endl;  
    }
    return;
}

void countFrequency2(vector<int> &arr, int n) {

    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    for(auto it : mpp) {
        cout << it.first << " : " << it.second << endl;
    }
    return;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // countFrequency(arr, n);

    // printArray(arr);

    countFrequency2(arr, n);

    return 0;
}