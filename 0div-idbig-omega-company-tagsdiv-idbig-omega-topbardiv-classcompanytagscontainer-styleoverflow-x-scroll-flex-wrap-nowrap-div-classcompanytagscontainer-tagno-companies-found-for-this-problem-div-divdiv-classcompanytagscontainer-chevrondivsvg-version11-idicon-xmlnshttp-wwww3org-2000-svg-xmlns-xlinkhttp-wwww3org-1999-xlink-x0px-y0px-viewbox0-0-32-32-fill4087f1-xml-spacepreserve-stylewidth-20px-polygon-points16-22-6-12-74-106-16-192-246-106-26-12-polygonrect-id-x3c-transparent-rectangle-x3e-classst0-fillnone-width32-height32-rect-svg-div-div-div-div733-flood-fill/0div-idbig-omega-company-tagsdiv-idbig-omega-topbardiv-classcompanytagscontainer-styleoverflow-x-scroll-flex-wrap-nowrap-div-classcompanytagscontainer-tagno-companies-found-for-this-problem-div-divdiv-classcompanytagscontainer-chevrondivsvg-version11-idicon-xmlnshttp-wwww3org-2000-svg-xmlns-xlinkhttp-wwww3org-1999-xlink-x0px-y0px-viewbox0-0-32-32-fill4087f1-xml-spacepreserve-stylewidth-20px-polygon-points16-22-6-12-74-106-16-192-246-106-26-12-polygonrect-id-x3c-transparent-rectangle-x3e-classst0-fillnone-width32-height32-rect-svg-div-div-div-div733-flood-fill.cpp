class Solution {
    void dfs(int row,int col, int startingPixelColor, int color, vector<vector<int>>& image, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        
        // traverse all 4 directions of current node
        if(row-1 >= 0 && row-1<n && image[row-1][col] == startingPixelColor && vis[row-1][col] == 0) {
            dfs(row-1,col,startingPixelColor,color,image,vis);
        }
        if(col+1 >= 0 && col+1 <m && image[row][col+1] == startingPixelColor && vis[row][col+1] == 0) {
            dfs(row,col+1,startingPixelColor,color,image,vis);
        }
        if(row+1 >= 0 && row+1 <n && image[row+1][col] == startingPixelColor && vis[row+1][col] == 0) {
            dfs(row+1,col,startingPixelColor,color,image,vis);
        }
        if(col-1 >= 0 && col-1<m && image[row][col-1] == startingPixelColor && vis[row][col-1] == 0) {
            dfs(row,col-1,startingPixelColor,color,image,vis);
        }
    }
    
    void dfs_traversal(int row, int col, int startingPixelColor,int newColor, vector<vector<int>>& image, vector<vector<int>>& ans, int delrow[], int delcol[]) {
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size();
        
        for(int k=0; k<4; k++) {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            
            if(nrow >= 0 && nrow <n && ncol >=0 && ncol <m && image[nrow][ncol] == startingPixelColor && ans[nrow][ncol] != newColor) {
                dfs_traversal(nrow, ncol, startingPixelColor, newColor, image, ans, delrow, delcol);
            }
        }
    } 
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // TC: O(m*n*4), SC: O(m*n)
//         int n = image.size();
//         int m = image[0].size();
//         vector<vector<int>> vis(n,vector<int>(m,0));
//         int startingPixelColor = image[sr][sc];
        
//         if(startingPixelColor == color) return image;
//         dfs(sr,sc,startingPixelColor,color,image,vis);
        
//         return image;
        
        // better approach, you dont need to user vis array. TC: O(m*n*4), SC: O(m*n)
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans = image;
        int startingPixelColor = image[sr][sc];
        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        
        if(startingPixelColor == color) return image;
        dfs_traversal(sr,sc,startingPixelColor,color,image,ans, delrow, delcol);
        
        return ans;
    }
};