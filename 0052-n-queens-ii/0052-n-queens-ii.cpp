class Solution {
    void solve(int col, int n, vector<string> board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &leftUpperDiagonal, vector<int> &leftLowerDiagonal, int &cnt) {
        if(col == n) {
            ans.push_back(board);
            cnt++;
            return;
        }

        for(int row=0; row<=n-1; row++) {
            if(leftRow[row] == 0 && leftUpperDiagonal[n-1 + col-row] == 0 && leftLowerDiagonal[row+col] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftUpperDiagonal[n-1 + col-row] = 1;
                leftLowerDiagonal[row+col] = 1;
                solve(col + 1, n, board, ans, leftRow, leftUpperDiagonal, leftLowerDiagonal, cnt);
                board[row][col] = '.';
                leftRow[row] = 0;
                leftUpperDiagonal[n-1 + col-row] = 0;
                leftLowerDiagonal[row+col] = 0;
            }
        }
    }

public:
    int totalNQueens(int n) {
        // Using hashing, TC: O(N!*N), SC: O(N)
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        int cnt=0;
        vector<int> leftRow(n,0);
        vector<int> leftUpperDiagonal(2*n-1,0);
        vector<int> leftLowerDiagonal(2*n-1, 0);
        solve(0, n, board, ans, leftRow, leftUpperDiagonal, leftLowerDiagonal, cnt);
        // for(auto i: ans) {
        //     for(auto j: i) {
        //         for(auto k: j) {
        //             cout<<k<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }
        return cnt;
    }
};