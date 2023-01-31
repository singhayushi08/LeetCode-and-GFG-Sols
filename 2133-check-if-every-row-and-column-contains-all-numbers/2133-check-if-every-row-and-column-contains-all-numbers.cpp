class Solution {
    bool isSafe(vector<vector<int>>& matrix, int row, int col, int num) {
        for(int i=0; i<matrix.size(); i++) {
            if(matrix[row][i] == num && i != col) { // check row, except for matrix[row][col]
                return false;
            } 
            if(matrix[i][col] == num && i!= row) { // check col, except for matrix[row][col]
                return false;
            }
        }
        return true;
    }
public:
    bool checkValid(vector<vector<int>>& matrix) {
        // each row and col should have nos. from 1 to n, that means each row and col will have unique nos.
        // if any no. is repeating in a row and col, then it is invalid
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(isSafe(matrix, i, j, matrix[i][j]) == true) { 
                    continue;
                } 
                else {
                    return false;
                }
            }
        }
        return true;
    }
};