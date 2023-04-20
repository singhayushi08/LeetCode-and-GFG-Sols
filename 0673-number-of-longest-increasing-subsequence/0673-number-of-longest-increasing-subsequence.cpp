class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // TC: O(n^2), SC: O(2n)
        int n = nums.size(); 
        if(n == 1) return 1;
        
        int maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) { // new LIS
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[prev] < nums[i] && dp[i] == 1 + dp[prev]) { // another LIS having same length found, so increase count
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        
        // add count of all subsequences having length as maxi
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxi) ans += cnt[i];
        }
        
        return ans;
    }
};