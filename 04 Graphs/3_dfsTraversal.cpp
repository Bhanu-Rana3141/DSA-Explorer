#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
TC - O(N) -> recursive call for each node, O(2E) -> neighbours of node
O(N) + O(2E) -> O(N + E)

SC - visited, bfs vector, recursive call stack -> O(N)
*/

void dfsTraversal(int node, int visited[], unordered_map<int, vector<int>>& adj, vector<int>& dfs) {

    visited[node] = 1;
    dfs.push_back(node);

    for(auto it : adj[node]) {
        if(!visited[it]) {
            dfsTraversal(it, visited, adj, dfs);
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

    for(int i=0; i<m; i++) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency list: " << endl;
    for(auto i : adj) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    // dfs starts from here
    int visited[n] = {0};
    int start = 0;
    vector<int> dfs;

    dfsTraversal(start, visited, adj, dfs);

    cout << "dfs : ";
    for(auto it : dfs) {
        cout << it << " ";
    }
    
    return 0;
}