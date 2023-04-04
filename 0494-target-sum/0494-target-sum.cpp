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
        // Memo
        // int n = nums.size();
        // // vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // return f(n-1, k, nums, dp);
        
        // Tabulation
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1, 0));
        if(nums[0] == 0) {
            dp[0][0] = 2;
        } else {
            dp[0][0] = 1;
        }
        if(nums[0] <= k && nums[0] != 0) dp[0][nums[0]] = 1;
        
        for(int idx = 1; idx<n; idx++) {
            for(int target=0; target<=k; target++) {
                int notPick = dp[idx-1][target]; 
                int pick = 0;
                if(nums[idx] <= target) 
                    pick = dp[idx-1][target-nums[idx]];

                dp[idx][target] = pick + notPick;
            }
        }
        
        return dp[n-1][k];
    }
    
    int f(int idx, int currSum, int target, vector<int> &nums) {
        if(idx == 0) {
            if((currSum + nums[idx]) == target || (currSum - nums[idx]) == target) return 1;
            else return 0;
        }
        
        int pos = f(idx-1, currSum + nums[idx], target, nums);
        int neg = f(idx-1, currSum - nums[idx], target, nums);
        
        return pos + neg;
    }
    
     int memo(int idx, int target, vector<int> &nums, map<pair<int,int>,int> &dp) {
        if(idx == 0) {
            if(nums[0] == 0 && target == 0) return 2;
            else return nums[0] == abs(target);
        }
         
        if(dp.find(make_pair(idx,target)) != dp.end()) return dp[make_pair(idx,target)];
        
        int pos = memo(idx-1, target + nums[idx], nums, dp);
        int neg = memo(idx-1, target - nums[idx], nums, dp);
        
        return dp[make_pair(idx,target)] = pos + neg;
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // ques is same as divide set into two subsets s1 and s2 such that s1-s2 = target
        // int totalSum = 0;
        // for(auto i: nums) totalSum += i;
        // if((totalSum - target) < 0 || (totalSum - target)%2 != 0) return 0;
        // int k = (totalSum - target)/2;
        // return countSubsetsWithSumK(nums, k);
        
        // Rec
        int n = nums.size();
        // return f(n-1, 0, target, nums);
        
        // Memo
        map<pair<int,int>,int> dp; //coz -ve values also, cannot use an array
        return memo(n-1, target, nums, dp);
        
    }
};