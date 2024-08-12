#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool dfs(int node, int col, int color[], unordered_map<int, vector<int>>& adj) {

    color[node] = col;

    for(auto it : adj[node]) {
        if(color[it] == -1) {
            if(dfs(it, !col, color, adj) == false) {
                return false;
            }
        }
        else if(color[it] == col) {
            return false;
        }
    }
    return true;
}

bool isBipartite(unordered_map<int, vector<int>>& adj, int n) {

    int color[n];
    for(int i = 0; i<n; i++) {
        color[i] = -1;
    }

    for(int i = 0; i<n; i++) {
        if(color[i] == -1) {
            if(dfs(i, 0, color, adj) == false) {
                return false;
            } 
        }
    }
    return true;
}

int main()
{   
    int n;
    cout << "Enter n: ";
    cin >> n;

    int m;
    cout << "Enter m: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<m; i++) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isBipartite(adj, n);

    return 0;
}