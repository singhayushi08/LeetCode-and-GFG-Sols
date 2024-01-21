class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis, int delrow[], int delcol[]) {
        vis[i][j] = 1;
        
        for(int k=0; k<4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, n, m, grid, vis, delrow, delcol);
            }
        }
        
        return;
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        // graph dfs, tc: O(n*m*4), sc: O(n*m)
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
    
        // first row and last row
        for(int j=0; j<m; j++) {
            if(grid[0][j] == 1 && vis[0][j] == 0) {
                dfs(0,j,n,m,grid,vis,delrow,delcol);
            }
            if(grid[n-1][j] == 1 && vis[n-1][j] == 0) {
                dfs(n-1,j,n,m,grid,vis,delrow,delcol);
            }
        }
        
        // first col and last col
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1 && vis[i][0] == 0) {
                dfs(i,0,n,m,grid,vis,delrow,delcol);
            }
            if(grid[i][m-1] == 1 && vis[i][m-1] == 0) {
                dfs(i,m-1,n,m,grid,vis,delrow,delcol);
            }
        }
        
        int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};