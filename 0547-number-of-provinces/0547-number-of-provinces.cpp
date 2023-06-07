class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        
        for(auto i: adj[node]) {
            if(vis[i] == 0) {
                dfs(i, vis, adj);
            }
        }    
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) { // same as no.of components in disconnected graph
        // 1 based indexing
        int n = isConnected.size();
        vector<int> adj[n+1];
        
        // convert adjacency matrix into list
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        int cnt = 0;
        vector<int> vis(n+1, 0);
        
        for(int i=1; i<=n; i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, vis, adj);
            }
        }
        
        return cnt;
    }
};