class Solution {
    int houseRobber(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        dp[0] = arr[0];
        
        for(int idx=1; idx<n; idx++) {
            int pick = arr[idx];
            if(idx >= 2) pick += dp[idx-2];
            int notPick = 0 + dp[idx-1];
            
            dp[idx] = max(pick, notPick);
        }
        
        return dp[n-1];
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(nums[i], maxi);
        }
        vector<int> freq(maxi+1,0); // tells how many points you can collect by deleting an element by calculating nums[i]*freq
        for(int i=0; i<n; i++) {
            freq[nums[i]] += nums[i];
        }
        
        // now its the same as house robber 1
        return houseRobber(freq);
    }
};