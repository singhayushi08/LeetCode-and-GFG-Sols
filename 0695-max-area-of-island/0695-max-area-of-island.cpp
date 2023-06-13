class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int &area) {
        if(i<0 || i>=m || j<0 || j>=n) return; // out of bound
        if(grid[i][j] == 0) return;
        if(vis[i][j] == 1) return; // already visited, do not visit again
        
        vis[i][j] = 1;
        area++;
        
        // call dfs on all 4 neighbours
        dfs(i-1, j, grid, vis, m, n, area); // up
        dfs(i, j+1, grid, vis, m, n, area); // right
        dfs(i+1, j, grid, vis, m, n, area); // down
        dfs(i, j-1, grid, vis, m, n, area); // left
        return;
    } 
    
    void dfs(int i, int j, vector<vector<int>>& grid, int m, int n, int &area) {
        if(i<0 || i>=m || j<0 || j>=n) return; // out of bound
        if(grid[i][j] == 0) return;
        
        grid[i][j] = 0; // mark it as 0, so that it does not gets visited again
        
        area++;
        
        // call dfs on all 4 neighbours
        dfs(i-1, j, grid, m, n, area); // up
        dfs(i, j+1, grid, m, n, area); // right
        dfs(i+1, j, grid, m, n, area); // down
        dfs(i, j-1, grid, m, n, area); // left
        return;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // variation of no. of island (graph problem)
        // TC: O(m*n), SC: O(m*n)
//         int maxi = 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<int>> vis(m, vector<int>(n,0));
        
//         for(int i=0; i<m; i++) {
//             for(int j=0; j<n; j++) {
//                 if(grid[i][j] == 1 && vis[i][j] == 0) {
//                     int area = 0;
//                     dfs(i,j,grid,vis,m,n,area);
//                     maxi = max(area, maxi);
//                 }
//             }
//         }
        
//         return maxi;
        
        // can be done without using visited array too, TC: O(m*n), SC: O(1)
        int maxi = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(i,j,grid,m,n,area);
                    maxi = max(area, maxi);
                }
            }
        }
        
        return maxi;
        
    }
};