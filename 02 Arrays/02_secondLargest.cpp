/*
Approach 1 -> Sort Array and print second last element if array does not contain duplicate elements
TC -> O(n log n)

Approach 2 -> 3 traversals
1. find max
2. place -1 at all the positions where elements are equal to max
3. now again find max, this will be the second max
TC -> O(n)

Approach 3 -> 2 traversals
1. find max
2. comapare second max with other elements and specify a condition for duplicacy
    secondMax > arr[i] && secondMax < max
TC -> O(n)

APPROACH 4 -> one traversal
TC -> O(n)

*/

#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

/* 3 APPROACHES
int approach_1(vector<int>&arr){
    sort(arr.begin(), arr.end());
    return arr[arr.size()-2];
}

int maxElement(vector<int>&arr) {
    int maxi = INT_MIN;

    for(int i=0; i<arr.size(); i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int approach_2(vector<int>&arr) {
    
    int max = maxElement(arr);
        
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] == max) {
            arr[i] = -1;
        }
    }
    int secondMax = maxElement(arr);
    return secondMax;
}

int approach_3(vector<int>&arr) {

    int max = maxElement(arr);

    int secondMax = INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}
*/

void secondMax(vector<int>& arr) {

    int max = INT_MIN;
    int secondMax = INT_MIN;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        else if(arr[i] > secondMax && arr[i] != max){ 
            secondMax = arr[i];
        }
    }
    cout << "max: " << max << endl;
    cout << "second max: " << secondMax << endl;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // cout << "second max: " << approach_1;
    // cout << "second max: " << approach_2(arr);
    // cout << "second max: " << approach_3(arr);

    secondMax(arr);
    

    return 0;
}