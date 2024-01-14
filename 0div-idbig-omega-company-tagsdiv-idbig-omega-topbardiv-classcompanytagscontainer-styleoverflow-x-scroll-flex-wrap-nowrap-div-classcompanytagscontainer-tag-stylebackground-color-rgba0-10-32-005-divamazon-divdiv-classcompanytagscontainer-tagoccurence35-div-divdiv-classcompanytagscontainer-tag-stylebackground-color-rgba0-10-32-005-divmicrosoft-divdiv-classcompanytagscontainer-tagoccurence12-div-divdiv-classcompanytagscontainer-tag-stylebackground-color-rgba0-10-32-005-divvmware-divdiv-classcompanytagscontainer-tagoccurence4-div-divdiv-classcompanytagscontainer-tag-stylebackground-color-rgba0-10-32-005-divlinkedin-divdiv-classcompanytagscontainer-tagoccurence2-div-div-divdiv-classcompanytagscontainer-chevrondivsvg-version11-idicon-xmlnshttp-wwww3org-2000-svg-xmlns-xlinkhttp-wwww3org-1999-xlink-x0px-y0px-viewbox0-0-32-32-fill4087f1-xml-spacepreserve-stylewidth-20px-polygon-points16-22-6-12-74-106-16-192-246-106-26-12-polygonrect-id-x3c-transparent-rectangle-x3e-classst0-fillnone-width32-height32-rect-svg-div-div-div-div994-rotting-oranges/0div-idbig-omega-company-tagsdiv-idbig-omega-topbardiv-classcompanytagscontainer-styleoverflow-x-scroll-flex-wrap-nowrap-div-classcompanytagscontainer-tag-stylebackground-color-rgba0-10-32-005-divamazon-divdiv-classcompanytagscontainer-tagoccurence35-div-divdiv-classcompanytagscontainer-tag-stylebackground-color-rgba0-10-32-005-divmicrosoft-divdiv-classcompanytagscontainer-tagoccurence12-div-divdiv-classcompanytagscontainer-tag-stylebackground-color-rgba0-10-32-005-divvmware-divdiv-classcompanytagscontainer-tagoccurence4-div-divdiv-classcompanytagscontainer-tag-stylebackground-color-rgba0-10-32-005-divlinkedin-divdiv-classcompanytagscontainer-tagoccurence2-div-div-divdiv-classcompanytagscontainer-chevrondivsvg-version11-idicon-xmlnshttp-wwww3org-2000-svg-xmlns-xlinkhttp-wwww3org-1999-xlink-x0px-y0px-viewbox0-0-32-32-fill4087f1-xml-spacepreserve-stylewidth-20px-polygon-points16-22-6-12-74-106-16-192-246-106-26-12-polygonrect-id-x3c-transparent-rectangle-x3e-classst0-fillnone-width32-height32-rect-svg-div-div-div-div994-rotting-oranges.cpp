class Solution {
    int bfs(queue<pair<int,int>> q, vector<vector<int>>& grid,vector<vector<int>>& vis, int delrow[], int delcol[]) {
        int minTime = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()) {
            bool checkRotten = false;
            int size = q.size();
            for(int i=0; i<size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                // visit all 4 neighbours
                for(int i=0; i<4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >=0 && nrow < n && ncol >=0 && ncol <m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 2;
                        checkRotten = true;
                    }
                }
            }
            if(checkRotten == true) minTime++;
        }    
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minTime;
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis = grid;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) { // push all rotten oranges in the queue
                    q.push({i,j});
                }
            }
        }
        
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        return bfs(q,grid,vis,delrow,delcol);
        
    }
};