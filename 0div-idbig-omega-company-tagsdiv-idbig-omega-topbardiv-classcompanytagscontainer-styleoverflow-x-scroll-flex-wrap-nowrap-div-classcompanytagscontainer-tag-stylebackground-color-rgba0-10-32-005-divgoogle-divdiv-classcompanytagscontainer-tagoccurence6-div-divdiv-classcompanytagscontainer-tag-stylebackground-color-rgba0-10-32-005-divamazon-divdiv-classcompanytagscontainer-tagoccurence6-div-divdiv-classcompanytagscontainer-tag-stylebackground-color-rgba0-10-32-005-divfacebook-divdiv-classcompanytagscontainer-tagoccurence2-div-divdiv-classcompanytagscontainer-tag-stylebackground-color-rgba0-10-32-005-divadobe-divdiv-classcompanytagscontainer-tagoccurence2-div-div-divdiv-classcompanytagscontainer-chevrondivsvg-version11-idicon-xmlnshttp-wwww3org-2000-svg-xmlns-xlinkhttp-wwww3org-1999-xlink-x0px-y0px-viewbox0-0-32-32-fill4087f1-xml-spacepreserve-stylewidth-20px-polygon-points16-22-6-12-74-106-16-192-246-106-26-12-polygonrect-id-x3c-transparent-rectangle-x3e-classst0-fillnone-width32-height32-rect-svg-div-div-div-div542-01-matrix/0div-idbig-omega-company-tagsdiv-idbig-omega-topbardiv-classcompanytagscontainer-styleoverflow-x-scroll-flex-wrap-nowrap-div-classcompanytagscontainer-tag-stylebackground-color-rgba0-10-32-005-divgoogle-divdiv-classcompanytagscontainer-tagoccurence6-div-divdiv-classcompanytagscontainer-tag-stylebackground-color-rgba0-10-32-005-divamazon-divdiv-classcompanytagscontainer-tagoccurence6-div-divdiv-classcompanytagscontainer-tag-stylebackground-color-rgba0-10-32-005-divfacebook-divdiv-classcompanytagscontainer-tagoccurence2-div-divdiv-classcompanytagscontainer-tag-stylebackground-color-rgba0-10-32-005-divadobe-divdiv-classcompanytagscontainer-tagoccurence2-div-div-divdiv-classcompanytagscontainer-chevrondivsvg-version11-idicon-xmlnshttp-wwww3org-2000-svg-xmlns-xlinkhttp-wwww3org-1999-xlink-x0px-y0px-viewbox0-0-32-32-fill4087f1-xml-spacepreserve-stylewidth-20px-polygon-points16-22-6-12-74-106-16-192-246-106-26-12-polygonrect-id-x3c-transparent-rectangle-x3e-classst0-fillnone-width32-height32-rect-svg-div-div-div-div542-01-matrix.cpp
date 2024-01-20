class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // using bfs graph, tc: o(n*m*4), sc: o(n*m)
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            
            ans[row][col] = dist;
            for(int k=0; k<4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if(nrow >= 0 && nrow<n && ncol >= 0 && ncol <m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 1) {
                    q.push({{nrow,ncol},dist+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        
        return ans;
    }
};