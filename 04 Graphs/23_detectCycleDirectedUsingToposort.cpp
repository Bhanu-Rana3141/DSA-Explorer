#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    int n = 5;
    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<n; i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // compute indegree
    int in[] = {0};
    for(int i = 0; i<n; i++) {
        for(auto it : adj[i]) {
            in[it]++;
        }
    }

    // push vertices with indegree 0 in queue
    queue<int> q;
    for(int i = 0; i<n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    // use bfs
    int cnt = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it : adj[node]) {
            in[it]--;
            if(in[it] == 0) {
                q.push(it);
            } 
        }
    }

    if(cnt == n) {
        cout << "Not cyclic";
    }
    else {
        cout << "cyclic";
    }

    return 0;
}