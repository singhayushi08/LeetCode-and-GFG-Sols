class Solution {
    int f(int i, vector<int>& arr, int n, int k, vector<int>& dp) {
        if(i == n) return 0; // base case
        if(dp[i] != -1) return dp[i];
        
        int maxElement = INT_MIN, len = 0;
        int maxSum = INT_MIN;
        for(int j=i; j<min(n,i+k); j++) { // in case i+k goes out of bound, hence min(n, i+k)
            len++;
            maxElement = max(arr[j], maxElement);
            int sum = len * maxElement + f(j+1, arr, n, k, dp);
            maxSum = max(sum, maxSum);  
        }
        
        return dp[i] = maxSum;
    }
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, arr, n, k, dp);
    }
};