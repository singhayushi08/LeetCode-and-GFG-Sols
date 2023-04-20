class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // Using DP, variation of Longest increasing subsequence, TC: O(n), SC: O(n)
        // int n = nums.size();
        // if(n == 1) return 1;
        
//         vector<int> dp(n, 1);
//         int maxi = 1;
        
//         for(int i=1; i<n; i++) {
//             if(nums[i] > nums[i-1] && dp[i] < 1 + dp[i-1]) {
//                 dp[i] = 1 + dp[i-1];
//             }
//             maxi = max(maxi, dp[i]);
//         }
        
        
//         return maxi;
        
        // Using kadane's algo, TC: O(n), SC: O(1)
        int n = nums.size();
        if(n == 1) return 1;
        int currLen = 1, maxLen = 1;
        
        for(int i=1; i<n; i++) {
           if(nums[i] > nums[i-1]) {
                currLen++;
            }
            else {
                maxLen = max(maxLen, currLen);
                currLen = 1; // reset
            } 
        }
        
        maxLen = max(maxLen, currLen);
        return maxLen;
    }
};