/*
TC - O(2^n) -> generating all subsets

SC - O(2^n)
O(2^n) -> storing all subsets
O(n) -> maximum recursive depth
O(n) -> worst case length of subset in subset vector 
*/

#include<iostream>
#include<vector>
using namespace std;

void generateAllSubsets(vector<int>& arr, int n, int i, vector<int>& subset, vector<vector<int>>& ans) {

    if(i == n) {
        ans.push_back(subset);
        return;
    }

    subset.push_back(arr[i]);
    generateAllSubsets(arr, n, i+1, subset, ans);

    subset.pop_back();
    generateAllSubsets(arr, n, i+1, subset, ans);
}

int main()
{   
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> subset;
    int i = 0;

    generateAllSubsets(arr, arr.size(), i, subset, ans);

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
    
    cout << endl;

    cout << "Total subsets : " << ans.size();

    return 0;
}