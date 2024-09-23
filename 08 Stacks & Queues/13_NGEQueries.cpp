#include<iostream>
#include<vector>
using namespace std;

int nge(int idx, vector<int>& arr, int n) {
        
    int cnt = 0;
    for(int i = idx+1; i<n; i++) {
        if(arr[i] > arr[idx]) {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    
    vector<int> arr = {1, 2, 3, 4, 1};
    int n = arr.size();
    int queries = 2;
    int indices[] = {0, 3};

    vector<int> ans;
        
    for(int i = 0; i<queries; i++) {
        int cnt = nge(indices[i], arr, n);
        ans.push_back(cnt);
    }

    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}