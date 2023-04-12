//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    bool f(int i, int j, string &s1, string &s2) { //convert into 1 based indxing for tabulation
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0 && i >= 0) {
            for(int k=0; k<=i; k++) {
                if(s1[k] != '*') return false;
            }
            return true;
        }
        
        if(s1[i] == s2[j] || s1[i] == '?') {
            return f(i-1, j-1, s1, s2);
        }
        else if(s1[i] == '*') {
            return f(i-1, j, s1, s2) || f(i, j-1, s1, s2);
        }
        else {
            return false;
        }
    }
    
    bool memo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return true;
        if(i == 0 && j > 0) return false;
        if(j == 0 && i > 0) {
            for(int k=1; k<=i; k++) {
                if(s1[k-1] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1] == s2[j-1] || s1[i-1] == '?') {
            return dp[i][j] = memo(i-1, j-1, s1, s2, dp);
        }
        else if(s1[i-1] == '*') {
            return dp[i][j] = memo(i-1, j, s1, s2, dp) || memo(i, j-1, s1, s2, dp);
        }
        else {
            return dp[i][j] = false;
        }
    }
    
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = pattern.size();
        int m = str.size();
        // return f(n-1, m-1, pattern, str);
        
        // Memoization
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1)); 
        // return memo(n, m, pattern, str, dp);
        
        // Tabulation
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        dp[0][0] = true;
        for(int j=1; j<=m; j++) dp[0][j] = false;
        for(int i=1; i<=n; i++) {
            bool flag = true;
            for(int k=1; k<=i; k++) {
                if(pattern[k-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends