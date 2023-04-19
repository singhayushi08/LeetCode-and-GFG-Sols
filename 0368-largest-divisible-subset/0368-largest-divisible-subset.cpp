class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Just like print longest Increasing Subsequence 
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());
        
        vector<int> dp(n,1), hash(n);
        
        int maxi = 1, lastIndex = 0;
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int prev = 0; prev<i; prev++) {
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i]; // length of largest divisible subset
                lastIndex = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};