class Solution {
    void dfs(vector<vector<int>>& stones, int index, vector<int>& vis) {
        vis[index] = 1; //mark curr stone as visited
        
        // check in the stones if there is any other stone is same row or same column which is not visited
        for(int i=0; i<stones.size(); i++) {
            int row = stones[index][0];
            int col = stones[index][1];
            
            if(vis[i] == 0 && (stones[i][0] == row || stones[i][1] == col)) {
                dfs(stones, i, vis);
            }
        }
        
        return;
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> vis(n,0);
        
        int totalComponents = 0;
        for(int i=0; i<n; i++) {
            if(vis[i] == 0) {
                dfs(stones, i, vis);
                totalComponents++;
            }
        }
        
        return n - totalComponents;
    }
};