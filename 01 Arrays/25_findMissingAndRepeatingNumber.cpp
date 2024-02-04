/*
APPROACH 1
* Use nested loops to count frequency and find DUPLICATE - O(N^2)
* sort and find MISSING - O(N*LOG N) - FOR SORTING AND O(N) - FOR FINDING MISSING ELEMENT
* TC - O(N*LOGN) + O(N^2) - O(N^2)
* SC - 0(1)

APPROACH 2
* sort array - O(N*LOG N)
* Find duplicate - O(N)
* Find missing - O(N)
* TC - O(N*LOG N)
* SC - O(1)

APPROACH 3
* Hashing 
* TC - O(N)
* SC - O(N)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// APPROACH 2
/*
vector<int> findDuplicateAndMissing(vector<int> &arr, int n) {

    sort(arr.begin(), arr.end());

    // duplicate
    int duplicate = -1;
    for(int i=1; i<n; i++) {
        if(arr[i] == arr[i-1]) {
            duplicate = arr[i];
        }
    }

    // missing
    int missing = -1;
    if(arr[n-1] != n) {
        missing = n;
    }
    else {
        for(int i=0; i<n-1; i++) {
            if(i+1 != arr[i]) {
                missing = i+1;
                break;
            }
        }
    }
    return {duplicate, missing};
}
*/

// APPROACH 3
vector<int> findDuplicateAndMissing(vector<int> &arr, int n) {

    vector<int>hash(n+1,0);
    for(int i=0; i<n; i++) {
        hash[arr[i]]++;
    }

    int duplicate = -1;
    int missing = -1;

    for(int i=1; i<=n; i++) {
        if(hash[i] == 2) {
            duplicate = i;
        }
        if(hash[i] == 0) {
            missing = i;
        }
    }
    return {duplicate, missing};
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = findDuplicateAndMissing(arr, n);
    cout << "duplicate: " << ans[0] << " , " << "missing: " << ans[1];
    
    return 0;
}