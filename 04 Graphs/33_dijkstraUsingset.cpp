#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<limits.h>
using namespace std;

// Q. Draw using min-heap ?  

vector<int> dijkstra(int n, vector<vector<int>> adj[], int src) {

    set<pair<int,int>> st;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {

        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for(auto it : adj[node]) {
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode]) {
                if(dist[adjNode] != INT_MAX) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode] , adjNode});
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