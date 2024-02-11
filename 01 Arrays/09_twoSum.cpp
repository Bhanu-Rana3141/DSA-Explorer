/*
BRUTE FORCE - using nested loops
TC -> O(n^2)
SC -> O(1) -> using fixed space, just 2 elements will be stored

OPTIMAL - using 2 pointer approach
TC -> O(n) + O(n log n) , if used sorting
WITHOUT SORTING -> O(n) 
SC -> O(1) -> changing in array, not using extra space
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// APPROCH 1
pair<int, int> twoSum_1(vector<int>&arr, int n, int target) {

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == target) {
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

// APPROACH 2
string twoSum_2(vector<int>&arr, int n, int target) {

    int i=0;
    int j=n-1;
   
    sort(arr.begin(), arr.end());

    while(i < j) {
        int sum = arr[i] + arr[j];
        if(sum == target) {
            return "YES";
        }
        else if(sum > target) {
            j--;
        }
        else{
            i++;
        }
    }
    return "NO";
}   

/*1. BRUTE

*/

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    // pair<int, int> p = twoSum_1(arr, n, target);
    // cout << p.first << " " << p.second;

    string ans = twoSum_2(arr, n, target);
    cout << ans;

    return 0;
}