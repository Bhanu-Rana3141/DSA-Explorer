#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointSet {

    vector<int> rank, parent;

    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int findUlPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUlPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlPar(u);
        int ulp_v = findUlPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {

    vector<pair<int, pair<int,int>>> edges;
    // TC - O(V + E)
    for(int i = 0; i<V; i++) {
        for(auto it : adj[i]) {
            int node = i;
            int adjNode = it[0];
            int wt = it[1];
            
            edges.push_back({wt, {node, adjNode}});
        }
    }

    // O(E log E)
    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int sum = 0;
    // TC - O(E * 4a*2) *2 is for findPar and union
    for(auto it : edges) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUlPar(u) != ds.findUlPar(v)) {
            sum += wt;
            ds.unionByRank(u, v);
        }
    }

    return sum;
}

int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    cout << "min sum spanning tree: " << spanningTree(V, adj);

    return 0;
}