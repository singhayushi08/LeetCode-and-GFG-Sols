//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int f(int idx, int transNo, vector<int>& price) {
    if(idx == price.size() || transNo == 4) { // base case
        return 0;
    }
    
    if(transNo % 2 == 0 ) { // buy
        int buyy = -price[idx] + f(idx+1, transNo+1, price);
        int notBuy = 0 + f(idx+1, transNo, price);
        return max(buyy, notBuy);
    } 
    else { //sell
        int sell = price[idx] + f(idx+1, transNo+1, price);
        int notSell = 0 + f(idx+1, transNo, price);
        return max(sell, notSell);
    }
}

int memo(int idx, int transNo, vector<int>& price, vector<vector<int>> &dp) {
    if(idx == price.size() || transNo == 4) { // base case
        return 0;
    }
    if(dp[idx][transNo] != -1) return dp[idx][transNo];
    
    if(transNo % 2 == 0 ) { // buy
        int buyy = -price[idx] + memo(idx+1, transNo+1, price, dp);
        int notBuy = 0 + memo(idx+1, transNo, price, dp);
        return dp[idx][transNo] = max(buyy, notBuy);
    } 
    else { //sell
        int sell = price[idx] + memo(idx+1, transNo+1, price, dp);
        int notSell = 0 + memo(idx+1, transNo, price, dp);
        return dp[idx][transNo] = max(sell, notSell);
    }
}

int maxProfit(vector<int>&price){
    //Write your code here..
    // 0 1 2 3 => transaction no.
    // B S B S (even no => buy, odd no => sell)

    // Recursion
    // return f(0, 0, price);
    
    // Memo
    int n = price.size();
    // vector<vector<int>> dp(n, vector<int>(4,-1));
    // return memo(0, 0, price, dp);
    
    // Tabulation
    vector<vector<int>> dp(n+1, vector<int>(5,0));
    for(int t=0; t<=4; t++) {
        dp[n][t] = 0;
    }
    for(int idx=0; idx<=n; idx++) {
        dp[idx][4] = 0;
    }
    
    for(int idx=n-1; idx>=0; idx--) {
        for(int transNo=3; transNo>=0; transNo--) {
            int profit = 0;
            if(transNo % 2 == 0 ) { // buy
                int buyy = -price[idx] + memo(idx+1, transNo+1, price, dp);
                int notBuy = 0 + memo(idx+1, transNo, price, dp);
                profit = max(buyy, notBuy);
            } 
            else { //sell
                int sell = price[idx] + memo(idx+1, transNo+1, price, dp);
                int notSell = 0 + memo(idx+1, transNo, price, dp);
                profit = max(sell, notSell);
            } 
            dp[idx][transNo] = profit;
        }
    }
    
    return dp[0][0];

    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends