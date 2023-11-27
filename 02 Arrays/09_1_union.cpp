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

    int i=0, j=0;
    while(i<n && j<m) {
        if(arr1[i] == arr2[j]) {
            ans.push_back(arr1[i]);
            i++, j++;
        }
        else if(arr1[i] < arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
        }
        else{
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