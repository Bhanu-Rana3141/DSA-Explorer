#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void comb(vector<int>& arr, int& n, int& target, int i, int& sum, vector<int>& temp, vector<vector<int>>& ans) {

    if(sum > target) return;
    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(i >= n) return;

    sum += arr[i];
    temp.push_back(arr[i]);
    comb(arr, n, target, i+1, sum, temp, ans);

    sum -= arr[i];
    temp.pop_back();
    while(i+1 < n && arr[i] == arr[i+1]) i++;
    comb(arr, n, target, i+1, sum, temp, ans);
}

int main()
{
    int n = 5;
    vector<int> arr = {2,5,2,1,2};
    int target = 5;

    int sum = 0;
    vector<vector<int>> ans;
    vector<int> temp;

    sort(arr.begin() , arr.end());
    comb(arr, n, target, 0, sum, temp, ans);

    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " "; 
        }
        cout << endl;
    }

    return 0;
}