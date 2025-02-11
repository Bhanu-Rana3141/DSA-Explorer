#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

vector<int> topoSort(int &n, unordered_map<int, vector<int>>& adj) {

    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    
    return topo;
}

int main()
{
    int n = 5;
    int k = 4;
    vector<string> dict = {"baa","abcd","abca","cab","cad"};

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < n-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int len = min(s1.size(), s2.size());

        for(int ptr = 0; ptr < len; ptr++) {
            if(s1[ptr] != s2[ptr]) {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topo = topoSort(k, adj);

    string ans = "";
    for(auto it : topo) {
        ans += it + 'a';
    }
    
    cout << ans;    

    return 0;
}