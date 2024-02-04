/*
BRUTE - Using Nested Loops
TC - O(N^2)
SC - O(N) - in worst case if all the elements are present just once - 
Ex : [1,2,3,4] , if this is the array here all the elements of array will be stored in ans array

OPTIMAL - Moore's Voting Algorithm
TC - O(N)
SC - O(1)
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> majorityElement1(vector<int> &arr) {
    int n = arr.size();

    vector<int> ans;
    for(int i=0; i<n; i++) {
        int count = 1;
        if(arr[i] == '~') {
            continue;
        }
        for(int j=i+1; j<n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = '~';
            }
        }
        if(count > (n/3)) {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

vector<int> majorityElement2(vector<int>& arr) {
    int n = arr.size();

    vector<int> ans;
    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;

    for(int i=0; i<n; i++) {
        if(count1 == 0 && arr[i] != element2) {
            count1 = 1;
            element1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != element1) {
            count2 = 1;
            element2 = arr[i];
        }
        else if(element1 == arr[i]) {
            count1++;
        }
        else if(element2 == arr[i]) {
            count2++;
        }
        else {
            count1--;
            count2--;
        }
    }   

    count1 = 0;
    for(int i=0; i<n; i++) {
        if(element1 == arr[i]) {
            count1++;
        }
    }

    count2 = 0;
    for(int i=0; i<n; i++) {
        if(element2 == arr[i]) {
            count2++;
        }
    }

    if(count1 > (n/3)) {
        ans.push_back(element1);
    }

    if(count2 > (n/3)) {
        ans.push_back(element2);
    }
    return ans;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // vector<int> ans = majorityElement1(arr);
    vector<int> ans = majorityElement2(arr);

    for(auto it : ans) {
        cout << it << " ";
    }    
    
    return 0;
}