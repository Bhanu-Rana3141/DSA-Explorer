#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> arr = {1,2,3};
    int n = arr.size();
    int totalSubsets = 1 << n;

    vector<vector<int>> ans;
    for(int num = 0; num < totalSubsets; num++) {
        vector<int> sub;
        for(int i = 0; i<n; i++) {
            if(num & (1 << i)) {
                sub.push_back(arr[i]);
            }
        }
        ans.push_back(sub);
    }

    for(auto it : ans) {
        cout << "[";
        for(auto i : it) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}