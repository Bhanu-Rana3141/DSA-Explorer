#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void perm(vector<int>& temp, int pos, vector<vector<int>>& ans) {

    if(pos == temp.size()) {
        ans.push_back(temp);
        return;
    }

    unordered_set<int> st;
    for(int i = pos; i<temp.size(); i++) {
        if(st.find(temp[i]) != st.end()) continue;
        st.insert(temp[i]);
        swap(temp[i] , temp[pos]);
        perm(temp, pos+1, ans);
        swap(temp[i] , temp[pos]);
    }
}

int main()
{   
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans;
    vector<int> temp = nums;

    perm(temp, 0, ans);

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