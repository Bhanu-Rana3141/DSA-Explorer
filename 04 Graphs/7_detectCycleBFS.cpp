/*
    // Function to detect cycle in an undirected graph.
    bool detect(int node, int parent, vector<int>adj[], int vis[]) {
        
        queue<pair<int, int>> q;
        q.push({node, parent});
        vis[node] = 1;
        
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto nNode : adj[node]) {
                if(!vis[nNode]) {
                    vis[nNode] = 1;
                    q.push({nNode, node});
                }
                else if(nNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(detect(i, -1, adj, vis)) return true;
            }
        }
        return false;
    } 

*/