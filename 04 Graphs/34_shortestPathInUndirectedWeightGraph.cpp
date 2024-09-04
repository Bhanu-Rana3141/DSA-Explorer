#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> shortestPath(int n, unordered_map<int, vector<pair<int,int>>>& adj) {

    vector<int> dist(n+1, 1e9), parent(n+1, 1e9);
    parent[1] = 1;
    // for(int i = 1; i<=n; i++) {
    //     parent[i] = i;
    // }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()) {
        auto it  = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int eW = it.second;

            if(dis + eW < dist[adjNode]) {
                dist[adjNode] = dis + eW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if(dist[n] == 1e9) return {-1};
    cout << dist[n] << endl;

    vector<int> path;
    int node = n;
    while(node != parent[node]) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n = 5, m = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    unordered_map<int, vector<pair<int,int>>> adj;
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> path = shortestPath(n, adj);

    for(auto it : path) {
        cout << it << " ";
    }

    return 0;
}