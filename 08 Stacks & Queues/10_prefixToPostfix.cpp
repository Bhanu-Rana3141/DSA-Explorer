#include<iostream>
#include<stack>
using namespace std;

string prefixToPostfix(string& s) {

    stack<string> st;

    for(int i = s.size()-1; i >= 0; i--) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            string str = "";
            str += s[i];
            st.push(str);
        }
        else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();

            string temp = top1 + top2 + s[i];
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string s = "/-AB*+DEF";

    string ans = prefixToPostfix(s);

    cout << ans;

    return 0;
}