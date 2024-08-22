// TC - O(V log V + V + E)
// SC - O(V + E)

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<vector<int>> arr(n);
    for(int i = 0; i < n; i++) {
        int m;
        cout << "Enter m : ";
        cin >> m;

        arr[i].resize(m);

        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // vector<vector<int>> arr = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
    // vector<vector<int>> arr = {{1,2},{2,3},{5},{0},{5},{}, {}};
    // int n = arr.size();

    unordered_map<int, vector<int>> adj;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < arr[i].size(); j++) {
            adj[arr[i][j]].push_back(i);
        }
    }

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

    vector<int> safeNodes;
    while(!q.empty()) {
        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    for(auto it : safeNodes) {
        cout << it << " ";
    }

    return 0;
}