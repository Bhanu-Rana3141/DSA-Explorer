#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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

int main() {

    int n = 3;
    vector<vector<int>> arr = {{1,0,0},{0,1,0},{0,0,1}};

    DisjointSet ds(n);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(arr[i][j] == 1) {
                ds.unionByRank(i, j);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i<n; i++) {
        if(ds.parent[i] == i) {
            cnt++;
        }
    }

    cout << "total provinces: " << cnt;

    return 0;
}