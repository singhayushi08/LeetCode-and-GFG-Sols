class Solution {
    int f(int idx, int k,  vector<int> &nums, vector<vector<int>> &dp) {
        if(idx == 0) {
            if(nums[0] == 0 && k == 0) return 2;
            if(k == 0 || nums[0] == k) return 1;
            else return 0;
        }
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int notPick = f(idx-1, k, nums, dp);
        int pick = 0;
        if(nums[idx] <= k) 
            pick = f(idx-1, k-nums[idx], nums, dp);
            
        return dp[idx][k] = pick + notPick;
    }
    
    int countSubsetsWithSumK(vector<int> &nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        return f(n-1, k, nums, dp);  
    }
    
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // ques is same as divide set into two subsets s1 and s2 such that s1-s2 = target
        int totalSum = 0;
        for(auto i: nums) totalSum += i;
        if((totalSum - target) < 0 || (totalSum - target)%2 != 0) return 0;
        int k = (totalSum - target)/2;
        return countSubsetsWithSumK(nums, k);
    }
};