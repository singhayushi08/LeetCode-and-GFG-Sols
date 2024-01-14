class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // {{r,c},t} where r is row, c is col and t is time
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    vis[i][j] = 2; // mark rotten in visited array
                } 
            }
        }
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int maxTime = 0; // this max time will be the min time taken to rot all oranges
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            maxTime = max(maxTime,t);
            
            // traverse its neighbours
            for(int i=0; i<4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) { //check validity and whether it is visited in vis array
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) { // if any fresh orange has not been rotted
                    return -1;
                }
            }
        }
        
        return maxTime;
    }
};