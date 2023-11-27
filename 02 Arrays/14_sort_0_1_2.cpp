/*
SORTING 1 : O(n log n)
SORITNG 2 : O(n)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>&arr){
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

void sorting_1(vector<int>&arr) {
    sort(arr.begin(), arr.end());
}

void sorting_2(vector<int>&arr) {
    int n = arr.size();
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    // counting 0 1 2 
    for(int i=0; i<n; i++) {
        if(arr[i] == 0)  zeroCount++;
        else if(arr[i] == 1) oneCount++;
        else twoCount++;
    }

    // placing 0 1 2 in sorted manner
    for(int i=0; i<zeroCount; i++) arr[i] = 0;
    for(int i=zeroCount; i<zeroCount+oneCount; i++) arr[i] = 1;
    for(int i=zeroCount+oneCount; i<n; i++) arr[i] = 2;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // sorting_1(arr); 
    // printArray(arr);

    sorting_2(arr);
    printArray(arr);


}