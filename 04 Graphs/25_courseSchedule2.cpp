#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int n = 4;
    vector<vector<int>> arr = {{1,0},{2,0},{3,1},{3,2}};

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<n; i++) {
        int u = arr[i][1];
        int v = arr[i][0];
        adj[u].push_back(v);
    }

    vector<int> in(n, 0);
    for(int i = 0; i<n; i++) {
        for(auto it : adj[i]) {
            in[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]) {
            in[it]--;
            if(in[it] == 0) {
                q.push(it);
            }
        }
    }

    for(auto it : ans) {
        cout << it << " ";  
    }

    return 0;
}