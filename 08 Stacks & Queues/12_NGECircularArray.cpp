#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nge(vector<int>& arr, int& n) {

    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 2*n-1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }

        if(i < n) {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(arr[i % n]);
    }

    return ans;
} 

int main()
{
    int n = 5;
    vector<int> arr = {1,2,3,4,3};

    vector<int> ans = nge(arr, n);

    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}