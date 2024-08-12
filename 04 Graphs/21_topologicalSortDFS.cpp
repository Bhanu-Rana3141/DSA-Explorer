#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

void print(unordered_map<int , vector<int>>& adj) {

    for(auto it : adj) {
        cout << it.first << " : ";
        for(auto i : it.second) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void dfs(int node, int vis[], stack<int>& st, unordered_map<int, vector<int>>& adj) {

    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}
 
int main()
{   
    int n = 6;

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<n; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    print(adj);
    
    int vis[n] = {0};
    stack<int> st;
    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop(); 
    }

    return 0;
}