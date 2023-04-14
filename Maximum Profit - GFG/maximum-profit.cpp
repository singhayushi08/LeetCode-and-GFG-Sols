//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int f(int idx, int transNo, int k, int prices[], int n) {
        if(idx == n || transNo == 2*k) return 0;
        
        if(transNo % 2 == 0) { // buy
            int buyy = -prices[idx] + f(idx+1, transNo+1, k, prices, n);
            int notBuy = 0 + f(idx+1, transNo, k, prices, n);
            return max(buyy, notBuy);
        } 
        else { // sell
            int sell = prices[idx] + f(idx+1, transNo+1, k, prices, n);
            int notSell = 0 + f(idx+1, transNo, k, prices, n);
            return max(sell, notSell);
        }
    }
    
    int memo(int idx, int transNo, int k, int prices[], int n, vector<vector<int>> &dp) {
        if(idx == n || transNo == 2*k) return 0;
        
        if(dp[idx][transNo] != -1) return dp[idx][transNo];
        
        int profit = 0;
        if(transNo % 2 == 0) { // buy
            int buyy = -prices[idx] + memo(idx+1, transNo+1, k, prices, n, dp);
            int notBuy = 0 + memo(idx+1, transNo, k, prices, n, dp);
            profit = max(buyy, notBuy);
        } 
        else { // sell
            int sell = prices[idx] + memo(idx+1, transNo+1, k, prices, n, dp);
            int notSell = 0 + memo(idx+1, transNo, k, prices, n, dp);
            profit = max(sell, notSell);
        }
        
        return dp[idx][transNo] = profit;
    }
    
  public:
    int maxProfit(int K, int N, int A[]) {
        // if K = 2, 
        // 0 1 2 3 => transaction No.
        // B S B S => buy and sell, buy and sell (total = 2*K = 4)
        
        // Recursion
        // return f(0, 0, K, A, N);
        
        // Memo
        // vector<vector<int>> dp(N, vector<int>(2*K, -1));
        // return memo(0, 0, K, A, N, dp);
        
        // Tabulation
        vector<vector<int>> dp(N+1, vector<int>(2*K+1, 0));
        
        for(int idx=N-1; idx>=0; idx--) {
            for(int transNo=2*K-1; transNo>=0; transNo--) {
                int profit = 0;
                if(transNo % 2 == 0) { // buy
                    int buyy = -A[idx] + dp[idx+1][transNo+1];
                    int notBuy = 0 + dp[idx+1][transNo];
                    profit = max(buyy, notBuy);
                } 
                else { // sell
                    int sell = A[idx] + dp[idx+1][transNo+1];
                    int notSell = 0 + dp[idx+1][transNo];
                    profit = max(sell, notSell);
                }
                
                dp[idx][transNo] = profit;
            }
        }
        
        return dp[0][0];

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends