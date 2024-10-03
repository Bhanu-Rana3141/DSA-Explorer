#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> findPSE(vector<int>& arr, int n) {

    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return pse;
}

vector<int> findNSE(vector<int>& arr, int n) {

    vector<int> nse(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return nse;
}

int main()
{
    vector<int> arr = {3,1,2,4};
    int n = arr.size();
    int mod = 1e9 + 7;

    vector<int> pse = findPSE(arr, n);
    vector<int> nse = findNSE(arr, n);

    int totalSum = 0;
    for(int i = 0; i<n; i++) {
        int left = i - pse[i];
        int right = nse[i] - i;

        totalSum = (totalSum + (left * right * arr[i]) % mod) % mod;
    }

    cout << "total sum : " << totalSum;

    return 0;
}