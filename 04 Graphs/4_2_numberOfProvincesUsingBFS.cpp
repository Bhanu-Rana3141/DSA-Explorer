#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int node, vector<int>& vis, unordered_map<int, vector<int>> adj) {

    queue<int> q;
    q.push(node);
    vis[node] = 1;

    while(!q.empty()) {
        
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

int main() {

    int n = 3;
    vector<vector<int>> arr = {{1,0,0},{0,1,0},{0,0,1}};

    unordered_map<int, vector<int>> adj;

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }    

    int cnt = 0;
    vector<int> vis(n, 0);

    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            cnt++;
            bfs(i, vis, adj);
        }
    }
    
    cout << "total province: " << cnt;

    return 0;
}