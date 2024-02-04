/*
TC - O(N^2)
SC - O(N^2)
*/

#include<iostream>
#include<vector>
using namespace std;

void pascalTriangle(vector<vector<int>>& arr, int n) {

    for(int i=0; i<n; i++) {
        vector<int> ans;
        for(int j=0; j<=i; j++) {
            if(j == 0 || j == i) {
                ans.push_back(1);
            }
            else {
                int value = arr[i-1][j-1] + arr[i-1][j];
                ans.push_back(value);
            }
        }
        arr.push_back(ans);
    }
}

int main() {

    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector<int>> ans;
    pascalTriangle(ans, n);

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}