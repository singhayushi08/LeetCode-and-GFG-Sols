class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vector<vector<int>>& vis, int delrow[], int delcol[]) {
        vis[i][j] = 1;
        
        // visit all 4 directions
        for(int k=0; k<4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                dfs(nrow, ncol, n, m, board, vis, delrow, delcol);
            }
        }
        
        return;
    }
    
public:
    void solve(vector<vector<char>>& board) {
        // TC: O(n*m*4) coz at worst case dfs will traverse the entire matrix, SC: O(n*m)
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        // first row
        for(int j=0; j<m; j++) {
            if(board[0][j] == 'O' && vis[0][j] == 0) {
                dfs(0,j,n,m,board,vis,delrow,delcol);
            }
        }
        
        // first col
        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O' && vis[i][0] == 0) {
                dfs(i,0,n,m,board,vis,delrow,delcol);
            }
        }
        
        // last row
        for(int j=0; j<m; j++) {
            if(board[n-1][j] == 'O' && vis[n-1][j] == 0) {
                dfs(n-1,j,n,m,board,vis,delrow,delcol);
            }
        }
        
        // last col
        for(int i=0; i<n; i++) {
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0) {
                dfs(i,m-1,n,m,board,vis,delrow,delcol);
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
        
        return;
    }
};