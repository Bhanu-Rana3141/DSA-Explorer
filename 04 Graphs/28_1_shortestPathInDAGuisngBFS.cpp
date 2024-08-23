#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

void dfs(int node, int vis[], unordered_map<int, vector<pair<int,int>>>& adj, stack<int>& st) {

    vis[node] = 1;

    for(auto it : adj[node]) {
        int v = it.first;
        if(!vis[v]) {
            dfs(v, vis, adj, st);
        }
    }
    st.push(node);
}

int main()
{

    int n = 6;
    int m = 7;
    vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

    // 1. adj list
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    // 2. topo sort
    stack<int> st;
    int vis[n] = {0};

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    // 3. dist
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;

    while(!st.empty()) {

        int node = st.top();
        st.pop();

        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dis[node] + wt < dis[v]) {
                dis[v] = dis[node] + wt;
            } 
        }
    }

    // 4. output
    for(int i = 0; i < n; i++) {
        cout << dis[i] << " ";
    }

    return 0;
}