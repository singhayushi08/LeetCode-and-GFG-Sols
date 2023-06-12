class Solution {
    void dfs(int i, int j, vector<vector<int>>& image, int starting_pixel_color, int color, vector<vector<int>>& vis, int m, int n) {
        if(i < 0 || i >= m || j < 0 || j >= n) return; // out of bound
        if(image[i][j] != starting_pixel_color) return; // neigbouring pixel should be of the same color as starting pixel
        if(vis[i][j] == 1) return;
        
        vis[i][j] = 1;
        image[i][j] = color;
        
        // now call dfs on 4 directions
        dfs(i-1, j, image, starting_pixel_color, color, vis, m, n);
        dfs(i, j+1, image, starting_pixel_color, color, vis, m, n);
        dfs(i+1, j, image, starting_pixel_color, color, vis, m, n);
        dfs(i, j-1, image, starting_pixel_color, color, vis, m, n);
        
        return; 
    }
    
    void dfs(int i, int j, vector<vector<int>>& image, int starting_pixel_color, int color, int m, int n, int delRow[], int delCol[]) {
        if(i < 0 || i >= m || j < 0 || j >= n) return; // out of bound
        if(image[i][j] != starting_pixel_color) return;  // neigbouring pixel should be of the same color as starting pixel
        if(image[i][j] == color) return; // already visited and modified
        
        image[i][j] = color;
        
        // now call dfs on 4 directions (shortcut)
        for(int k=0; k<4; k++) {
            int newRow = i + delRow[k];
            int newCol = j + delCol[k];
            dfs(newRow, newCol, image, starting_pixel_color, color, m, n, delRow, delCol);
        }
        
        return; 
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // with visited array, TC: O(m*n*4), SC: O(2*m*n)
//         if(image[sr][sc] == color) return image;
        
//         // do not alter the given image, create a copy of it
//         vector<vector<int>> ans = image;
//         int m = image.size();
//         int n = image[0].size();
//         vector<vector<int>> vis(m, vector<int>(n,0));
//         int starting_pixel_color = image[sr][sc];
//         dfs(sr, sc, ans,  starting_pixel_color, color, vis, m, n);

//         return ans;
        
        // works without visited array too, TC: O(m*n*4), SC: O(m*n)
        if(image[sr][sc] == color) return image;
        
        // do not alter the given image, create a copy of it
        vector<vector<int>> ans = image;
        int m = image.size();
        int n = image[0].size();
        int starting_pixel_color = image[sr][sc];
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr, sc, ans,  starting_pixel_color, color, m, n, delRow, delCol);

        return ans;
    }
};