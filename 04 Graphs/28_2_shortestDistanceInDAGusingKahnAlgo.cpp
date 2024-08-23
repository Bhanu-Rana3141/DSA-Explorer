#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<limits.h>
using namespace std;

int main()
{
    int n = 6;
    int m = 7;
    vector<vector<int>> edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

    // 1. adj list
    unordered_map<int, vector<pair<int,int>>> adj;
    for(int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    cout << "Adjacency list : " << endl;
    for(auto it : adj) {
        cout << it.first << " -> ";
        for(auto i : it.second) {
            cout << "{ " << i.first << " , " << i.second << " }, "; 
        }
        cout << endl;
    }

    cout << endl << "indegree's : ";
    // 2. calculate indegree
    int indegree[n] = {0};
    for(int i = 0; i < n; i++) {
        for(auto it : adj[i]) {
            int v = it.first;
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << indegree[i] << " ";
    }

    cout << endl << endl;


    // 3. push nodes in queue having indegree as 0
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    // // 4. topo sort
    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]) {
            int v = it.first;
            indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << "topo sort : ";
    for(auto it : topo) {
        cout << it << " ";
    }
    cout << endl << endl;

    // 5. dis
    vector<int> dis(n, INT_MAX);
    dis[0] = 0;
    for(int i = 0; i < n; i++) {
        int node = topo[i];
        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dis[node] + wt < dis[v]) {
                dis[v] = dis[node] + wt;
            } 
        }
    }

    cout << "dis : "; 
    for(auto it : dis) {
        cout << it << " ";
    }

    return 0;
}