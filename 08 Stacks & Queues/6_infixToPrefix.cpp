#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

/*
1. reverse string 
    reverse brackets
2. operands - ans
3. opening bracket - stack
4. closing bracket
5. operator - priority 
    if ^ , <= 
    else <
6. reverse ans
*/

// TC - O(N)  
// SC - O(N)

int priority(char ch) {

    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPrefix(string s) {

    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            s[i] = ')';
        }
        else if(s[i] == ')') {
            s[i] = '(';
        }
    }

    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if(s[i] == '^') {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s = "x+y*z/w+u";

    string ans = infixToPrefix(s);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}