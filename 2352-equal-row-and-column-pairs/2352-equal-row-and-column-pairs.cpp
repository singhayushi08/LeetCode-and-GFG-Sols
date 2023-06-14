class Solution {
    int match(vector<vector<int>>& grid, vector<int> &v) {
        int cnt = 0;
        int n = grid.size();
        for(int j=0; j<n; j++) {
            vector<int> temp; // for every col
            for(int i=0; i<n; i++) {
                temp.push_back(grid[i][j]);
            }
            if(v == temp) cnt++;
        }  
        return cnt;
    }
    
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i=0; i<grid.size(); i++) {
           cnt += match(grid,grid[i]);
        }
        return cnt;
    }
};