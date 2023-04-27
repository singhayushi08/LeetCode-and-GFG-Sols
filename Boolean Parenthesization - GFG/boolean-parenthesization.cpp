//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int mod = 1003;
    
    int f(int i, int j, bool isTrue, string &s) {
        if(i > j) return 0; 
        if(i == j) {
            if(isTrue == 1) return s[i] == 'T'; // returns 1 if looking for true
            else return s[i] == 'F'; // returns 1 if looking for false
        }
        
        int ways = 0;
        // make partitions at every operators (&, |, ^)
        for(int k=i+1; k<=j-1; k += 2) {
            int lT = f(i, k-1, 1, s); // no of ways in which left is true
            int lF = f(i, k-1, 0, s); // no of ways in which left is false
            int rT = f(k+1, j, 1, s); // no of ways in which right is true
            int rF = f(k+1, j, 0, s); // no of ways in which right is false
            
            if(s[k] == '&') {
                if(isTrue == 1) {
                    ways += lT * rT;
                } else {
                    ways += (lT * rF) + (lF * rT) + (lF * rF); 
                }
            }
            else if(s[k] == '|') {
                if(isTrue == 1) {
                    ways += (lT * rT) + (lT * rF) + (lF * rT);
                } else {
                    ways += (lF * rF);
                }
            }
            else if(s[k] == '^') {
                if(isTrue == 1) {
                    ways += (lT * rF) + (lF * rT);
                } else {
                    ways += (lT * rT) + (lF * rF);
                }
            }
        }
        
        return ways;
    }
    
    int memo(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if(i > j) return 0; 
        if(i == j) {
            if(isTrue == 1) return s[i] == 'T'; // returns 1 if looking for true
            else return s[i] == 'F'; // returns 1 if looking for false
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        
        int ways = 0;
        // make partitions at every operators (&, |, ^)
        for(int k=i+1; k<=j-1; k += 2) {
            int lT = memo(i, k-1, 1, s, dp); // no of ways in which left is true
            int lF = memo(i, k-1, 0, s, dp); // no of ways in which left is false
            int rT = memo(k+1, j, 1, s, dp); // no of ways in which right is true
            int rF = memo(k+1, j, 0, s, dp); // no of ways in which right is false
            
            if(s[k] == '&') {
                if(isTrue == 1) {
                    ways += (lT * rT)%mod;
                } else {
                    ways += ((lT * rF)%mod + (lF * rT)%mod + (lF * rF)%mod)%mod; 
                }
            }
            else if(s[k] == '|') {
                if(isTrue == 1) {
                    ways += ((lT * rT)%mod + (lT * rF)%mod + (lF * rT)%mod)%mod;
                } else {
                    ways += (lF * rF)%mod;
                }
            }
            else if(s[k] == '^') {
                if(isTrue == 1) {
                    ways += ((lT * rF)%mod + (lF * rT)%mod)%mod;
                } else {
                    ways += ((lT * rT)%mod + (lF * rF)%mod)%mod;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways%mod;
    }
    
public:
    int countWays(int N, string S){ // Variation of MCM
    
        // Recursion
        // return f(0, N-1, true, S); // the whole expr should evaluate to true
        
        // Memoization (3D DP), TC: O(N*N*2), SC: O(N*N*2 + N)
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2,-1)));
        return memo(0, N-1, true, S, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends