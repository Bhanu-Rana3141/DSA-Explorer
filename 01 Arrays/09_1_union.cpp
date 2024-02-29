/* 
APPROACH 1 : SET
* TC : O(n*log n) + O(n*log m) -> O(n+m) * log(max(n,m))
* SC : O(n+m)

APPROACH 2: 2 POINTER
* TC : O(n+m)
* SC : O(n+m)
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// APPROACH 1
void unionArray(vector<int>& arr1, int n, vector<int>&arr2, int m) {

    set<int> st;
    
    for(int i=0; i<n; i++) {
        st.insert(arr1[i]);
    }

    for(int i=0; i<m; i++) {
        st.insert(arr2[i]);
    }

    for(int element : st) {
        cout << element << " ";
    }
    return;
}

// APPROACH 2
void unionArr(vector<int>& arr1, int n, vector<int>&arr2, int m) {

    vector<int>ans;

    int i = 0;
    int j = 0;

    while(i < n && j < m) {
        // condition for not including duplicates in ans 
        if(ans.size() == 0 || (arr1[i] != ans[ans.size()-1] && arr2[j] != ans[ans.size()-1])) {
            if(arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i] == arr2[j]) {
                ans.push_back(arr1[i]);
                i++, j++;
            }
            else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        else {
            if(arr1[i] == ans[ans.size()-1]) {
                i++;
            }
            else {
                j++;
            }
        }
    }

    while(i < n) {
        if(arr1[i] != ans[ans.size()-1]) {
            ans.push_back(arr1[i]);
            i++;
        }
    }

    while(j < m) {
        if(arr2[j] != ans[ans.size()-1]) {
            ans.push_back(arr2[j]);
            j++;
        }
    }

    for(auto it : ans) {
        cout << it << " ";
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr1(n);
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    int m;
    cout << "Enter m: ";
    cin >> m;

    vector<int>arr2(m);
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }

    // unionArray(arr1, n , arr2, m);
    unionArr(arr1, n, arr2, m);

    return 0;
}