class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        dist[0][0] = 1;
        
        while(!q.empty()) {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int d = q.front().first;
            q.pop();
            
            if(row == n-1 && col == n-1) return d;
             
            //traverse all 8 directions
            for(int delrow=-1; delrow<=1; delrow++) {
                for(int delcol=-1; delcol<=1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    int nd = d + 1;
                    
                    if(nrow >= 0 && nrow < n && ncol>=0 && ncol < n && grid[nrow][ncol] == 0 && nd < dist[nrow][ncol]) {
                        dist[nrow][ncol] = nd;
                        q.push({nd,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};