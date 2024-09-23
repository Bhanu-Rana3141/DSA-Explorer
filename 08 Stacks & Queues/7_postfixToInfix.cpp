#include<iostream>
#include<stack>
#include<string>
using namespace std;

string postfixToInfix(string& s) {

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

            string temp = "(" + top2 + s[i] + top1 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main()
{
    string s = "AB-DE+F*/";

    string ans = postfixToInfix(s);

    cout << ans;

    return 0;
}