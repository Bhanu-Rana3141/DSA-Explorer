#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<limits.h>
using namespace std;

int main()
{
    int n = 9;
    int m = 10;
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    int src = 0;

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(dis[node] + 1 < dis[it]) {
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(dis[i] == INT_MAX) {
            dis[i] = -1;
        }
    }

    for(auto it : dis) {
        cout << it << " ";
    }

    return 0;
}