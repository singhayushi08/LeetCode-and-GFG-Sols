class Solution {
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[node] = 1;
        
        for(int i=0; i<isConnected[node].size(); i++) {
            if(isConnected[node][i] == 1 && node != i && vis[i] == 0) {
                dfs(i, vis, isConnected);
            }
        }    
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        
        return cnt;
    }
};