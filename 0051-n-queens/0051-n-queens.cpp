class Solution {
    bool isSafe(int row, int col, vector<string> &board,int n) { //no need to check right, up or down to curr queen's pos
        int r = row, c = col;
        while(row >= 0 && col >= 0) { //check upper left diagonal
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = r, col = c;
        while(col >= 0) { //check left in curr queen's row
            if(board[row][col] == 'Q') return false;
            col--;
        }

        row = r, col = c;
        while(row <= n-1 && col >= 0) { //check down left diagonal
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }

        // if no false, then queen can be placed at board[row][col]
        return true; 
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
        // base case
        if(col == n) {
            ans.push_back(board); 
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row,col,board,n)) { //if you can place queen in this col at this row
                board[row][col] = 'Q'; //place the queen at this row,col
                solve(col+1, board, ans, n);  //cal rec to place the next queen in next col
                board[row][col] = '.'; //remove placed queen while backtracking
            }
        }
    }

    void helper(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftRow, vector<int> &leftUpperDiagonal, vector<int> &leftLowerDiagonal) {
        if(col == n) { //base case
            ans.push_back(board);
            return;
        }

        for(int row=0; row<=n-1; row++) {
            if(leftRow[row] == 0 && leftUpperDiagonal[n-1 + col-row] == 0 && leftLowerDiagonal[row+col] == 0) { //if all three conditions met, then you can place the queen at this row,col
                board[row][col] = 'Q'; // place the queen
                // hash all three vectors
                leftRow[row] = 1;
                leftUpperDiagonal[n-1 + col-row] = 1;
                leftLowerDiagonal[row + col] = 1;
                helper(col + 1, board, ans, n, leftRow, leftUpperDiagonal, leftLowerDiagonal);
                board[row][col] = '.'; //remove the queen
                // unhash all three vectors
                leftRow[row] = 0;
                leftUpperDiagonal[n-1 + col-row] = 0;
                leftLowerDiagonal[row + col] = 0;
            }
        }
    }
    

public:
    vector<vector<string>> solveNQueens(int n) {
        // brute force => TC: O(N^2), solve() takes O(N) and isSafe() also takes O(N), 
        // vector<vector<string>> ans;
        // vector<string> board(n); 
        // string s(n,'.');
        // for(int i=0; i<n; i++) {
        //     board[i] = s;
        // }
        // solve(0,board,ans,n);
        // return ans;

        // optimised approach, TC: O(N!*N), SC: O(N)
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board[i] = s;
        }
        vector<int> leftRow(n,0);
        vector<int> leftLowerDiagonal(2*n-1, 0);
        vector<int> leftUpperDiagonal(2*n-1, 0);
        helper(0, board, ans, n, leftRow, leftLowerDiagonal, leftUpperDiagonal);
        return ans;
    }
};