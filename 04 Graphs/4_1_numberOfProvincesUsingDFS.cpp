#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, unordered_map<int, vector<int>> adj) {

    visited[node] = 1;

    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfs(it, visited, adj);
        }
    }
}

int main() {

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    int m;
    cout << "Enter no of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;

    for(int i = 0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency list : " << endl;
    for(auto i : adj) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    // number of provinces
    vector<int> visited(n, 0);

    int cnt = 0;
    for(int i = 1; i<=n; i++) {
        if(!visited[i]) {
            cnt++;
            dfs(i, visited, adj);
        }
    }

    cout << "Total provinces: " << cnt;
    
    return 0;
}