#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool dfs(int node, unordered_map<int, vector<int>>& adj, int vis[], int pathVis[]) {

    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis) == true) {
                return true;
            }
        }
        else if(pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}

bool isCyclic(unordered_map<int , vector<int>>& adj, int n) {

    int vis[n] = {0};
    int pathVis[n] = {0};

    for(int i = 0; i<n; i++) {
        if(!vis[i]) {
            if(dfs(i, adj, vis, pathVis) == true) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    int m;
    cout << "Enter m: ";
    cin >> m;

    unordered_map<int , vector<int>> adj;
    for(int i = 0; i<m; i++) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    

    // cout << isCyclic(adj, n);

    return 0;
}