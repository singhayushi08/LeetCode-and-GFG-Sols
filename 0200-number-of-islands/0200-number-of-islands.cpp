class Solution {
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid, int m, int n) {
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // check for 1 in all 4 directions
            
            // up-> row-1, col
            if(row-1 >= 0 && row-1<m && col >= 0 && col < n && grid[row-1][col] == '1' && vis[row-1][col] == 0) {
                vis[row-1][col] = 1;
                q.push({row-1, col});
            }
            
            // right -> row, col+1
            if(row >= 0 && row<m && col+1 >= 0 && col+1 < n && grid[row][col+1] == '1' && vis[row][col+1] == 0) {
                vis[row][col+1] = 1;
                q.push({row, col+1});
            }
            
            // down -> row+1, col
            if(row+1 >= 0 && row+1<m && col >= 0 && col < n && grid[row+1][col] == '1' && vis[row+1][col] == 0) {
                vis[row+1][col] = 1;
                q.push({row+1, col});
            }
            
            // left -> row, col-1
            if(row >= 0 && row<m && col-1 >= 0 && col-1 < n && grid[row][col-1] == '1' && vis[row][col-1] == 0) {
                vis[row][col-1] = 1;
                q.push({row, col-1});
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    cnt++;
                    bfs(i,j,vis,grid,m,n); // call bfs on node which is having 1 in grid
                }
            }
        }
        
        return cnt;
    }
};