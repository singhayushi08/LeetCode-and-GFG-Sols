class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // TC: O(E log V) where E=m*n*4, V = m*n
        // SC: O(m*n)
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX)); //stores min effort
        dist[0][0] = 0;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!pq.empty()) {
            pair<int,pair<int,int>> top = pq.top();
            int row = top.second.first;
            int col = top.second.second;
            int d = top.first; 
            pq.pop();
            
            if(row == n-1 && col == m-1) return d;
            
            // traverse all 4 directions
            for(int i=0; i<4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int nd = max(d, abs(heights[nrow][ncol] - heights[row][col])); //maintains max abs diff
                    if(nd < dist[nrow][ncol]) {
                        dist[nrow][ncol] = nd;
                        pq.push({nd,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1;
    }
};
