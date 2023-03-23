class Solution {
    bool f(int idx, int target, vector<int>& arr) {
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        bool notPick = f(idx-1, target, arr);
        bool pick = false;
        if(arr[idx] <= target) {
            pick = f(idx-1, target-arr[idx], arr);
        }
        
        return pick | notPick;
    }
    
    bool memo(int idx, int target, vector<int>& arr, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool notPick = memo(idx-1, target, arr, dp);
        bool pick = false;
        if(arr[idx] <= target) {
            pick = memo(idx-1, target-arr[idx], arr, dp);
        }
        
        return dp[idx][target] = pick | notPick;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int i=0; i<n; i++) {
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0) return false; //if total sum is odd, it cannot be divided into 2 subsets
        int k = total_sum/2;
        
        // now just call subset sum equal to k, if we find 1 subset with k = total_sum/2 then obvio the other subset would be having the sum as total_sum/2
        
        // Recursion, TC: O(2^n), SC: O(n)
        // return f(n-1, k, nums);
        
        // Memoization, TC: O(n*k), SC: O(n*k + n) for 2d array and aux stack space
        // vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // return memo(n-1, k, nums, dp);
        
        // Tabulation, TC: (n*k), SC: O(n*k)
        vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
        for(int i=0; i<n; i++) { //if target is 0
            dp[i][0] = true;
        }
        if(nums[0] <= k) dp[0][nums[0]] = true; 
        
        for(int idx=1; idx<n; idx++) {
            for(int target=1; target<=k; target++) {
                bool notPick = dp[idx-1][target];
                bool pick = false;
                if(nums[idx] <= target) {
                    pick = dp[idx-1][target-nums[idx]];
                }

                dp[idx][target] = pick | notPick;
            }
        }
        
        return dp[n-1][k];
        

        
    }
};