class Solution {
    int f(int i, int j, string s1, string s2) { 
        //f(i,j) signifies length of longest lcs in s1(0..i) and s2(0..j)  
        if(i==0 || j==0) return 0;    
        
        if(s1[i-1] == s2[j-1]) { // if both char match
            return 1 + f(i-1, j-1, s1, s2); // 1 length subsequence found, so add it
        }
        
        // if char do not match
        return max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }
    
    int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) { 
        if(i==0 || j==0) return 0;    
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) { 
            return dp[i][j] = 1 + memo(i-1, j-1, s1, s2, dp); 
        }
        
        return dp[i][j] = max(memo(i-1, j, s1, s2, dp), memo(i, j-1, s1, s2, dp));
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        
        // Recursion, TC: O(2^n * 2^m), SC: O(max(n,m))
        // return f(n, m, text1, text2);
        
        // Memoization, TC: O(n*m), SC: O(n*m) for 2d array + O(n+m) for aux stack space
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return memo(n, m, text1, text2, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n, vector<int>(m+1,0));
        

    }
};