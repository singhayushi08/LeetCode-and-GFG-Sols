class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int &ans) {
        if(i<0 || i>=m || j<0 || j>=n) return; // out of bound
        if(grid[i][j] == 0) return; 
        if(vis[i][j] == 1) return;
        
        // if neighbouring cell is water, then increase perimeter by 1
        // if 3 water cells in neighbour, so add 3 to perimeter
        if((i-1 >= 0 && grid[i-1][j] == 0) || i-1 < 0) ans++;
        if((j+1 < n && grid[i][j+1] == 0) || j+1 == n) ans++;
        if((i+1 < m && grid[i+1][j] == 0) || i+1 == m) ans++;
        if((j-1 >=0 && grid[i][j-1] == 0) || j-1 < 0) ans++;
        vis[i][j] = 1;
        
        dfs(i-1,j,grid,vis,m,n,ans); // up
        dfs(i,j+1,grid,vis,m,n,ans); // right
        dfs(i+1,j,grid,vis,m,n,ans); // down
        dfs(i,j-1,grid,vis,m,n,ans); // left
        return;
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    dfs(i,j,grid,vis,m,n,ans); 
                    break; // coz we know there is only 1 land
                }
            }
        }
        
        return ans;
    }
};