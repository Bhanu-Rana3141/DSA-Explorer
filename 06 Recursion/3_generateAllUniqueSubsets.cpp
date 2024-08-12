#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void generateUniqueSubsets_2(vector<int>& arr, int n, int i, vector<int>& subset, vector<vector<int>>& ans) {

    if(i == n) {
        ans.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    generateUniqueSubsets_2(arr, n, i+1, subset, ans);

    subset.pop_back();

    while(i < n-1 && arr[i] == arr[i+1]) i++;
    generateUniqueSubsets_2(arr, n, i+1, subset, ans);
}

void generateUniqueSubsets_1(vector<int>& arr, int n, int i, vector<int>& subset, set<vector<int>>& st) {

    if(i == n) {
        st.insert(subset);
        return;
    }

    subset.push_back(arr[i]);
    generateUniqueSubsets_1(arr, n, i+1, subset, st);

    subset.pop_back();
    generateUniqueSubsets_1(arr, n, i+1, subset, st);
}

int main()
{   
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans;
    vector<int> subset;
    set<vector<int>> st;
    int i = 0;

    // generateUniqueSubsets(arr, arr.size(), i, subset, st);
    // ans.assign(st.begin() , st.end());
    // for(auto it : st) {
    //     vector<int> temp;
    //     for(auto i : it) {
    //         temp.push_back(i);
    //     }
    //     ans.push_back(temp);
    // }


    sort(arr.begin() , arr.end());
    generateUniqueSubsets_2(arr, arr.size(), i, subset, ans);

    for(int i = 0; i<ans.size(); i++) {
        cout << "[";
        for(int j = 0; j<ans[i].size(); j++) {
            if(j < ans[i].size() - 1) {
                cout << ans[i][j] << " ";
            }
            else {
                cout << ans[i][j];
            }
        }
        if(i < ans.size() - 1) {
            cout << "] , ";
        }
        else {
            cout << "]";
        }
    }

    return 0;
}