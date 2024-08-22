// TC , SC - O(4^n * n)

#include<iostream>
#include<vector>
using namespace std;

void solve(string& digits, int index, string output, vector<string>& ans, vector<string>& mpp) {

    if(index >= digits.size()) {
        ans.push_back(output);
        return;
    }

    int num = digits[index] - '0';
    string value = mpp[num];

    for(int i = 0; i<value.size(); i++) {
        output.push_back(value[i]);
        solve(digits, index + 1, output, ans, mpp);
        output.pop_back();
    }
}

int main()
{
    string digits = "23";
    vector<string> ans;
    string output = "";
    int i = 0;
    vector<string> mpp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    solve(digits, i, output, ans, mpp);

    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}