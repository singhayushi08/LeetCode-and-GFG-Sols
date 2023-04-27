class Solution {
    bool isPalindrome(string &s, int start, int end) {
        // if(start >= end) return true;
        // if(s[start] != s[end]) return false;
        // return isPalindrome(s, start+1, end-1);
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    int f(int i, string &s, int n, vector<int>& dp) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        
        int mini = INT_MAX;
        for(int j = i; j<n; j++) {
            if(isPalindrome(s, i, j) == true) {
                int cost = 1 + f(j+1, s, n, dp);
                mini = min(mini, cost);
            }
        }
        
        return dp[i] = mini;
    }
    
public:
    int minCut(string s) {
        // Memo, TC: O(n^2), SC: O(n + n) for dp array and aux stack space
        // int n = s.size();
        // vector<int> dp(n, -1);
        // return f(0, s, n, dp) - 1;
        
        // Tabulation
        int n = s.size();
        vector<int> dp(n+1, 0); 
        dp[n] = 0;
        
        for(int i=n-1; i>=0; i--) {
            int mini = INT_MAX;
            for(int j = i; j<n; j++) {
                if(isPalindrome(s, i, j) == true) {
                    int cost = 1 + dp[j+1];
                    mini = min(mini, cost);
                }
            }

            dp[i] = mini;
        }
        
        return dp[0]-1;
    }
};