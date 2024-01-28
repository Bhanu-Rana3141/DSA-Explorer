/*
BRUTE - LINEAR SEARCH
* Take a element and check if a number next to it is present or not if yes then increment count by 1
* TC - O(N^2)
* SC - O(1)

OPTIMAL 1 - SET DATA STRUCTURE
* TC - O(N * LOG N)
* SC - O(N)

OPTIMAL 2 - SORT ARRAY & LINEAR TRAVERSE NEGLECT DUPLICATES
* TC - O(N*LOG N)
* SC - O(1)
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int getMaxLength1(vector<int> &arr, int n) {
    // EDGE CASES
    if(arr.size() == 0) {
        return 0;
    }
    if(arr.size() == 1) {
        return 1;
    }

    set<int> st;
    for(int i=0; i<arr.size(); i++) {
        st.insert(arr[i]);
    }

    vector<int>ans;
    for(auto it : st) {
        ans.push_back(it);
    }

    int cnt = 1;
    int maxCnt = 1;

    for(int i=0; i<n-1; i++) {
        if(ans[i] + 1 == ans[i+1]) {
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else {
            cnt = 1;
        }
    }
    return maxCnt;
} 

int getMaxLength2(vector<int> &arr, int n) {
    //EDGE CASES
    if(arr.size() == 0) {
        return 0;
    }
    if(arr.size() == 1) {
        return 1;
    }

    sort(arr.begin(), arr.end());

    int cnt = 1;
    int maxCnt = 1;

    for(int i=1; i<n; i++) {
        if(arr[i] == arr[i-1]) {
            continue;
        }
        else if(arr[i] == arr[i-1] + 1) {
            cnt++;
            maxCnt = max(cnt, maxCnt);
        }
        else {
            cnt = 1;
        }
    }
    return maxCnt;
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // cout << "Max Length: " << getMaxLength1(arr, n);
    cout << "Max Length : " << getMaxLength2(arr, n);
    
    return 0;
}