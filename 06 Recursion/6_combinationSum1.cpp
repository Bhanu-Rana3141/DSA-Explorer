#include<iostream>
#include<vector>
using namespace std;

void comb(vector<int>& arr, int& n, int i, int& sum, vector<int>& temp, vector<vector<int>>& ans, int target) {

    if(sum == target) {
        ans.push_back(temp);
        return;
    }
    if(sum > target) return;
    if(i >= n) return;

    sum += arr[i];
    temp.push_back(arr[i]);
    comb(arr, n, i, sum, temp, ans, target);

    sum -= arr[i];
    temp.pop_back();
    i++;
    comb(arr, n, i, sum, temp, ans, target);
}

int main()
{
    int n = 4;
    vector<int> arr = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans;
    vector<int> temp;
    int i = 0;
    int sum = 0;

    comb(arr, n, i, sum, temp, ans, target);

    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}