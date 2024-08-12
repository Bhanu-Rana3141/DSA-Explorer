/*
    bool dfs(int node, int parent, vector<int>adj[], int vis[]) {
        
        vis[node] = 1;
        
        for(auto nNode : adj[node]) {
            if(!vis[nNode]) {
                if(dfs(nNode, node, adj, vis)) {
                    return true;
                }
            }
            else if(nNode != parent) {
                return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        for(int i = 0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
*/