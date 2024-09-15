#include<iostream>
#include<vector>
using namespace std;

// For negative edge weights and negative cycles

vector<int> bellmanFord(vector<vector<int>>& edges, int n, int src) {

    // SC - O(V)
    vector<int> dist(n, 1e8);
    dist[src] = 0;

    // TC - O(V * E)
    for(int i = 0; i < n-1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    int src = 2;

    vector<int> dist =  bellmanFord(edges, n, src);
    
    for(auto it : dist) {
        cout << it << " ";
    }

    return 0;
}