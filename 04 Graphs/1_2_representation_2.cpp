#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    int m;
    cout << "Enter no of edges: ";
    cin >> m;

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i<m; i++) {
        int u , v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(auto i : adj) {
        cout << i.first << " : ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}