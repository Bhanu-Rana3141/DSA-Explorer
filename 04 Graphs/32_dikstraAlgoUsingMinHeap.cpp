#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

// Q. Why only for positive edge weights ?
// because this algo is used to find the shortest path, if it contains the negative edgeweights in that case it will stuck in infinite loop

vector<int> dijkstra(int n, vector<vector<int>> adj[], int src) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
            }
        }
    }
    return dist;
}

int main()
{
    int n = 2;
    vector<vector<int>> adj [] = {{{1, 9}}, {{0, 9}}};
    int src = 0;
    
    vector<int> dist = dijkstra(n, adj, src);

    for(auto it : dist) {
        cout << it << " ";
    }

    return 0;
}