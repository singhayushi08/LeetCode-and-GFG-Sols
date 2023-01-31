class Solution {
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == ch) //check row
                return false;
            
            if(board[i][col] == ch)  //check column
                return false;
            
            if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == ch ) //check sub-box (3*3 grid)
                return false;
        }
        //if no false, then it is safe to place this ch at board[row][col]
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                
                if(board[i][j] == '.') { //if empty place
                    
                    for(char ch='1'; ch<='9'; ch++) { //try all nos from 1-9, if any valid
                        if(isValid(board, i, j, ch)) { 
                            board[i][j] = ch; //if valid, place this no.

                            //call rec to fill up next empty cell on board
                            if(solve(board) == true) { //if any call returns true, do not remove the no. placed and directly return true since this is a valid sudoko
                                return true;
                            } else { //else if you can't place any no. in the next call, that means this sudoko is invalid, so you remove the no. place before
                                board[i][j] = '.';
                            }
                        }
                    }

                    return false; //you cant place any no. at curr empty place
                }
            }
        }
        return true; //if all the nos. are filled in sudoko, this will be the last case so return true
    }

    bool check(vector<vector<char>>& board, int row, int col, char ch) {
        //check curr row and curr col
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == ch) return false; //check row
            if(board[i][col] == ch) return false; //check col
        }

        // check subgrid corresponding to board[row][col]
        // x0, y0 is the starting index of the subgrid
        int x0 = 3 * (row/3);
        int y0 = 3 * (col/3); 
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x0 + i][y0 + j] == ch) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve_helper(vector<vector<char>>& board, int i, int j) { //i is row, j is col
        if(i == 9) return true; //end of matrix
        if(j == 9) return solve_helper(board, i+1, 0); //col ends, move to next row
    
        //if board[i][j] is empty cell
        if(board[i][j] == '.') {
            
            for(char ch = '1'; ch <= '9'; ch++) {  //try all 1-9 on this empty cell
                if(check(board, i, j, ch) == true) {
                    //place ch at this empty cell
                    board[i][j] = ch;
                    if(solve_helper(board, i, j+1) == true) { //call rec on next empty cell
                        return true;
                    } 
                    else {
                        board[i][j] = '.'; //remove the placed no. while backtracking
                    }
                }
            }
            
            //if not able to place any no. on this empty cell, return false
            return false;
        }
        //if it is not an empty cell
        else {
            return solve_helper(board, i, j+1);
        }
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        // TC: O(9^(N^2)) coz every cell in n^2 matrix we have 9 possible options, SC: O(1)
        // solve(board);

        // another way: instead of traversing the whole matrix again to find the next empty cell, we can simply pass r,c
        solve_helper(board, 0, 0);
    }
};