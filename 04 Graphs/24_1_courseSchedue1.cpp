#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int main()
{   
    int n = 2;
    vector<vector<int>> arr = {{1,0}, {0,1}};
    // vector<vector<int>> arr = {{1,0}};

    unordered_map<int, vector<int>> adj;
    for(auto it : arr) {
        adj[it[1]].push_back(it[0]);
    }

    vector<int> in(n,0);
    for(int i = 0; i<n; i++) {
        for(auto it : adj[i]) {
            in[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i<in.size(); i++) {
        if(in[i] == 0) q.push(i);
    }

    int cnt = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cnt++;

        for(auto it : adj[node]) {
            in[it]--;
            if(in[it] == 0) q.push(it);
        }
    }

    (cnt == n) ? cout << "true" : cout << "false"; 

    return 0;
}