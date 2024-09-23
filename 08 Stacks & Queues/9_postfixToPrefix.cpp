#include<iostream>
#include<stack>
using namespace std;

string postfixToPrefix(string& s) {

    stack<string> st;

    for(int i = 0; i < s.size(); i++) {
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

            string temp = s[i] + top2 + top1;
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";

    string ans = postfixToPrefix(s);

    cout << ans;

    return 0;
}