#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*
TC - O(N) + O(2E) -> O(N+E)
- queue will store each node 1 time - O(N)
- neighbour nodes - O(2E)

SC : queue, visited, bfs -> O(3N) -> O(N)
*/

vector<int> bfsTraversal(int n, unordered_map<int, vector<int>>& adj) {

    queue<int> q;
    q.push(1);
    vector<int> visited(n+1 , 0);
    visited[1] = 1;
    vector<int> bfs;

    while(!q.empty()) {

        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]) {
            if(!visited[it]) {
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
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

    cout << endl << "adjacency list : " << endl;
    for(auto i : adj) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

    // solution starts from here
    vector<int> bfs = bfsTraversal(n, adj);

    cout << endl << "bfs: ";
    for(auto it : bfs) {
        cout << it << " ";
    }
    
    cout << endl;
    
    return 0;
}