#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0, dst = 3, k = 1;

    unordered_map<int, vector<pair<int,int>>> adj;
    for(auto it : flights) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adj[u].push_back({v, wt});
    }

    queue<pair<int, pair<int,int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[0] = 0;

    while(!q.empty()) {
        auto it = q.front();
        int stops = it.first;
        int node = it.second.first;
        int dis = it.second.second;
        q.pop();

        if(stops > k) continue;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int eW = it.second;
            if(dis + eW < dist[adjNode]) {
                dist[adjNode] = dis + eW;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }

    if(dist[dst] == 1e9) {
        cout << "Not possible to reach destination";
    }

    cout << dist[dst];

    return 0;
}