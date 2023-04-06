//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int f(int i, int j, string &s1, string &s2) {
        if(i == 0 || j == 0) return 0;
        
        if(s1[i-1] == s2[j-1]) {
            return 1 + f(i-1, j-1, s1, s2);
        }    
        
        return 0 + max(f(i-1,j,s1,s2), f(i,j-1,s1,s2));
    }
    
    int memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1]) {
            return dp[i][j] = 1 + memo(i-1, j-1, s1, s2, dp);
        }    
        
        return dp[i][j] = 0 + max(memo(i-1,j,s1,s2,dp), memo(i,j-1,s1,s2,dp));
    }
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        // Recursion
        // return f(n, m, s1, s2);
        
        // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        // return memo(n, m, s1, s2, dp);
        
        // Tabulation
        // vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // for(int j=0; j<=m; j++) dp[0][j] = 0;
        // for(int i=0; i<=n; i++) dp[i][0] = 0;
        
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=m; j++) {
        //         if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        //         else dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        
        // return dp[n][m];
        
        // Space Optimised
        vector<int> prev(m+1,0), curr(m+1,0);
        for(int j=0; j<=m; j++) prev[j] = 0;
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = 0 + max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends