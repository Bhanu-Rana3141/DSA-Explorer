#include<iostream>
#include<vector>
using namespace std;

void perm(int pos, string& s, vector<string>& ans) {

    if(pos == s.size()) {
        ans.push_back(s);
        return;
    }

    for(int i = pos; i<s.size(); i++) {
        swap(s[i], s[pos]);
        perm(pos + 1, s, ans);
        swap(s[i], s[pos]);
    }
}

int main()
{
    vector<string> ans;
    string s = "abc";
    string temp = s;

    perm(0, temp, ans);

    for(int i = 0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}