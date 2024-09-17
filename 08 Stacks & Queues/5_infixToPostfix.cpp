#include<iostream>
#include<stack>
using namespace std;

/*
1. operands - ans
2. opening bracket - stack
3. closing bracket
4. operator - priority
*/

// TC - O(N)  - each character is processed once
// SC - O(N) - stack, O(N) - ans

int priority(char ch) {

    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}

string infixToPostfix(string& s) {

    string ans = "";
    stack<char> st;

    for(int i = 0; i < s.size(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        // in worst case - all operands and operators can be present in this parenthesis - O(N) - each character is pushed and popped once
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            // worst case - all operators in stack are of greater precedence - O(N)
            while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string s = "(p+q)*(m-n)";

    string ans = infixToPostfix(s);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}