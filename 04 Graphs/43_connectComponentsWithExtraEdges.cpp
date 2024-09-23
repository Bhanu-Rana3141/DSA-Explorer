#include<iostream>
#include<vector>
using namespace std;

/*
1. extra edge - if ulpar of u and v are same
2. ulpar
3. extra edge >= ulPar
*/

class DisjointSet {

    public :

    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i = 0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int ulPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = ulPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int upu = ulPar(u);
        int upv = ulPar(v);
        
        if(upu == upv) return;

        if(rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else if(rank[upv] < rank[upu]) {
            parent[upv] = upu;
        }
        else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};

int connectComponents(int n, vector<vector<int>>& edges) {

    DisjointSet ds(n);

    int extraEdges = 0;
    for(auto it : edges) {
        int u = it[0];
        int v = it[1];

        if(ds.ulPar(u) == ds.ulPar(v)) {
            extraEdges++;
        }
        else {
            ds.unionByRank(u, v);
        }
    }

    int cntComp = 0;
    for(int i = 0; i<n; i++) {
        if(i == ds.parent[i]) {
            cntComp++;
        }
    }

    if(extraEdges >= cntComp-1) {
        return extraEdges;
    }
    return -1;
}

int main()
{
    int n = 9, m = 8;
    vector<vector<int>> edges = {{0,1},{0,2},{0,3},{1,2},{2,3},{4,5},{5,6},{7,8}};

    cout << "extra edges: " << connectComponents(n, edges);

    return 0;
}