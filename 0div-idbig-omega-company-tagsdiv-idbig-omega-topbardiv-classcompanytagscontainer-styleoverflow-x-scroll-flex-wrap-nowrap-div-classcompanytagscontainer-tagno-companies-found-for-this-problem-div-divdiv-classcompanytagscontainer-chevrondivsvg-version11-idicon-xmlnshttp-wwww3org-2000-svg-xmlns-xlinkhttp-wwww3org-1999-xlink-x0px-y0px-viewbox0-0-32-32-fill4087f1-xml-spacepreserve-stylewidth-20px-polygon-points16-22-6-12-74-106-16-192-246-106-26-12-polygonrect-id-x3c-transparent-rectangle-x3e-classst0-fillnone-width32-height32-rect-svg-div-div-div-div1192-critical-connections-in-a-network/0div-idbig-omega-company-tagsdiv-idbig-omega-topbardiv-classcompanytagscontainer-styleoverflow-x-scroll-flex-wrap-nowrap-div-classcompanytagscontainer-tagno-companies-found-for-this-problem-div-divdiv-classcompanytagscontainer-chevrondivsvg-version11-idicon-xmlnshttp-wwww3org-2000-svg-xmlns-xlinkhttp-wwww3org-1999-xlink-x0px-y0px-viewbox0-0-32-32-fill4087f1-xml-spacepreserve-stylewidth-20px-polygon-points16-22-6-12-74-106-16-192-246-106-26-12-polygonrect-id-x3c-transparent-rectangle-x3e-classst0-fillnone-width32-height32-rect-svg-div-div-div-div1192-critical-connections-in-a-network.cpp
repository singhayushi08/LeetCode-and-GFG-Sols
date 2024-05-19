class Solution {
private:
    int timer=0;
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        // vis adj nodes
        for(auto it: adj[node]) {
            if(it == parent) continue;
            if(vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                // now after this dfs call is done and it is coming back to the parent node
                low[node] = min(low[node], low[it]);
                // check if it -- node has a bridge
                if(tin[node] < low[it]) { //then this is a bridge
                    bridges.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // TC: O(V+2E), SC: O(3N + V+2E)
        vector<vector<int>> bridges;
        vector<int> vis(n,0);
        vector<int> adj[n];
        
        for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         
        int tin[n]; //contains no. of steps to reach this node
        int low[n]; //contains the lowest node apart from the parent node which can be visited
        dfs(0,-1,vis,adj,tin,low,bridges);
        
        return bridges;
    }
};