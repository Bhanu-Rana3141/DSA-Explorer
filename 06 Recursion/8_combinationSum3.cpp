#include<iostream>
#include<vector>
using namespace std;

void comb(int i, int& sum, vector<int>& temp, vector<vector<int>>& ans, int k, int n) {

    if(sum > n) return;
    if(k == 0) {
        if(sum == n) {
            ans.push_back(temp);
            return;
        }
        return;
    }
    if(i == 10) return;

    sum += i;
    temp.push_back(i);
    k--;
    comb(i+1, sum, temp, ans, k, n);

    sum -= i;
    k++;
    temp.pop_back();
    comb(i+1, sum, temp, ans, k, n);
}

int main()
{
    int k = 3;
    int n = 7;

    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    
    comb(1, sum, temp, ans, k, n);

    for(int i = 0; i<ans.size(); i++) {
        for(int j = 0; i<ans[i].size(); j++) {
            if(ans[i][j] >= 1 && ans[i][j] < 10) {
                cout << ans[i][j] << " ";
            }
            else {
                break;
            }
        }
        cout << endl;
    }

    return 0;
}