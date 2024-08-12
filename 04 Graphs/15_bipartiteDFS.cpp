#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

bool dfs(int node, int col, int *color, unordered_map<int, vector<int>> adj) {

    color[node] = col;
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            if(dfs(it, !col, color, adj) == false) {
                return false;
            }
        }
        else if(color[it] == color[node]) {
            return false;
        }
    }
    return true;
}

bool bfs(int node, int col, int *color, unordered_map<int, vector<int>> adj) {

    queue<int> q;
    q.push(node);
    color[node] = col;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int n, unordered_map<int, vector<int>> adj) {

    int color[n];
    for(int i = 0; i<n; i++) {
        color[i] = -1;
    }

    for(int i = 0; i<n; i++) {
        if(color[i] == -1) {
            if(bfs(i, 0, color, adj) == false) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    unordered_map<int , vector<int>> adj;
    for(int i = 0; i<m; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto it : adj) {
        cout << it.first << " : ";
        for(auto j : it.second) {
            cout << j << " ";
        }
        cout << endl;
    }    

    isBipartite(n, adj) ? cout << "bipartite" : cout << "not bipartite";
    
    return 0;
}