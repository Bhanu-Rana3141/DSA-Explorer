#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{   
    int n = 6;
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<n; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(u);
    }

    int indegree[n] = {0};
    for(int i = 0; i<n; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }


    return 0;
}