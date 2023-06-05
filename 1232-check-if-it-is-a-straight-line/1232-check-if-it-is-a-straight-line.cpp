class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];
        
        int dx = x2 - x1;
        int dy = y2 - y1;
        
        for(int i=2; i<coordinates.size(); i++) {
            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            
            if((dy * (x3-x1)) != (dx * (y3-y1))) { // checking slope of every pair with 0th pair
                return false;
            }
        }
        
        return true;
    }
};