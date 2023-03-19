//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int f(int day, int last, vector<vector<int>> &points) {
        if(day == 0) { // base case
            int maxi = 0;
            for(int task=0; task<3; task++) {
                if(task != last) {
                    maxi = max(maxi, points[day][task]);
                }
            }
            return maxi;
        }    
        
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int point = points[day][task] + f(day-1,task,points);
                maxi = max(point, maxi);
            }
        }
        
        return maxi;
    }
    
    int memo(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
        if(day == 0) { // base case
            int maxi = 0;
            for(int task=0; task<3; task++) {
                if(task != last) {
                    maxi = max(maxi, points[day][task]);
                }
            }
            return maxi;
        }    
        
        if(dp[day][last] != -1) return dp[day][last];
        
        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int point = points[day][task] + memo(day-1,task,points,dp);
                maxi = max(point, maxi);
            }
        }
        
        return dp[day][last] = maxi;
    }
    
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Recursion, TC: O(2^n), SC: O(2^n)
        // last => 0,1,2,3 (3 is for none of the activity)
        // task => 0,1,2 
        // return f(n-1, 3, points); //last means the last activity which was performed, initially 3 which means none
        
        
        // Memoization, TC: O(n*4*3) where n*4 is 2d matrix and for each cell running a loop of 3 acitivities
        // SC: O(n*4 + n) where n*4 is for 2d matrix and n is for rec stack space
        // vector<vector<int>> dp(n, vector<int>(4,-1));
        // return memo(n-1, 3, points, dp);
        
        // Tabulation, TC: O(n*4*3), SC: O(n*4) for the 2d matrix
        vector<vector<int>> dp(n, vector<int>(4));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1; day<n; day++) {
            for(int last=0; last<4; last++) {
                dp[day][last] = 0;
                int maxi = 0;
                
                for(int task = 0; task<3; task++) {
                    if(task != last) {
                        int point = points[day][task] + dp[day-1][task];
                        maxi = max(maxi, point);
                    }
                }
                
                dp[day][last] = maxi;
            }
        }
        
        return dp[n-1][3];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends