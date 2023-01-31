class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == ch && i != col) { //check row, except for board[row][col] itself
                return false;
            }

            if(board[i][col] == ch && i != row) { // check col, except for board[row][col] itself
                return false;
            }

            int r = 3 * (row/3) + i/3;
            int c = 3 * (col/3) + i%3;
            if(board[r][c] == ch && r != row && c != col)  { // check subgrid, except for board[row][col] itself
                return false;
            }
        }
        return true;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                if(board[i][j] != '.') {
                    if(isValid(board,i,j,board[i][j]) == true) {
                        continue;
                    } 
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};