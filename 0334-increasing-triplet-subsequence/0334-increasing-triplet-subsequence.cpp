class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // brute force, TC: O(n^3), SC: O(1)
        // int n = nums.size();
        // for(int i=0; i<n-2; i++) {
        //     for(int j=i+1; j<n-1; j++) {
        //         for(int k=j+1; k<n; k++) {
        //             if(nums[j] > nums[i] && nums[k] > nums[j]) {
        //                 return true;
        //             }
        //         }
        //     }
        // }
        // return false;
        
        
        // Using Longest Increasing Subsequence(LIS), TC: O(n^2), SC: O(n)
//         int n = nums.size();
//         vector<int> dp(n, 1);
        
//         for(int i=0; i<n; i++) {
//             for(int prev=0; prev<i; prev++) {
//                 if(nums[prev] < nums[i] && dp[i] < 1 + dp[prev]) {
//                     dp[i] = 1 + dp[prev];
//                 }        
//             }
//             if(dp[i] == 3) return true;
//         }
        
//         return false;
        
        // Optimised version of LIS, TC: O(n), SC: O(n)
        int n = nums.size();
        vector<int> temp; // stores LIS
        temp.push_back(nums[0]);
        
        for(int i=1; i<n; i++) {
            if(nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        
        if(temp.size() >= 3) return true;
        return false;
        
    }
};